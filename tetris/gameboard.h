#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
// #include <ctime>
// #include <limits>
#include <vector>
#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "piece.h"
#include "block.h"
#include "gameManager.h"

using namespace std;
class gameBoard : public QLabel
{
	Q_OBJECT
private:
	int score, level;
	bool first, collision;
	string Color;
	Block *block, *nextBlock;
	Piece* piece;
	gameManager manager;

	QImage myImage;

public:
	gameBoard(QWidget * parent = 0, Qt::WindowFlags f = 0);
	void UpdateBlockPosition();
	void keyPressEvent(QKeyEvent *event);
	
public slots:
	void updateWindow();

signals:
	void blockChanged(Block* block);
	void scoreChanged(int score);
	void levelChanged(int level);
};


#endif