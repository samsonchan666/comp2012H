#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <QtGui>
#include <QApplication>
#include <QLabel>

#include "piece.h"
#include "block.h"
#include "gameManager.h"

using namespace std;
class scoreBoard : public QLabel
{
	Q_OBJECT
private:
	int level, score;
public:
	scoreBoard(QWidget * parent = 0, Qt::WindowFlags f = 0);
	void updateDisplay();

public slots:
	void scoreDisplay(int score);
	void levelDisplay(int level);
	
};

#endif