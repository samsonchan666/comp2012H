#include "scoreBoard.h"

scoreBoard::scoreBoard(QWidget * parent, Qt::WindowFlags f)
: QLabel(parent, f), level(1), score(0)
{


}

void scoreBoard::updateDisplay()
{
	QPixmap myPix(QSize(80,40));
	myPix.fill(Qt::white);

	QPainter qPainter(&myPix);

	qPainter.setPen("#000000");

	QString s = QString("Score:%1").arg(QString::number(score));
	QString l = QString("Level:%1").arg(QString::number(level));

	qPainter.drawText(QPoint(0,10),s);
	qPainter.drawText(QPoint(0,20),l);



	this->setPixmap(myPix);
	this->update();	
}

void scoreBoard::scoreDisplay(int _score)
{
	score =_score;
	updateDisplay();
}

void scoreBoard::levelDisplay(int _level)
{
	level = _level;
	updateDisplay();
}