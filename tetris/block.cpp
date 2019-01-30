#include "block.h"

void Block::setBlock()
{
	static const int position[7][4][2] = { 
		{{0,0}, {0,-1}, {0,1},{0,2}},	//type 1
		{{0,0}, {-1,0}, {0,-1},{-1,-1}},  // type 2
		{{0,0}, {0,1}, {1,0},{1,-1}},	//type 3
		{{0,0}, {0,-1}, {1,0},{1,1}},	//type 4
		{{0,0}, {0,-1}, {1,-1},{0,1}},	//type 5
		{{0,0}, {0,-1}, {-1,-1},{0,1}},	//type 6
		{{0,0}, {-1,0}, {1,0},{0,1}},	//type 7
	 };

	int number;
	// srand (time(NULL));
	number = rand() % 7 ;	 

	for (int i = 0; i < NO_OF_PIECE; i++){
		//number = 4;
		piece[i].setX(position[number][i][0]+5);
		piece[i].setY(position[number][i][1]+2);
		// cout << position[number][i][0] << " "
		// cout << position[number][i][1] << endl;
	}
}

void Block::setColor()
{
	int number;
	static const string colorCode[] = { "#000000", "#ff0000", "#00ff00", "#0000ff", "#00ffff", "#ffff00"};

	//srand (time(NULL));
	number = rand() % 6 ;

	color = colorCode[number];	

	for (int i = 0; i < NO_OF_PIECE; i++){
		piece[i].setPieceColor(color);
	}	
}

void Block::moveDown()
{
	if (!reachBtm()){
		int origY;
		int newY = 0;
		for (int i = 0; i < NO_OF_PIECE; i++){
			origY = piece[i].getY();
			newY = origY+1;
			piece[i].setY(newY);
		}			
	}
}

void Block::moveLeft()
{
	if (reachBoundary(1)) return;
	int origX;
	int newX = 0;
	for (int i = 0; i < NO_OF_PIECE; i++){
		origX = piece[i].getX();
		newX = origX-1;
		piece[i].setX(newX);
	}	
}

void Block::moveRight()
{
	if (reachBoundary(0)) return;
	int origX;
	int newX = 0;
	for (int i = 0; i < NO_OF_PIECE; i++){
		origX = piece[i].getX();
		newX = origX+1;
		piece[i].setX(newX);
	}	
}

void Block::leftRotation()
{
	if (outBoundary()) return;
	int origX, origY;
	int cenX = 0;
	int cenY = 0;	
	int newX = 0;
	int newY = 0;
	for (int i = 0; i < NO_OF_PIECE; i++){
		if ( i == 0 ) { 
			cenX = piece[i].getX();
			cenY = piece[i].getY();
			continue;
		}
		origX = piece[i].getX();
		origY = piece[i].getY();

		newX = cenX + (origY - cenY);
		newY = cenY - (origX - cenX);
		piece[i].setX(newX);
		piece[i].setY(newY);				
	}	
}

void Block::rightRotation()
{
	if (outBoundary()) return;
	int origX, origY;
	int cenX = 0;
	int cenY = 0;	
	int newX = 0;
	int newY = 0;
	for (int i = 0; i < NO_OF_PIECE; i++){
		if ( i == 0 ) { 
			cenX = piece[i].getX();
			cenY = piece[i].getY();
			continue;
		}
		origX = piece[i].getX();
		origY = piece[i].getY();

		newX = cenX + (cenY - origY);
		newY = cenY - (cenX - origX);
		piece[i].setX(newX);
		piece[i].setY(newY);				
	}	
}
bool Block::reachTop()
{
	int yCor;
	for (int i = 0; i < NO_OF_PIECE; i++){
		yCor = piece[i].getY();
		//cout << yCor << endl;
		if (yCor <= 1) return true;
	}
	return false;
}

bool Block::reachBtm()
{
	int yCor;
	for (int i = 0; i < NO_OF_PIECE; i++){
		yCor = piece[i].getY();
		//cout << yCor << endl;
		if (yCor == 19) return true;
	}
	return false;
}

bool Block::reachBoundary(int a)
{
	int xCor;
	for (int i = 0; i < NO_OF_PIECE; i++){
		xCor = piece[i].getX();
		//cout << xCor << endl;
		if ( a == 1 && (xCor == 0)) return true; //left boundary 
		else if ( a == 0 && (xCor == 9)) return true; //right bondary
	}
	return false;	
}

bool Block::outBoundary()
{
	int origX, origY;
	int cenX = 0;
	int cenY = 0;	
	int newX = 0;
	int newY = 0;
	for (int i = 0; i < NO_OF_PIECE; i++){
		if ( i == 0 ) { 
			cenX = piece[i].getX();
			cenY = piece[i].getY();
			continue;
		}
		origX = piece[i].getX();
		origY = piece[i].getY();

		newX = cenX + (origY - cenY);
		newY = cenY - (origX - cenX);
		if ( newX > 9 || newX < 0 ) return true;
		else if ( newY > 19 || newY < 0) return true;		
	}
	return false;
}