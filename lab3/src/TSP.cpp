#include "TSP.h"
#include <math.h>
#include <algorithm>

using namespace std;



TSP::TSP()
{
	
}

double TSP::BF(vector<vector<float>> a,int x)
{
	// BF method
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	string my_path;
	string shorter_path;
	int total_path = 1;
	for (int i = 1; i < x; i++)
		total_path *= i;
	cout << "The total paths: " << total_path << endl;
	// create the first path
	for (int j = 2; j <= x; j++) {
		my_path += to_string(j);
	} 
	permutation(a,my_path, 0, my_path.length());
	checkBF();

	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

void TSP::permutation(vector<vector<float>>a,string path, int start, int end)
{  
	// find all possible path
	cout << ".";
	if (start == end-1) {
		float dist = 0.0;
		path = "1" + path;
		dist = distance(a, path);
		p1.push_back(make_pair(path,dist));
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

float TSP::distance(vector<vector<float>> graph,string path)
{
	// find the nodes distance
	int path_s = 0;
	vector<int> path_t;
	// convert char to int
	for (int i = 0; i < path.length(); i++) {
		path_s = path[i] - '0';
		path_t.push_back(path_s);
	}

	float dist = 0.0;
	int x, y, z;
	int x1, y1, z1;
	int location;
	for (int j = 0; j < path_t.size()-1; j++) {
		location = path_t[j];
		x = graph[location][0];
		y = graph[location][1];
		z = graph[location][2];
		x1 = graph[location + 1][0];
		y1 = graph[location + 1][1];
		z1= graph[location + 1][2];
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

void TSP::DP(vector<vector<float>> a, int x)
{


}


