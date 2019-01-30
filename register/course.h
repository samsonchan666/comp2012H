#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
class Course
{
private:
	string code, name, credit;

public:
	Course() : code("") , name(""), credit("") {}
	~Course() {}

	void setCode(string _code) { code = _code;}
	void setName(string _name) { name = _name;}
	void setCredit(string _credit) { credit = _credit;}

	string getCode() const { return code; }
	string getName() const { return name; }
	string getCredit() const { return credit; }

	bool checkValidCode(string _code) ;
	bool checkValidName(string _name);
	bool checkValidCredit(string _gender);

	bool operator==(Course c) { return (getCode()==c.getCode()); }
	bool operator<(Course c);
};


#endif