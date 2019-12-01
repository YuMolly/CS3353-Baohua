
#include <iostream>
#include "loader.h"
#include <string>
#include <time.h>
using namespace std;
int main()
{   
	srand(time(NULL));
	loader lod;
	lod.load();
	lod.execute();
	//lod.print();
	cout << "HERE"<<endl;
	
}


