#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <fstream>
#include "HashTable.h"
#include "Student.h"
#include "course.h"
#include "courseSelect.h"
#include "deque.h"

using namespace std;
class Utility
{
private:
	HashTable<Student>* s_hs;
	HashTable<Course>* c_hs;
	Deque<CourseSelect>* c_list;
public:
	Utility() : s_hs(NULL), c_hs(NULL), c_list(NULL) {}
	Utility(HashTable<Student>* _s_hs) : s_hs(_s_hs) {}
	Utility(HashTable<Course>* _c_hs) : c_hs(_c_hs) {}
	Utility(HashTable<Student>* _s_hs, HashTable<Course>* _c_hs, Deque<CourseSelect>* _c_list)
	 : s_hs(_s_hs), c_hs(_c_hs), c_list(_c_list) {}
	~Utility() {} 

	void outputStu();
	void outputCrs() ;
	void outputListCrs() ;
	void outputListStu() ;

	static bool IdComp(Student a, Student b) { return a < b;}
	static bool CrsComp(Course a, Course b) { return a < b;}	
};



#endif