#include "TSP.h"
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <sstream>
using namespace std;



TSP::TSP(int x)
{
	size = x;
	arr = new int[(1 << size)]();
	path = new int[x];
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
		cout << my_path[j];
	}
	cout << "1" << " and in BF the cost is: " << smallerDist;
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
			graph[j][i] = dist;
		}
	}

	vector<vector<int>> dp(graph.size());
	for (auto& n : dp)
		n = vector<int>(((1 << graph.size())-1), -1);

	cout<<" and the cost in DP is: "<< findCost(graph, 0, 1, dp)<<endl;
	//cout << "The path is: ";

	//cout << "The size is: " << size << endl;
	/*vector<int> dp_path;
	int num = (1 << size) - 1;
	cout << "num is: " << num << endl;
	for (int i = 0; i < size;i++) {
		
		int number = arr[num];
		cout << "number is:" << number << endl;
		dp_path.push_back(number);
		num = num - (1 << number);
		cout << "num here is:" << num << endl;
	}

	for (int j = 0; j < dp_path.size(); j++) {
		cout << dp_path[j]<<"->";
	}
	cout << endl;*/
	
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

float TSP::findCost(vector<vector<float>> &graph,int pos,int mask,vector<vector<int>> &dp)
{   
	
	//cout << "mask is: " << mask << endl;
	//int Binary_s = 0;
	//Binary_s = BinaryConvert(mask);
	//path[pos] = Binary_s;
	//cout << "pos is:" << pos << endl;
	
	if (mask == ((1 << graph.size()) - 1)) {
		
		return graph[pos][0];
	}
	if (dp[pos][mask] != -1) {
		
		int temp =dp[pos][mask];
		temp = temp / 1.0;
		
		return temp;
	}
	float ans = 9999999.0;
	for (int city = 0; city < graph.size(); ++city) {
		//cout << "city is: " << city << endl;
		if ((mask & (1 << city)) == 0) {
			
			float newAns = graph[pos][city] + findCost(graph, city, mask | (1 << city), dp);
			
			/*if ((newAns < ans) || (arr[mask] == 0)) {
				arr[mask] = pos;
				if ((mask + (1 << city)) == (1 << graph.size() - 1)) {
					arr[mask | (1 << city)] = city;
				}
			}*/

			ans = min(ans, newAns);
			
			//Binary_s = BinaryConvert(mask);
			//path[city] = Binary_s;
		}
	}
		
	//Binary_s = BinaryConvert(mask);
	//path[pos] = Binary_s;
	int temp2 = dp[pos][mask] = ans;
	temp2 = temp2 / 1.0;
	return temp2;
}

double TSP::Tabu(std::vector<std::vector<float>> graph, std::vector<int> path)
{
	// generate a random path
	srand(time(NULL));
	vector<int>random_path;// select as best
	random_path.push_back(1);
	vector<int>visited;
	for (int i = 0; i < path.size(); i++) {
		visited.push_back(0);
	}
	visited[0] = 1;// mark node 1 visited
	
	while (random_path.size() != path.size()) {
		int p = rand() % path.size() + 1;
		//cout << "p is: " << p << endl;
		random_path.push_back(p);
		
		if (visited[p-1] != 0) {
			random_path.pop_back();
		}
		else {
			visited[p-1] = 1;
		}
	}
	/*cout << "The path is: ";
	for (int j = 0; j < random_path.size(); j++) {
		cout << random_path[j] << " ";
	}
	cout << endl;*/ 
    // ok 
	vector<int>my_neighbour;
	
	for (int i = 1; i < random_path.size() - 1; i++) {
		my_neighbour = findNeighbour(random_path,i,i+1);
		float Tabu_cost = distance(graph, my_neighbour);
		cout << "the cost is: " << Tabu_cost << endl;
	}
	
	
	
		
	
	return 0.0;
}

vector<int> TSP::findNeighbour(std::vector<int> best_path,int p1,int p2)
{
	// right now the size of tabu list is 20
	// current swap with next when i++
	swap(best_path[p1], best_path[p2]);
	best_path.push_back(1); // returning back to start point
	cout << "The neighbour path is: ";
	for (int i = 0; i < best_path.size(); i++) {
		
		cout << best_path[i] ;
	}
	cout << endl;
	return best_path;
}




