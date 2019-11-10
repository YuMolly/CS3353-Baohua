#ifndef loader_hpp
#define loader_hpp

#include"Algorithm.h"

#include <iostream>
#include <vector>

class loader :public Algorithm {
public:
	loader();
	void load();
	void print();
	void execute();
	
private:
	int Gsize;//graph size
	std::vector<std::vector<float>> graph;
	std::vector<int> path;
	double time_BF;
	double time_DP;
};




#endif //!loader_hpp