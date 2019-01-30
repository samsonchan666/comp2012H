#include <iostream>
#include <cstdlib>
#include "Point.h"
#include "algorithm.h"

using namespace std;
int main()
{
	int size,x, y;
	cin >> size;
	Point* point = new Point[size];
	int i = 0;
	while (cin >> x && cin >> y)
	{
		point[i].set(x,y);
		i++;
	}
	Fast fast(point,size);
	fast.search();	
	return 0;
}