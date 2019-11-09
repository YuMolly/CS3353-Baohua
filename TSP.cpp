#include "TSP.h"
#include <math.h>
#include <algorithm>

using namespace std;



TSP::TSP()
{
	cost = 0.0;
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
	string my_path;
	float dist = 0.0;
	if (start == end-1) {
		
		
		dist = distance(a, path);
		//cout << "dist: " << dist << endl;
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
	float di = 0.0;
	float dist = 0.0;
	int x, y, z;
	int x1, y1, z1;
	int location;
	int location2;
	for (int j = 0; j < path.size()-1; j++) {
		location = path[j];
		location2 = path[j + 1];
		//cout << "location is " << location << endl;
		x = graph[location-1][0];
		y = graph[location-1][1];
		z = graph[location-1][2];
		//cout << "x is :" << x << " y is:" << y << " z is:" << z << endl;
		x1 = graph[location2-1][0];
		y1 = graph[location2-1][1];
		z1= graph[location2-1][2];
		//cout << "x1 is :" << x1 << " y1 is:" << y1 << " z1 is:" << z1 << endl;
		//di = pow((x1 - x), 2) + pow((y1 - y), 2) + pow((z1 - z), 2);
		//cout << "di is " << di << endl;
		dist += pow( (x1 - x),2) + pow( (y1- y),2) + pow((z1 - z),2);
		//cout << "The BFcost is " << dist << endl;
	}
	// calculate the cost back to 1
	//cout << "dist is " << dist << endl;
	int last = path[path.size() - 1];
	x= graph[last-1][0];
	y = graph[last-1][1];
	z = graph[last-1][2];
	//cout << "x is :" << x << " y is:" << y << " z is:" << z << endl;
	x1 = graph[0][0];
	y1 = graph[0][1];
	z1 = graph[0][2];
	//out << "x1 is :" << x1 << " y1 is:" << y1 << " z1 is:" << z1 << endl;
	//di = pow((x1 - x), 2) + pow((y1 - y), 2) + pow((z1 - z), 2);
	//cout << "di is " << di << endl;
	dist += pow((x1 - x), 2) + pow((y1 - y), 2) + pow((z1 - z), 2);
	//cout << "The BFcost is " << dist << endl;
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
		//cout << "index_second" << p1[index].second << endl;
		//cout << "i_second" << p1[i].second << endl;
	}
	float smallerDist = p1[index].second;
	string my_path = p1[index].first;
	cout << "The path is: ";
	for (int j = 0; j < my_path.length(); j++) {
		cout << my_path[j] << "->";
	}
	cout <<"1"<< " and the cost is: " << smallerDist << endl;
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
	for (int i = 0; i < graph.size(); i++) {
		x = a[i][0];
		y = a[i][1];
		z = a[i][2];
		//cout << "x is :" << x << " y is:" << y << " z is:" << z << endl;
		for (int j = 0; j < graph.size(); j++) {
			x1 = a[j][0];
			y1 = a[j][1];
			z1 = a[j][2];
			//cout << "x1 is :" << x1 << " y1 is:" << y1 << " z1 is:" << z1 << endl;
			dist = pow((x1 - x), 2) + pow((y1 - y), 2) + pow((z1 - z), 2);
			//cout << "dist is " << dist << endl;
			graph[i][j] = dist;
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
	//float cost = 0.0;
	visited[node] = 1;
	//DP_path.push_back(node + 1);
	//cout << "The path is: " << node+1<<"->";
	child_node = leave(graph,node,visited,&cost);
	
	if (child_node == 999) {
		cout << "The cost before child_node = 999 " << cost << endl;
		//cout << "." << endl;
		child_node = 0;
		cout << "node is " << node << endl;
		cost += graph[node][child_node];
		//cost = 0
		cout << "The cost after child_node = 999 " << cost << endl;
		return;
	}
	cout << "The DPcost is: " << cost << endl;
	findCost(graph, child_node, visited);
	DP_cost.push_back(cost);
	//cout << "The cost is: " << cost << endl;
}

int TSP::leave(vector<vector<float>> graph,int node, vector<int> visited,float *cost)
{   
	//float cost = 0;
	cout << "my node here is " << node+1 << endl;
	DP_path.push_back(node + 1);
	float min = 999;
	float min_t = 0;
	int child_node = 999;
	for (int i = 0; i < visited.size(); i++) {
		cout << "graph at node" << node+1 << " and i:" << i<<" and the cost is:" << graph[node][i] << endl;
		cout << "visited?" << visited[i] << endl;
		if ((graph[node][i] != 0) && (visited[i] == 0)) {
			if (graph[node][i] + graph[i][node] < min) {
				min = graph[i][0] + graph[node][i];
				cout << "min here:" << min << endl;
				min_t = graph[node][i];
				cout << "min_t here:" << min_t << endl;
				child_node = i;
				cout << "child_node here is " << child_node << endl;
			}
		}
	}
	if (min != 999) {
		//cout << "The min_t is: " << min_t << endl;
		*cost += min_t;
		cout << "cost here is " << *cost << endl;
	}
	
	return child_node;
}

void TSP::printDP()
{
	float cost = 0.0;
	cout << "The path is: ";
	for (int i = 0; i < DP_path.size(); i++) {
		cout << DP_path[i]<<"->";
	}


	cout << "1 ";
	cout << "The total cost is: " << DP_cost[0] << endl;
}


