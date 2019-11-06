#include "TSP.h"

#include <iostream>
#include <string>
#include <math.h>
#include <utility>
using namespace std;



TSP::TSP()
{
	
}

void TSP::BF(vector<vector<float>> a ,int x)
{
	vector<pair<string,float>>path;
	vector<string>per_path;
	string my_path;
	int total_path = 1;
	bool status;
	for (int i = 1; i < x; i++)
		total_path *= i;
	// create the first path
	for (int j = 1; j <= x; j++) {
		my_path += to_string(j);
	}
	//push the first path
	float dist = 0.0;
	dist = distance(a, my_path);
	path.push_back(make_pair(my_path,dist));
	int counter = 0;
	
	for (int k = 0; k < total_path; k++) {
		for (int i = 1; i < x - 1; i++) {
			swap(my_path[i], my_path[i + 1]);
			for (int j = 1; j < x - 1; j++) {
				swap(my_path[i + 1], my_path[j + 1]);
				status = check(path, my_path);
				if (status == false) {
					counter++;
					//calculate the distance 
					dist = distance(a, my_path);
					path.push_back(make_pair(my_path, dist));
				}
			}
		}
	}
	for (int i = 0; i < path.size(); i++) {
		cout << "The path is: " << path[i].first << " ";
		cout << "and the size is: " << path[i].second << endl;
	}
	cout << "total path is: " << counter + 1 << endl;
}

vector<string> TSP::permutation(string path, int start, int end)
{  
	int i;
	vector<string>p;
	if (start == end) {
		cout << "The path is: " << path << endl;
		p.push_back(path);
		//return path;
	}
	else
	{
		for (i = start; i< path.length(); i++)
		{
			swap(path[start], path[i]);
			permutation(path, i+1, end);
			swap(path[start], path[i]);
		}
	}
	return p;
}

void TSP::DP(vector<vector<float>> a, int x)
{


}



float TSP::distance(vector<vector<float>> graph,string path)
{
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

bool TSP::check(vector<pair<string,float>>path,string y)
{ 
	for (int i = 0; i < path.size(); i++) {
		if (y == path[i].first)
			return true;
	}
	return false;
}


