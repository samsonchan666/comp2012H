#ifndef RECORDS_H
#define RECORDS_H
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
class Record
{
private:
	FILE* myfile;	
	HashTable<Student>* s_hs;
	HashTable<Course>* c_hs;
	Deque<CourseSelect>* c_list;
public:
	Record():  s_hs(NULL), c_hs(NULL), c_list(NULL) {}
	Record(HashTable<Student>* _s_hs, HashTable<Course>* _c_hs, Deque<CourseSelect>* _c_list)
	: s_hs(_s_hs), c_hs(_c_hs), c_list(_c_list) {}
	~Record() {} 

	void saveDatabase();
	void loadDatabase(HashTable<Student>* _s_hs, HashTable<Course>* _c_hs, Deque<CourseSelect>* _c_list);
};


#endif