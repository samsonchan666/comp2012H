#include <iostream>
#include <fstream>
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include "MainWindow.h"
#include "Point.h"

using namespace std;
int main(int argv, char **args)
{
	QApplication app(argv, args);

	ifstream fin(args[1]); // file input
	if (argv < 2) 
	{
		cout << "Unable to open file: input.txt" << endl;
		exit(1);
	}
	else if (!fin.is_open()) 
	{
		cout << "Unable to open file: " << args[1] << endl;
		exit(1);
	}
	int count, x, y;
	int i = 0;
	fin >> count;
	Point* point = new Point[count+1]; // ADT Point
	while (!fin.eof())
	{
		fin >> x;
		fin >> y;
		point[i].set(x,y);
		i++;
	}

	MainWindow *window = new MainWindow(point, count);
	window->show();
	return app.exec();
}