#include <QApplication>
#include <QtGui>
#include "gameWindow.h"

using namespace std;
int main(int argv, char **args)
{
	QApplication app(argv, args);

	gameWindow *window = new gameWindow();
	window->show();
	return app.exec();
}