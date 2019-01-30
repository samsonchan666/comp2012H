#ifndef COURSESELECT_H
#define COURSESELECT_H
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "deque.h"

using namespace std;
class CourseSelect
{
private:
	string id, code, mark;
public:
	CourseSelect() : id(""), code(""), mark("N/A") {}
	~CourseSelect() {}

	void setId(string _id) { id = _id;}
	void setCode(string _code) { code = _code;}
	void setMark(string _mark) { mark = _mark;}

	string getId() const { return id; }
	string getCode() const { return code;}
	string getMark() const { return mark;}

	bool checkValidMark(string _mark);

	bool operator==(CourseSelect cs);
	bool operator<(CourseSelect cs); //overloading the less than operator
};

#endif