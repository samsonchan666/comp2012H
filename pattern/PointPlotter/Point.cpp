#include "Point.h"

bool Point::check_collinear(Point& i, Point& j)
{
	double dy = double(getY()) - double(i.getY());
	double dx = double(getX()) - double(i.getX());
	double _dy = double(getY()) - double(j.getY());
	double _dx = double(getX()) - double(j.getX());
	double slope = dy / dx;
	double _slope = _dy / _dx;
	if (slope == _slope) return true;
	else return false;
}

bool Point::operator==(const Point& p)
{
	return (getAngle() == p.getAngle());
}

void Point::setAngle(Point& p)
{
	double dy = double(y) - double(p.y);
	double dx = double(x) - double(p.x);
	if ( dy < 0) dy = -dy;
	if ( dx < 0) dx = -dx;
	p.angle = atan2(dy, dx); 
}

void Point::draw(QPainter& painter)
{
	int px = getX()/100;
	int py = 328-getY()/100;
	painter.drawPoint(px,py);
}

void Point::drawTo(QPainter* painter, Point q)
{
	QPen pen(Qt::black);
	pen.setWidth(2);
	painter->setPen(pen);
	int px = getX()/100;
	int py = 328-getY()/100;
	int _px = q.getX()/100;
	int _py = 328-q.getY()/100;
	painter->drawLine(px, py, _px, _py);
}