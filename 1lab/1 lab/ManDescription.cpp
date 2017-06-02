#include <iostream>
#include <fstream>
#include "Man.h"
#include "ExceptionErrorMemory.h"
#pragma warning (disable:4996)
using namespace std;


Man :: Man (){
	name = NULL;
	surname = NULL;
	age = 0;
	}

Man :: Man (char* bufName , char* bufSurname , int bufAge ){
	name = new char[strlen(bufName) + 1];
	surname = new char[strlen(bufSurname) + 1];
	strcpy (name , bufName);
	strcpy (surname , bufSurname);
	age = bufAge;
	}

Man :: Man (Man &bufObj) {
	name = new char[strlen(bufObj.name) + 1];
	surname = new char[strlen(bufObj.surname) + 1];
	strcpy (name , bufObj.name);
	strcpy (surname , bufObj.surname);
	age = bufObj.age;
	}

Man :: ~Man () {
	delete [] name;
	delete [] surname;
	age = NULL;
	}

void  Man :: set (char* bufName , char* bufSurname , int bufAge){
	name = new char[strlen(bufName) + 1];
	surname = new char[strlen(bufSurname) + 1];
	strcpy (name , bufName);
	strcpy (surname , bufSurname);
	age = bufAge;
	}

void Man :: getName () {
	cout << name;
	}

void Man :: getSurname () {
	cout << surname;
	}

void Man :: getAge () {
	cout << age;
	}

void Man :: getAllData () {
	cout << "Name:" << name << endl << "Surname:" << surname << endl << "Age:" << age << endl ;
	}

void Man :: recordData () {
	char *checkFile;
	checkFile = new char [100];
	fstream dataFile("DataFile.txt",ios_base::app);
	if(!dataFile.is_open()){
		throw exOpenFile ("Error!Can't open the file.");
		}
	dataFile << name << " " << surname << " " << age <<endl;
	dataFile.close ();
	if(dataFile.is_open()){
		throw exCloseFile ("Error!Can't close the file.");
		}
	fstream dataCheckFile("DataFile.txt",ios_base::in);
	if(!dataCheckFile.is_open()){
		throw exOpenFile ("Error!Can't open the file.");
		}
	dataCheckFile >> checkFile;
	if(!checkFile[0])throw exRecordFile ("Sorry, for some reason the data can't be inputed in the file");
	dataCheckFile.close ();
	if( dataCheckFile.is_open() ){
		throw exCloseFile ("Error!Can't close the file.");
		}
	delete []checkFile;
	}







