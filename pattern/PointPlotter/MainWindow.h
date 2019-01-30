#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include "Point.h"
#include "deque.h"
#include "algorithm.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(Point* point, int count, QWidget* parent = 0);
	void paintEvent(QPaintEvent* );
	
private slots:
	void quit();
	void brute();
	void fast();

private:
	Point* _point;
	int _count;
	Deque<Point*> result;

	QAction *bruteAction;
	QAction *fastAction;
	QAction *exitAction;

	QMenu *fileMenu;	
};

#endif