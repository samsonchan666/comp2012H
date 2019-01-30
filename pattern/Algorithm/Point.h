#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <cmath>
//include <QPainter>


using namespace std;
class Point
{
private:
	int x,y;
	double angle;
	bool push_flag;
public:
	Point() : x(0), y(0), angle(0), push_flag(true) {}
	~Point() {}
	void set(int cx, int cy) { x = cx; y = cy; }
	void setAngle(Point& p);
	void setFlag() { push_flag = !(push_flag);}
	int getX() const { return x;}
	int getY() const { return y;}
	double getAngle() const { return angle;}
	bool getFlag() const { return push_flag;}
	// void draw(QPainter& painter);
	// void drawTo(QPainter* painter, Point q);
	bool check_collinear(Point& i, Point& j);
	bool operator== (const Point& p); 
	bool operator< (const Point& p) { return getX()<p.getX(); }
};



#endif