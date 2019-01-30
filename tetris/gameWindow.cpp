#include "gameWindow.h"

gameWindow::gameWindow(QWidget* parent)
:	QMainWindow(parent)
{
	mainLayout.addWidget(&gameboard);
	mainLayout.addLayout(&layout);
	layout.addWidget(&previewwindow,5);
	layout.addWidget(&scoreboard,1);

	setCentralWidget(new QWidget);
	centralWidget()->setLayout(&mainLayout);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), &gameboard, SLOT(updateWindow()));
	connect(&gameboard, SIGNAL(blockChanged(Block*)), &previewwindow, SLOT(previewDisplay(Block*)));
	connect(&gameboard, SIGNAL(scoreChanged(int)), &scoreboard, SLOT(scoreDisplay(int)));
	connect(&gameboard, SIGNAL(levelChanged(int)), &scoreboard, SLOT(levelDisplay(int)));
	connect(&gameboard, SIGNAL(levelChanged(int)), this, SLOT(start(int)));

	initialed = false;
}

void gameWindow::start(int level)
{
	timer->start(1000-(level-1)*100);
}

void gameWindow::keyPressEvent(QKeyEvent *event)
{
	if (!(initialed) && (event->key() == Qt::Key_Up)) {
		start(1);
		initialed = true;
	}
	gameboard.keyPressEvent(event);
}
