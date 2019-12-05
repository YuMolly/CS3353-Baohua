#ifndef TSP_hpp
#define TSP_hpp

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<chrono>

class TSP {
public:
	TSP(int);
	double BF(std::vector<std::vector<float>>,std::vector<int>);
	void permutation(std::vector<std::vector<float>>, std::vector<int>, int,int);
	float distance(std::vector<std::vector<float>>,std::vector<int>);
	void checkBF();

	double DP(std::vector<std::vector<float>>, std::vector<int>);
	float findCost(std::vector<std::vector<float>>&,int,int, std::vector<std::vector<int>>&);
	

	double Tabu(std::vector<std::vector<float>>, std::vector<int>);
	std::vector<int> findNeighbour(std::vector<int>, int);
	int checkTabuExist(std::vector<int>);
	
	double GA(std::vector<std::vector<float>>, std::vector<int>);
	std::vector<int> findChild(std::vector<int>,std::vector<int>, int);

	std::vector<int> path_generator(std::vector<int>);
	
private:
	std::vector<std::pair<std::string, float>>p1;
	//BF string for each possible path and foloat for the corrsponsed cost
	
	int* path;
	int* arr;
	float cost;//for DP
	int size;
	std::vector<std::pair<std::vector<int>, float>> tabu_list;// for Tabu
	std::vector<std::pair<std::vector<int>, float>> GA_best;//for GA

}; 
#endif //!TSP_hpp

