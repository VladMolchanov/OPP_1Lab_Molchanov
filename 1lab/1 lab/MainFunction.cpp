#include <iostream>
#include <Windows.h>
#include <new.h>
#include "Man.h"
#include "ExceptionErrorMemory.h"
#pragma warning (disable:4703)
using namespace std;

void outData(Man &bufObj) { 
	bufObj.getAllData();
	}

void recordData(Man &bufObj) {
	try{
		bufObj.recordData();
		}
	catch(exRecordFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exCloseFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(exOpenFile exMessage){
		cout << exMessage.what() << endl;
		}
	catch(...){
		cout << "Error!" << endl;
		}
	}

int main() {
	char *name;
	char *surname;
	int age = 0;
	int memorySize;
	do{
		try{
			cout << "Which amount of memory should be used?" << endl;
			cin >> memorySize;
			if( memorySize > 256){
				throw exErrorMemory("The number is too large!");
				}
			name = new char[memorySize];
			surname = new char[memorySize];
			}
		catch(bad_alloc){
			cout << "Error in the memory allocation!" << endl << "The programm has been stoped." <<endl;
			memorySize = 0;
			return 1;
			}
		catch(exErrorMemory exMessage){
			cout << exMessage.what() << endl;
			memorySize = 0;
			}
		catch(...){
			cout << "Error!" << endl;
			memorySize = 0;
			return 1;
			}
		}while(!memorySize);
	cout << "Enter name:";
	cin >> name;
	cout << "Enter surname:";
	cin >> surname;
	cout << "Enter age:";
	cin >> age;
	Man obj (name , surname , age);
	outData (obj);
	recordData (obj);
	system("pause");
	delete []name;
	delete []surname;
	return 0;
	}

