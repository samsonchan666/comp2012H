#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
class Student
{
private:
	string id;
	int year;
	string name, gender;

public:
	Student() : id(""), year(0), name(""), gender(""){}
	~Student() {}

	void setId(string _id) { id = _id;}
	void setName(string _name) { name = _name; }
	void setYear(int _year) { year = _year; }
	void setGender(string _gender) { gender = _gender; }

	string getId() const{ return id;}
	string getName() const { return name;}
	int getYear() const { return year;}
	string getGender() const ;

	bool checkValidId(string _id) ;
	bool checkValidName(string _name);
	bool checkValidGender(string _gender);

	bool operator==(Student s) { return (getId()==s.getId()); }
	bool operator<(Student s);	//overloading the less than operator
};

#endif