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
	//int leave(std::vector<std::vector<float>>,int, std::vector<int>,float*);
	//void printDP();
private:
	std::vector<std::pair<std::string, float>>p1;
	//std::vector<float> DP_cost;
	int* path;
	float cost;//for DP
	int size;
};

#endif //!TSP_hpp

