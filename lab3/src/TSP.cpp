#include "TSP.h"
#include <math.h>
#include <algorithm>

using namespace std;



TSP::TSP()
{
	
}

double TSP::BF(vector<vector<float>> a,vector<int> my_path)
{
	// BF method
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	
	
	permutation(a,my_path, 1, my_path.size());
	checkBF();

	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

void TSP::permutation(vector<vector<float>>a,vector<int> path, int start, int end)
{  
	// find all possible path
	//cout << ".";
	//int num = 0;
	//string p;
	string my_path;
	if (start == end) {
		float dist = 0.0;
		
		dist = distance(a, path);
		for (int i = 0; i < path.size(); i++) {
			my_path += to_string(path[i]);
			
		}
		//cout << "my_path is: " << my_path << endl;
		p1.push_back(make_pair(my_path, dist));
		return;
	}
	else
	{
		for (int i = start; i< end; i++)
		{
			swap(path[start], path[i]);
			permutation(a,path, start+1, end);
			swap(path[start], path[i]);
		}
	}
	
}

float TSP::distance(vector<vector<float>> graph,vector<int> path)
{
	// find the nodes distance
	//int path_s = 0;
	//vector<int> path_t;
	// convert char to int

	float dist = 0.0;
	int x, y, z;
	int x1, y1, z1;
	//int location;
	for (int j = 0; j < path.size()-1; j++) {
		
		x = graph[j][0];
		y = graph[j][1];
		z = graph[j][2];
		x1 = graph[j+ 1][0];
		y1 = graph[j + 1][1];
		z1= graph[j+ 1][2];
		dist += pow(2, (x1 - x)) + pow(2, (y1- y)) + pow(2, (z1 - z));
		
	}
	
	return dist;
}

void TSP::checkBF()
{   
	//find the smaller path 
	int index = 0;
	for (int i = 1; i < p1.size(); i++) {
		if (p1[index].second > p1[i].second) {
			index = i;
		}
	}
	int smallerDist = p1[index].second;
	cout << "The path is: " << p1[index].first << " and the size is: " << p1[index].second << endl;
}

double TSP::DP(vector<vector<float>> a, vector<int> my_path)
{
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	vector<vector<float>>graph;
	for (int i = graph.size(); i < my_path.size(); i++) {
		vector<float>temp;
		graph.push_back(temp);
		for (int j = 0; j < my_path.size(); j++) {
			graph[i].push_back(0);
		}
	}
	float dist;
	int x, y, z;
	int x1, y1, z1;
	for (int i = 0; i < graph.size() - 1; i++) {
		x = a[i][0];
		y = a[i][1];
		z = a[i][2];
		x1 = a[i + 1][0];
		y1 = a[i + 1][1];
		z1 = a[i + 1][2];
		dist = pow(2, (x1 - x)) + pow(2, (y1 - y)) + pow(2, (z1 - z));
		//graph[i][i] = 0;
		if (i + 1 < graph.size()) {
			graph[i][i + 1] = dist;
		}
	}
	vector<int> visited;
	for (int i = 0; i < my_path.size(); i++) {
		visited.push_back(0);
	}
	// start at the 1 so change node 1 into visited
	findCost(graph,0, visited);
	printDP();
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

void TSP::findCost(vector<vector<float>> graph,int node,vector<int> visited)
{   
	int child_node;
	float cost = 0.0;
	visited[node] = 1;
	DP_path.push_back(node + 1);
	//cout << "The path is: " << node+1<<"->";
	child_node = leave(graph,node,visited,&cost);
	if (child_node == 999) {
		child_node = 0;
		cout << child_node + 1;
		cost += graph[node][child_node];
		return;
	}
	findCost(graph, child_node, visited);
	DP_cost.push_back(cost);
	//cout << "The cost is: " << cost << endl;
}

int TSP::leave(vector<vector<float>> graph,int node, vector<int> visited,float *cost)
{   
	//float cost = 0;
	float min = 999;
	float min_t = 0;
	int child_node = 999;
	for (int i = 0; i < visited.size(); i++) {
		if ((graph[node][i] != 0) && (visited[i] == 0)) {
			if (graph[node][i] + graph[i][node] < min) {
				min = graph[i][0] + graph[node][i];
				min_t = graph[node][i];
				child_node = i;
			}
		}
	}
	if (min != 999) {
		*cost += min_t;
	}
	return child_node;
}

void TSP::printDP()
{
	cout << "The path is: ";
	for (int i = 0; i < DP_path.size(); i++) {
		cout << DP_path[i]<<"->";
	}
	cout << "1 ";
	cout << "The total cost is: " << DP_cost[0] << endl;
}


