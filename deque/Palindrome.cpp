#include <iostream>
#include <cstdio>
#include "deque.h"
using namespace std;

int main()
{
	string a, b;
	Deque<char> q;
	char c;
	int i = 0 ;
	cin >> a;
	b = a;
	while ( b[i] != '\0')
	{
		q.addLast(b[i]);
		i++;
	}
    i = 0;
	while (!(q.isEmpty()))
	{
		b[i] = q.removeLast();
		i++;
	}
	b[i] = '\0';
	i = 0;
	while ( a[i] != '\0')
	{
		if (a[i] == 'A') a[i] = 'T';
		else if (a[i] == 'T') a[i] = 'A';
		else if (a[i] == 'C') a[i] = 'G';
		else if (a[i] == 'G') a[i] = 'C';
		else { cout << "false" << endl;  return 0;}
		i++;
	}

	if ( a == b) { cout << "true" << endl;}
	else { cout << "false" << endl; }
	return 0;
}