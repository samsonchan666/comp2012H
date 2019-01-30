#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include "block.h"
#include "piece.h"

using namespace std;
class gameManager
{
private:
	int score, level, condScore;
	vector<Piece> record;
	bool** table;

public:
	gameManager();
	~gameManager() {
		for (int i = 0; i < 10; i++){
			delete[] table[i];
		}
	}

	void setScore(int _score) { score = _score; }
	void setLevel(int _level) { level = _level; }
	void setRecord(Block* block);
	void setTable(Block* block);
	void resetTable();

	int getScore() { return score; }
	int getLevel() { return level; }
	vector<Piece> getRecord() { return record;}
	bool** getTable() { return table;}


	bool checkCollision(Block* block, int a);
	void checkRemoveLine();	//return the number of removed row
	bool fullLine(int a);
	void removeLine(int a);

};

#endif