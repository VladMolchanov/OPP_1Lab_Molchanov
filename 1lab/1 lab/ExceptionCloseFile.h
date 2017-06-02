#include <iostream>
#include "ExceptionOpenFile.h"
using namespace std;

class exCloseFile: public exOpenFile {
public: 
	exCloseFile (char* typeOfException) : exOpenFile (typeOfException) {}
	};

