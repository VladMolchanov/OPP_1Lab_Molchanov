#include <iostream>
using namespace std;

class Man {
	char* name;
	char* surname;
	int age;
public:
	Man ();
	Man ( char* , char* , int );
	Man (Man &);
	void set ( char* , char* , int );
	void getName ();
	void getSurname ();
	void getAge ();
	void getAllData ();
	void recordData ();
	~Man ();
	};
