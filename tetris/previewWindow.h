#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H
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
class previewWindow : public QLabel
{
	Q_OBJECT
private:
public:
	previewWindow(QWidget * parent = 0, Qt::WindowFlags f = 0);

public slots:
	void previewDisplay(Block* block);
	
};

#endif