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
	std::vector<std::vector<float>> getGraph();
	int getGsize();
	
private:
	int Gsize;//graph size
	std::vector<std::vector<float>> graph;
	double time_span;
};




#endif //!loader_hpp