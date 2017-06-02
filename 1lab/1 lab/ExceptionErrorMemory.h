#include <iostream>
#include "ExceptionErrorRecord.h"
using namespace std;

class exErrorMemory: public exRecordFile {
public: 
	exErrorMemory (char* typeOfException) : exRecordFile (typeOfException) {}
	};