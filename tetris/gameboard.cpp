#include "gameboard.h"

gameBoard::gameBoard(QWidget * parent, Qt::WindowFlags f)
: QLabel(parent, f), score(0), level(1), first(true), collision(false)
{
	myImage.load("background.bmp");

	this->setPixmap(QPixmap::fromImage(myImage));

	block = new Block;
	nextBlock = new Block;
	piece = new Piece[NO_OF_PIECE];

}

void gameBoard::updateWindow()
{
	myImage.load("background.bmp");
	if (first || collision||block->reachBtm()) {
		if (!(first)) {
			if (block->reachTop()) return;
			collision = false;

			manager.setTable(block);
			manager.setRecord(block);

			manager.checkRemoveLine();
			score = manager.getScore();
			level = manager.getLevel();
			block = nextBlock;

			nextBlock = new Block;
			nextBlock->setBlock();
			nextBlock->setColor();
		}
		else {
			first = false;

			block->setBlock();
			block->setColor();	

			nextBlock->setBlock();
			nextBlock->setColor();
			
		}
			emit blockChanged(nextBlock);
			emit scoreChanged(score);
			emit levelChanged(level);
			
			piece = block->getBlock();		
			Color = block->getColor();		

	} 

	QString color = QString::fromStdString(Color);
	QColor qcolor(color);
	QBrush brush(qcolor);

	QPainter qPainter(&myImage);
	qPainter.setBrush(brush);
	qPainter.setPen("#000000");

	for (int i = 0; i < NO_OF_PIECE; i++){
		int x = piece[i].getX();
		int y = piece[i].getY();
		x *= 20;
		y *= 20;
		qPainter.drawRect(x,y,20,20);
	}

	Piece memPiece;
	vector<Piece> memPiece_arr = manager.getRecord();
	vector<Piece>::iterator it;
	for (it = memPiece_arr.begin(); it!= memPiece_arr.end(); ++it){
			Piece memPiece = *it;
			int x = memPiece.getX();
			int y = memPiece.getY();
			x *= 20;
			y *= 20;

			string memColor = memPiece.getPieceColor();
			QString color = QString::fromStdString(memColor);
			QColor qcolor(color);
			QBrush brush(qcolor);
			qPainter.setBrush(brush);
			qPainter.setPen("#000000");						
			qPainter.drawRect(x,y,20,20);			
	}
	UpdateBlockPosition();
	this->setPixmap(QPixmap::fromImage(myImage));

}

void gameBoard::UpdateBlockPosition()
{
	if (!(manager.checkCollision(block,1))) block->moveDown();
	else collision = true;
	//update();
}

void gameBoard::keyPressEvent(QKeyEvent *event)
{
	//cout << "key is press" << endl;
	if((event->key() == Qt::Key_Left) && !(manager.checkCollision(block,2))) 
		{ block->moveLeft(); }
	else if ((event->key() == Qt::Key_Right) && !(manager.checkCollision(block,3)))
		{ block->moveRight(); }
	else if (event->key() == Qt::Key_Z) block->rightRotation();
	else if (event->key() == Qt::Key_X) block->leftRotation();
	else if (event->key() == Qt::Key_Down) {
		if (!(manager.checkCollision(block,1))) block->moveDown();
	}
}