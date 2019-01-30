#include "previewWindow.h"

previewWindow::previewWindow(QWidget * parent, Qt::WindowFlags f)
: QLabel(parent, f)
{


}

void previewWindow::previewDisplay(Block* block)
{
	QPixmap myPix(QSize(80,160));
	myPix.fill(Qt::white);

	QPainter qPainter(&myPix);

	QString color = QString::fromStdString(block->getColor());
	QColor qcolor(color);
	QBrush brush(qcolor);

	qPainter.setBrush(brush);
	qPainter.setPen("#000000");

	Piece* piece = block->getBlock();
	for (int i = 0; i < NO_OF_PIECE; i++){
		int x = piece[i].getX();
		int y = piece[i].getY();
		x-=4;
		x *= 20;
		y *= 20;
		qPainter.drawRect(x,y,20,20);
	}
	this->setPixmap(myPix);
	this->update();
}