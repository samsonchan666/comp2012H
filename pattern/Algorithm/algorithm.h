#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <vector>
#include "deque.h"
#include "Point.h"

using namespace std;
class Brute
{
private:
	Point* point_arr;
	Point** result;
	int size;
public:
	Brute() : point_arr(NULL), result(NULL), size(0){}
	~Brute() { delete[] point_arr;}
	Brute(Point* p, int s) : point_arr(p), size(s) {}
	static bool PtComp(Point p1 ,Point p2) { return p1 < p2;}
	Point* print(Deque<Point>& deque);
	Deque<Point*> search();
};

class Fast
{
private:
	Point* point_arr;
	const int size;
public:
	Fast() : point_arr(NULL), size(0){}
	~Fast() { delete[] point_arr;}
	Fast(Point* p, int s) : point_arr(p), size(s) {}
	static bool PtComp(Point p1 ,Point p2) { return p1 < p2;}
	static bool Comparator(Point p1 ,Point p2){return (p1 == p2)? (p1 < p2):(p1 == p2);}
	Point* print(Deque<Point>& deque);
	Deque<Point*> search();
};



#endif