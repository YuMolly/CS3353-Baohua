#include "TSP.h"

#include <iostream>
#include <string>
using namespace std;



TSP::TSP()
{
	
}

void TSP::BF(vector<vector<float>> a ,int x)
{
	vector<string> path;
	string my_path;
	int total_path = 1;
	bool status;
	for (int i = 1; i < x; i++)
		total_path *= i;
	//cout << "The total_path is: " << total_path << endl;
	// create the first path
	for (int j = 1; j <= x; j++) {
		my_path += to_string(j);
	}
	//push the first path
	path.push_back(my_path);
	int counter = 0;
	cout << "my_path is: " << my_path << endl;
	for (int k = 0; k < total_path; k++) {
		for (int i = 1; i < x-1; i++) {
			swap(my_path[i], my_path[i + 1]);
			for (int j = 1; j < x -1; j++) {
				swap(my_path[i+1], my_path[j + 1]);
				//swap(my_path[j + 1], my_path[j]);
				
				

				//cout << "The new path is " << my_path << endl;
				status = check(path, my_path);
				if (status == false) {
					counter++;
					cout << "My new path is: " << my_path << endl;
					path.push_back(my_path);
				}
			}
		}
	}
	cout << "total path is: " << counter +1<< endl;
	for (int i = 0; i < path.size(); i++) {
		//cout << "The path is: " << path[i] << endl;
	}
}

void TSP::DP(vector<vector<float>> a, int x)
{


}


float TSP::distance(vector<int> path)
{
	
	return 0.0;
}

bool TSP::check(vector<string>path,string y)
{ 
	for (int i = 0; i < path.size(); i++) {
		if (y == path[i])
			return true;
	}
	return false;
}


