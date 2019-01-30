#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm> 
#include "Student.h"
#include "course.h"
#include "deque.h"

#define STUDENT_BUCKETS 29
#define COURSE_BUCKETS 17
#define S_BASE 10
#define C_BASE 36

using namespace std;
template <typename T>
class HashTable
{
private:
	int index;
	Deque<T>* q;
public:
	HashTable() : index(0), q(NULL) {}
	HashTable(Student s) : index(0), q(new Deque<T>[STUDENT_BUCKETS]) {}
	HashTable(Course h) : index(0), q(new Deque<T>[COURSE_BUCKETS]) {}
	~HashTable() {}

	int hashFunc(string key);
	int hashFuncCrs(string key);

	void pushStu(Student s);	/* student operations */
	void modifyStu(Student s);	
	void deleteStu(Student s);
	void queryStu(Student s);
	void print();
	bool isExist(Student s);
	Student getStu(Student s);

	void pushCrs(Course c);		/* course operations */
	void modifyCrs(Course c);	
	void deleteCrs(Course c);
	void queryCrs(Course c);
	void printCrs();
	bool isExist(Course c);
	Course getCrs(Course c);

	Deque<T>* getDeque() { return q;}
	int getIndex() { return index;}

	bool isEmpty(int buckets);
	int size(int buckets);

	void clearStu() { index = 0; q = new Deque<T>[STUDENT_BUCKETS];}
	void clearCrs() { index = 0; q = new Deque<T>[COURSE_BUCKETS];}

	/* Student id comparator */
	static bool IdComp(Student a, Student b) { return a < b;}

	/* Course code comparator */
	static bool CrsComp(Course a, Course b) { return a < b;}
};

template<typename T>
int HashTable<T>::hashFunc(string key)
{
	int sum = 0;
	for (int i =0; key[i] != '\0'; i++){
		sum += (key[i]-48) * pow( S_BASE, i);

	}
	sum %= STUDENT_BUCKETS;
	index = sum;
	return sum;
}

template<typename T>
int HashTable<T>::hashFuncCrs(string key)
{
	long sum = 0;
	int length = strlen(key.c_str());
	for (int i =0; i < length; i++){
		if (isdigit(key[i])) {
			sum += (key[i]-48+10) * pow( C_BASE, i);
		}	
		else {
			sum += (key[i]-64+10) * pow( C_BASE, i);
		}
	}
	sum %= COURSE_BUCKETS;
	index = sum;
	return sum;
}

template<typename T>
void HashTable<T>::pushStu(Student s)
{
	int i = 0;
	int count = q[index].size();
	Student s_arry[count+1];
	if (q[index].isEmpty()) q[index].addLast(s);
	else
	{
		while (!(q[index].isEmpty()))
		{
			s_arry[i] = q[index].removeFirst();
			i++;
		}
		s_arry[i] = s;
		sort(s_arry, s_arry+count+1, IdComp); //sorting
		for (int j = 0; j < count+1; j++)
		{
			q[index].addLast(s_arry[j]);
		}		
	}

}

template<typename T>
void HashTable<T>::modifyStu(Student s)
{

}

template<typename T>
void HashTable<T>::deleteStu(Student s)
{
	if (!(q[index].isEmpty())) {
		q[index].removeNode(s);
		cout << "Deletion of student record successful" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();
	}
	else{
		cout << "Student not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();
	} 

}

template<typename T>
void HashTable<T>::queryStu(Student s)
{
	Deque<Student>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++){
       if ( s == *itr){
       cout << "ID: " << (*itr).getId() << endl;
       cout << "Name: " << (*itr).getName() << endl;
       cout << "Year: " << (*itr).getYear() << endl;
       cout << "Gender: " << (*itr).getGender() << endl;
	   cout << endl;
	   cout << "Hit ENTER to continue..." << endl;
	   getchar();
       break;
       }
       ++itr;
    }
}

template<typename T>
void HashTable<T>::print()
{
	for (int i = 0; i < STUDENT_BUCKETS; i++){
		if (q[i].isEmpty()) continue;
		else {
			Deque<Student>::Iterator itr = q[i].iterator();
			for (int j = 0 ; j < q[i].size(); j++){
				T tmp = *itr;
				cout << tmp.getId() << endl;
				++itr;
			}
		}
	}
}

template<typename T>
bool HashTable<T>::isExist(Student s)
{
	Deque<Student>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++){
        if ( s == *itr) {
        	return true;
        }
        else ++itr;
	}
	return false;
}

template<typename T>
Student HashTable<T>::getStu(Student s)
{
	Deque<Student>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++){
        if ( s == *itr) {
        	return (*itr);
        }
        else ++itr;
	}
}

template<typename T>
void HashTable<T>::pushCrs(Course c)
{
	int i = 0;
	int count = q[index].size();
	Course c_arry[count+1];
	if (q[index].isEmpty()) q[index].addLast(c);
	else
	{
		while (!(q[index].isEmpty()))
		{
			c_arry[i] = q[index].removeFirst();
			i++;
		}
		c_arry[i] = c;
		sort(c_arry, c_arry+count+1, CrsComp); // sorting Course code
		for (int j = 0; j < count+1; j++)
		{
			q[index].addLast(c_arry[j]);
		}		
	}

}

template<typename T>
void HashTable<T>::deleteCrs(Course c)
{
	if (!(q[index].isEmpty())) {
		q[index].removeNode(c);
		cout << "Deletion of course record successful" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();
	}
	else{
		cout << "Course not exist" << endl << endl;
		cout << "Hit ENTER to continue..." << endl;
		getchar();
	} 
}

template<typename T>
void HashTable<T>::queryCrs(Course c)
{
	Deque<Course>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++){
       if ( c == *itr){
       cout << "Code: " << (*itr).getCode() << endl;
       cout << "Name: " << (*itr).getName() << endl;
       cout << "Credit: " << (*itr).getCredit() << endl;
	    cout << endl;
	    cout << "Hit ENTER to continue..." << endl;
	    getchar();      
       break;
       }
       ++itr;
    }
}

template<typename T>
void HashTable<T>::printCrs()
{
	for (int i = 0; i < COURSE_BUCKETS; i++){
		if (q[i].isEmpty()) continue;
		else {
			Deque<Student>::Iterator itr = q[i].iterator();
			for (int j = 0 ; j < q[i].size(); j++){
				T tmp = *itr;
				cout << tmp.getCode() << endl;
				++itr;
			}
		}
	}	
}

template<typename T>
bool HashTable<T>::isExist(Course c)
{
	Deque<Course>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++){
        if ( c == *itr) {
        	return true;
        }
        else ++itr;
	}
	return false;	
}

template<typename T>
Course HashTable<T>::getCrs(Course c)
{
	Deque<Course>::Iterator itr = q[index].iterator();
	for(int i = 0; i < q[index].size();i++){
        if ( c == *itr) {
        	return (*itr);
        }
        else ++itr;
	}	
}


template<typename T>
bool HashTable<T>::isEmpty(int buckets)
{
	for (int i = 0; i < buckets; i++){
		if (q[i].isEmpty()) continue;
		else return false;
	}
	
	return true;	
}

template<typename T>
int HashTable<T>::size(int buckets)
{
	int count = 0;
	for (int i = 0; i < buckets; i++){
		if (q[i].isEmpty()) continue;
		else count+=q[i].size();
	}
	
	return count;		
}
#endif