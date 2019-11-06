#ifndef TSP_hpp
#define TSP_hpp
#include<vector>
#include<string>
#include<utility>

class TSP {
public:
	TSP();
	void BF(std::vector<std::vector<float>>,int);
	std::vector<std::string> permutation(std::string, int,int);
	void DP(std::vector<std::vector<float>>,int);
	float distance(std::vector<std::vector<float>>,std::string);
	bool check(std::vector<std::pair<std::string,float>>,std::string);
private:
	
	std::vector<std::vector<float>> graph;
};

#endif //!TSP_hpp

