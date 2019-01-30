#include "algorithm.h"

Point* Brute::print(Deque<Point>& deque)
{
	Point* tmpResult = new Point[deque.size()];
	int resultno = 0;
	printf("4: ");
	while (!(deque.isEmpty()))
	{
		Point tmp;
		tmp = deque.removeFirst();
		tmpResult[resultno] = tmp;
		resultno++;
		int x = tmp.getX();
		int y = tmp.getY();
		if (deque.size() == 0) { printf("(%d,%d)\n",x,y);}
		else printf("(%d,%d) -> ",x ,y);
	}
	return tmpResult;		
}
Deque<Point*> Brute::search()
{
	Deque<Point> deque;
	Deque<Point*> result;
	sort(point_arr, point_arr+size ,PtComp);
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = i+1; j <size ; j++)
			for (int k = j+1; k < size; k++)
			{
				if(!(point_arr[i].check_collinear(point_arr[j],point_arr[k])))
					continue;
				for ( int l = k+1; l < size; l++)
				{
					if(point_arr[i].check_collinear(point_arr[j],point_arr[l])) 
					{
						deque.addLast(point_arr[i]);
						deque.addLast(point_arr[j]);
						deque.addLast(point_arr[k]);
						deque.addLast(point_arr[l]);						
						result.addLast(print(deque));
					}
					
				}
			}	
	}
	return result;
}

Point* Fast::print(Deque<Point>& deque)
{
	Point* tmpResult = new Point[deque.size()];
	int resultno = 0;
	while (!(deque.isEmpty()))
	{
		Point tmp;
		tmp = deque.removeFirst();
		tmpResult[resultno] = tmp;
		resultno++;
		int x = tmp.getX();
		int y = tmp.getY();
		if (deque.size() == 0) { printf("(%d,%d)\n",x,y);}
		else printf("(%d,%d) -> ",x ,y);	
	}
	return tmpResult;	
}
Deque<Point*> Fast::search()
{
	Deque<Point> deque;
	Deque<Point*> result;
	int i, j ,k;
	sort( point_arr, point_arr+size, PtComp); //a simple sort
	Point origin; //
	for (i = 0; i < size; i++)
	{
		Point* tmp = new Point[size-i];
		origin = point_arr[i];
		for (j = i+1; j < size; j++)
		{
			origin.setAngle(point_arr[j]);
		}
		sort(point_arr+i+1, point_arr+size, Comparator);
		int mycount = count(point_arr+i+1,point_arr+size,*(point_arr+i+1));
		if  (mycount>=3 && origin.getFlag() == true)//check whether the point had pushed before
		{
			deque.addLast(origin);
			printf("%d: ",mycount+1);
			{
				for (k = i+1; k < size ; k++)
				{
					if (point_arr[i+1] == point_arr[k])
					{
						point_arr[k].setFlag();
						deque.addLast(point_arr[k]);
					}
				}	
			}
			result.setCounter2(mycount);//set the number of elements in each tuple
			result.addLast(print(deque));	
		}
	}
	return result;
}
