#include <QtGui>
#include "MainWindow.h"
#include <iostream>
#include <time.h>

using namespace std;
MainWindow::MainWindow(Point* point, int count, QWidget* parent) 
	:  QMainWindow(parent), _point(point), _count(count)
{
	setMinimumSize(400, 400);

	bruteAction = new QAction(tr("Brute"), this);
	fastAction = new QAction(tr("Fast"), this);
	exitAction = new QAction(tr("E&xit"), this);

	connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(bruteAction, SIGNAL(triggered()), this, SLOT(brute()));
	connect(fastAction, SIGNAL(triggered()), this, SLOT(fast()));

	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(bruteAction);
	fileMenu->addAction(fastAction);
	fileMenu->addAction(exitAction);

	
}


void MainWindow::paintEvent(QPaintEvent* )
{
	QPainter painter(this);
	QPen pen(Qt::black);
	pen.setWidth(5);
	painter.setPen(pen);
	for (int i=0; i<_count;i++){
		_point[i].draw(painter);
	}
	Deque<Point*>::Iterator itr = result.iterator();
	int counter2 = result.getCounter2() ;
	for (int i = 0; i < result.size(); i++)
	{
		if ( counter2 == 0)
		{
			for ( int j = 0; j < 3; j++)
			{
			Point* tmp = *itr;
			tmp[j].drawTo(&painter,tmp[j+1]);
			}
			++itr;
		}
		else 
		{
			for ( int j = 0; j < counter2; j++)
			{
			Point* tmp = *itr;
			tmp[j].drawTo(&painter,tmp[j+1]);
			}
			++itr;
		}

	} 
}

void MainWindow::quit()
{
	qApp->quit();
}

void MainWindow::brute()
{
	clock_t t1,t2;
	Brute brute(_point,_count);
	t1=clock();
	result = brute.search();
	t2=clock();
	float diff ((float)t2-(float)t1);
	float seconds = diff / CLOCKS_PER_SEC;
	QString b = QString::number(seconds);
	QMessageBox::information( this, "Runnung Time", b);
	repaint();
}

void MainWindow::fast()
{
	clock_t t1,t2;
	Fast fast(_point, _count);
	t1=clock();
	result = fast.search();
	t2=clock();
	float diff ((float)t2-(float)t1);
	float seconds = diff / CLOCKS_PER_SEC;
	QString b = QString::number(seconds);
	QMessageBox::information( this, "Runnung Time", b);
	repaint();
}