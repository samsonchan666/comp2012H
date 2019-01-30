#include "gameManager.h"

gameManager::gameManager() : score(0), level(1), condScore(100)
{
	table = new bool*[10];
	for (int i = 0; i < 10; i++){
		table[i] = new bool[20];
		for (int j = 0; j < 20; j++){
			table[i][j] = false;
		}
	}

}

void gameManager::setRecord(Block* block)
{
	Piece* piece = new Piece[NO_OF_PIECE];
	piece = block->getBlock();
	for (int i = 0; i < NO_OF_PIECE; i++){
		record.push_back(piece[i]);
	}
}


void gameManager::setTable(Block* block)
{
	int x = 0;
	int y = 0;
	Piece* piece = block->getBlock();
	for (int i = 0; i < NO_OF_PIECE; i++){
		x = piece[i].getX();
		y = piece[i].getY();
		table[x][y] = true;
	}
}

void gameManager::resetTable()
{
	for (int i = 0; i < 10; i++){
		table[i] = new bool[20];
		for (int j = 0; j < 20; j++){
			table[i][j] = false;
		}
	}
}

bool gameManager::checkCollision(Block* block, int a)
{
	int x = 0;
	int y = 0;
	Piece* piece = block->getBlock();
	for (int i = 0; i < NO_OF_PIECE; i++){
		x = piece[i].getX();
		y = piece[i].getY();
		if (block->reachBoundary(0)||block->reachBoundary(1)) a = 1;
		switch(a){
			case 1: {
				if (table[x][y+1] == true) {
				return true;			//downward collision
				}

			}
			break;

			case 2: {
				if (table[x-1][y] == true) {
				return true;			//left collision
				}
			}
			break;

			case 3: {
				if (table[x+1][y] == true) {
				return true;			//right collision		
				}
			}
			break;

			default: break;
			}


		}
	return false;
}

bool gameManager::fullLine(int a)
{
	for (int i = 0; i < 10; i++){
		if (table[i][a] == false) return false;
	}
	return true;
}

void gameManager::checkRemoveLine()
{
	int counter = 0;
	for (int i = 0; i < 20; i++){
		if ( fullLine(i) == true ){
			removeLine(i);
			counter++; //check the number of removed row
		}
	}
	score += counter*counter*10; //add score
	level = score/100;
	if (level == 0) level = 1;
}

void gameManager::removeLine(int a)
{
	int yCor = -1;
	cout << "a is " << a << endl;
	vector<Piece>::iterator it;
	for ( it = record.begin(); it != record.end(); ++it){
		yCor = (*it).getY();
		if ( yCor == a ) {
			record.erase(it);
			--it;	//As erase operation return pointer to next element
		}
	}

	for ( it = record.begin(); it != record.end(); ++it ){
		yCor = (*it).getY();
		if ( yCor > a ) continue;
			(*it).setY(yCor+1);
	}
	resetTable();
	int x = 0;
	int y = 0;
	for ( it = record.begin(); it != record.end(); ++it ){
		for (int i = 0; i < NO_OF_PIECE; i++){
		x = (*it).getX();
		y = (*it).getY();
		table[x][y] = true;
		}	
	}
}

