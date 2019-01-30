#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <iostream>

#include "gameboard.h"
#include "previewWindow.h"
#include "scoreBoard.h"

using namespace std;
class gameWindow : public QMainWindow
{
	Q_OBJECT
private:
	QHBoxLayout mainLayout;
	QVBoxLayout layout;

	QTimer* timer;

	gameBoard gameboard;
	previewWindow previewwindow;
	scoreBoard scoreboard;
	bool initialed;

public:
	gameWindow(QWidget* parent = 0);
	void keyPressEvent(QKeyEvent *event);

public slots:
	void start(int level);
};



#endif