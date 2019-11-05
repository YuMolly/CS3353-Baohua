#ifndef TSP_hpp
#define TSP_hpp
#include<vector>
#include<string>
class TSP {
public:
	TSP();
	void BF(std::vector<std::vector<float>>,int);
	void DP(std::vector<std::vector<float>>,int);
	float distance(std::vector<int>);
	bool check(std::vector<std::string>,std::string);
private:
	
	std::vector<std::vector<float>> graph;
};

#endif //!TSP_hpp

