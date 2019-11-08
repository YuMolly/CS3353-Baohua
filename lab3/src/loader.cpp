#include "loader.h"
#include "TSP.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

loader::loader()
{
	Gsize = 0;
}
void loader::load()
{   
	cout << "The load function is running\n";
	ifstream file;
	file.open("positions.txt");
	string num,num1;
	string leave;
	int x, y, z;
	int pos,pos1,pos2;
	int node;
	if (!file)
		cout << "The file fail to open" << endl;
	else
		cout << "The file can open successfully!" << endl;
	while (file) {
		while (getline(file, num)) {
			pos = num.find(',');
			num1= num.substr(0, pos);
			node = stoi(num1);
			leave = num.substr(pos + 1, num.length() - pos + 1);
			pos1 = leave.find(',');
			x = stoi(leave.substr(0, pos1));
			leave = leave.substr(pos1 + 1, leave.length() - pos1 + 1);
			pos2 = leave.find(',');
			y = stoi(leave.substr(0, pos2));
			z = stoi(leave.substr(pos2 + 1));
			for (int i = graph.size(); i < node; i++) {
				vector<float> temp;
				graph.push_back(temp);
			}
			for (int j = graph[node - 1].size(); j < 3; j++) {
				graph[node - 1].push_back(0);
			}
			//cout << "node is " << node;
			graph[node - 1][0] = x;
			graph[node - 1][1] = y;
			graph[node - 1][2] = z;
			//cout << "position is (" << x << "," << y << "," << z << ")" << endl;
			Gsize++;
		}
		
		//cout << "The size is: " << Gsize << endl;
	}
	//cout << "The Gsize is: " << Gsize << endl;
	file.close();
}

void loader::print()
{
	cout << "The use time of navie brute froce method is: " << time_span <<"s"<< " in "<< "7" <<" node."<<endl;
	//chage 7 into Gsize
}

void loader::execute()
{
	TSP tsp;
	time_span = tsp.BF(graph,7);
	//tsp.DP(graph,Gsize);

}

vector<vector<float>> loader::getGraph()
{
	return graph;
}

int loader::getGsize()
{
	return Gsize;
}






