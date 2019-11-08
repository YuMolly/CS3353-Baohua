#ifndef TSP_hpp
#define TSP_hpp

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<chrono>

class TSP {
public:
	TSP();
	double BF(std::vector<std::vector<float>>,int);
	void permutation(std::vector<std::vector<float>>, std::string, int,int);
	float distance(std::vector<std::vector<float>>,std::string);
	void checkBF();

	void DP(std::vector<std::vector<float>>, int);

private:
	std::vector<std::pair<std::string, float>>p1;
	
};

#endif //!TSP_hpp

