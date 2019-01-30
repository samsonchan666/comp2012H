#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "piece.h"

#define NO_OF_PIECE 4

using namespace std;
class Block
{
private:
	Piece* piece;
	string color;

public:
	Block() : piece(new Piece[NO_OF_PIECE]), color("") {}
	~Block() { delete[] piece; }

	void setBlock();
	void setColor();

	Piece* getBlock() { return piece; }
	string getColor() { return color; }

	void moveDown();
	void moveLeft();
	void moveRight();
	void leftRotation();
	void rightRotation();

	bool reachTop();
	bool reachBtm();
	bool reachBoundary(int a);
	bool outBoundary();
};





#endif