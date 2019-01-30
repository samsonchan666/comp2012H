#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
class Piece
{
private:
	int x, y;
	string color;

public:
	Piece(): x(0), y(0), color("") {}
	Piece(int _x, int _y) : x(_x), y(_y), color("") {}
	~Piece() {}

	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setPieceColor(string _color) { color = _color; }

	int getX() { return x; }
	int getY() { return y; }
	string getPieceColor() { return color; }

};


#endif