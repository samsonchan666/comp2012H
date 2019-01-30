#include <iostream>
#include <cstdio>
#include "randomized_queue.h"
using namespace std;


int main(int argc, char* argv[])
{
	srand(time(0));
	int num;
	if ( argc == 2 ) { num = atoi(argv[1]); } 
	else return 0;
	
	RandomizedQueue<char> rq;
	char a;

	while(cin >> a) 
	{
		rq.enqueue(a);
	}

	for (int i = 0 ; i < num; i++)
	{
		cout << rq.dequeue() << endl;
	}

	return 0;
}