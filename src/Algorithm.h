#ifndef Algorithm_hpp
#define Algorithm_hpp


#include <stdio.h>

class Algorithm {
public:
	virtual void load() = 0;
	virtual void print() = 0;
};

#endif //!Algorithm_hpp