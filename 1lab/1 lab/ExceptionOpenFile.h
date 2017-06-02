#include <iostream>
using namespace std;

class exOpenFile: public exception {
public: 
	exOpenFile (char* typeOfException) : exception (typeOfException) {}
	};

