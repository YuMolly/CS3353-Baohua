#include "TSP.h"
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
using namespace std;



TSP::TSP(int x)
{
	size = x;
	
	arr = new int[(1 << size)]();
	path = new int[x];
	cost = 0.0;
	vector<int>temp;
	for (int i = 0; i < x+1; i++) {
		temp.push_back(0);
		
	}
	// for tabu
	for (int i = 0; i < 1500; i++) {
		float n = 0.0;
		tabu_list.push_back(make_pair(temp,n));
	}
	// intinalize a GA_beast only record one best solution
	for (int i = 0; i < 1; i++) {
		float b = 100000000.0;
		GA_best.push_back(make_pair(temp, b));
	}
	
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
	
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

float TSP::findCost(vector<vector<float>> &graph,int pos,int mask,vector<vector<int>> &dp)
{   
	
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
			ans = min(ans, newAns);
		}
	}
		
	//Binary_s = BinaryConvert(mask);
	//path[pos] = Binary_s;
	int temp2 = dp[pos][mask] = ans;
	temp2 = temp2 / 1.0;
	return temp2;
}

double TSP::Tabu(vector<vector<float>> graph, vector<int> path)
{
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	vector<int>random_path;
	int a = 0;
	int tabu_size = 0;
	int exist;
	//cout << "tabu_list size: " << tabu_list.size();
	while(a<25000) {
		a++;
		random_path = path_generator(path);
		
		float Tabu_cost = 0.0;
		
		exist = checkTabuExist(random_path);
		Tabu_cost = distance(graph, random_path);
		if ((tabu_size < tabu_list.size())&&(exist!=1)) {
			tabu_list[tabu_size] = make_pair(random_path, Tabu_cost);
			tabu_size++;
			//cout << "here1";
		}
		else if ((tabu_size >= tabu_list.size()) && (exist != 1)) {
			tabu_size = 0;
			tabu_list[tabu_size] = make_pair(random_path, Tabu_cost);
			tabu_size++;
			//cout << "here2";
		}

		int steps = 0;
		
		
		while (steps < 30000) {

			
			int counter = 0;
			float bigger_min = 0.0;
			float the_min = 100000000000.0;
			vector<float>cost_sort;
			vector<int>my_neighbour;
			vector<int>my_path;
			vector<pair<vector<int>, float>> neighbour_list;
			bool not_option = true;
			
			// avoid swap 1
			for (int i = 1; i < random_path.size() - 2; i++) {

				my_neighbour = findNeighbour(random_path, i);// get each possible neighbour paths

				Tabu_cost = distance(graph, my_neighbour);//get the total cost of the neighbour
				cost_sort.push_back(Tabu_cost);// store for sorting the cost

				//store all neighbours
				neighbour_list.push_back(make_pair(my_neighbour, Tabu_cost));
				sort(cost_sort.begin(), cost_sort.end());

				if (the_min > Tabu_cost) {
					the_min = Tabu_cost;
				}

			}

			//std::cout << "the min is: " << the_min << endl;

			for (int h = 0; h < neighbour_list.size(); h++) {
				if (neighbour_list[h].second == the_min) {
					my_path = neighbour_list[h].first;
				}
			}


			//store not exist min cost path into Tabu list

			exist = checkTabuExist(my_path);
			if (exist == 0) {
				if (tabu_size < tabu_list.size()) {
					tabu_list[tabu_size] = make_pair(my_path, the_min);
					tabu_size++;
					random_path = my_path;
					not_option = false;
					steps++;
					//cout << "here4";
				}
				else {
					tabu_size = 0;
					tabu_list[tabu_size] = make_pair(my_path, the_min);
					tabu_size++;
					random_path = my_path;
					not_option = false;
					steps++;
					//cout << "here5";
				}
				
			}


			// if the_min already in the Tabu_list
			else if (exist == 1) {
				
				int c = 1;
				while (c < cost_sort.size()) {
					bigger_min = cost_sort[c];
					c++;
					for (int j = 0; j < neighbour_list.size(); j++) {
						exist = checkTabuExist(neighbour_list[j].first);
						
						if ((neighbour_list[j].second == bigger_min) && (exist != 1)) {
							the_min = bigger_min;
							random_path = neighbour_list[j].first;
							//std::cout << "smallest occupied" << endl;
							if (tabu_size < tabu_list.size()) {
								tabu_list[tabu_size] = make_pair(random_path, the_min);
								tabu_size++;
								not_option = false;
								steps++;
								//cout << "here6";
							}
							else {
								tabu_size = 0;
								tabu_list[tabu_size] = make_pair(random_path, the_min);
								tabu_size++;
								not_option = false;
								steps++;
								//cout << "here7";
							}

							break;
						}
						break;

					}
					break;
				}
				break;
			}

			// all the path alreay exist in tabu_list find the smallest cost in neighbour
			else if (not_option == true) {
				for (int j = 0; j < neighbour_list.size(); j++) {
					if (neighbour_list[j].second == cost_sort[0]) {
						random_path = neighbour_list[j].first;
						steps++;
						break;

					}
				}
			}

		}
	}

	float final_min = 10000000000;
	vector<int> f;
	// find the final answer
	for (int j = 0; j < tabu_list.size(); j++) {
		
		float num = tabu_list[j].second;
	
		if((num<final_min)&&(num != 0)){
			final_min = num;
		}
		if (tabu_list[j].second == final_min) {
			f = tabu_list[j].first;
		}
	}
	std::cout << "The smallest path in Tabu search is: ";
	for (int k = 0; k < f.size(); k++) {
		std::cout << f[k] << " ";
	}
	std::cout << "and cost is: " << final_min << endl;

	//std::cout << "the tabu_list size is: " << tabu_list.size() << endl;
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

vector<int> TSP::findNeighbour(std::vector<int> best_path,int p1)
{
	// current swap with next when i++
	//swap(best_path[p1], best_path[p2]);

	// current swap with the pos = number in path into the new pos
	int temp = best_path[p1];
	if (temp < best_path.size() - 1) {
		swap(best_path[p1], best_path[temp]);
	}
	
	return best_path;
}

int TSP::checkTabuExist(vector<int> path)
{
	for (int i = 0; i < tabu_list.size(); i++) {
		if (path == tabu_list[i].first) {
			return 1;
		}
	}
	return 0;
}

double TSP::GA(vector<vector<float>> graph, vector<int> path)
{
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	int population_size = 0;
	int generations = 0;
	float GA_cost = 0.0;
	float the_min_GA = 1000000000.0;
	vector<int> random_child;
	vector < pair<vector<int>, float> >parents;
	

	// generate first parents
	while (population_size < 2000000) {
		
		random_child = path_generator(path);
		GA_cost = distance(graph, random_child);
		//cout << "The GA_cost is: " << GA_cost << endl;
		parents.push_back(make_pair(random_child, GA_cost));
		population_size++;
	}
	
	vector<int> father;
	vector<int> mother;
	while (generations < 1500000) {
		// fintiness guid: choose first two smaller cost path as parents
		float second_min = 100000000.0;
		
		for (int j = 0; j < parents.size(); j++) {
			if (parents[j].second < the_min_GA) {
				the_min_GA = parents[j].second;
				father = parents[j].first;
				
			}
			else if ((parents[j].second < second_min) && (parents[j].second != the_min_GA)) {
				second_min = parents[j].second;
				mother = parents[j].first;
			}
		}
		// assume crossover always happen
		// generate a list of children that have a same population size as parents
		// from 1..1
		vector < pair<vector<int>, float> >my_parents;
		int f_m = 0;
		for (int i = 1; i < parents.size()-1; i++) {
			if (f_m >= path.size()) {
				f_m = 0;
			}
			else
				f_m++;
			}
			random_child = findChild(father, mother, f_m);
			GA_cost = distance(graph, random_child);
			my_parents.push_back(make_pair(random_child, GA_cost));
			// if exist parents cost bigger than child cost
			if (GA_cost < the_min_GA) {
				GA_best[0] = make_pair(random_child, GA_cost);
				//cout << "here1";
			}
			else {
				GA_best[0] = make_pair(father,the_min_GA);
				//cout << "here2";
			}
			
		// assume mutation happen by random rate
		// random rate generator
		int counter = 0;
		int c = 0;
		while (counter < 100) {
			counter++;
			int p = rand() % 10 + 1;
			if (p == 2) {
				c++;
			}
		}
		// if 2 happen 5 times then mutation happen
	
		if (c > 5) {
			random_child = path_generator(path);
			GA_cost = distance(graph, random_child);
			my_parents.push_back(make_pair(random_child, GA_cost));
			if (GA_cost < the_min_GA) {
				GA_best[0] = make_pair(random_child, GA_cost);
				//cout << "here3";
			}
			else {
				GA_best[0] = make_pair(father, the_min_GA);
				//cout << "here4";
			}
		}
		parents = my_parents;
		generations++;
	}
	//cout << endl;
	cout << "The smallest path in GA is: ";
	for (int j = 0; j < GA_best.size(); j++) {
		vector<int> t;
		t = GA_best[j].first;
		for (int k = 0; k < t.size(); k++) {
			std::cout << t[k] << " ";
		}
		std::cout << " ";
		cout << "and the cost is ";
		std::cout << GA_best[j].second << endl;
	}
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	return time_span.count();
}

vector<int> TSP::findChild(vector<int> father, vector<int> mother, int p)
{
	/*int temp  = father[p];
	if (mother[temp] != 1) {
		swap(mother[temp - 1], mother[temp]);
	}*/

	int temp  = mother[p];
	if (father[temp] != 1) {
		swap(father[temp - 1], father[temp]);
	}
	return father;
}


vector<int> TSP::path_generator(vector<int>path)
{
	// generate a random path
	
	vector<int>random_path;// select as best
	random_path.push_back(1);
	vector<int>visited;
	for (int i = 0; i < path.size(); i++) {
		visited.push_back(0);
	}
	visited[0] = 1;// mark node 1 visited

	while (random_path.size() != path.size()) {

		int p = rand() % path.size() + 1;
		random_path.push_back(p);

		if (visited[p - 1] != 0) {
			random_path.pop_back();
		}
		else {
			visited[p - 1] = 1;
		}
	}
	random_path.push_back(1);// 1...1

	/*cout << "The path is: ";
	for (int i = 0; i < random_path.size(); i++) {
		cout << random_path[i] << " ";
	}
	cout << endl;*/
	return random_path;
}






