#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "deque.h"

using namespace std;
int main()
{
    Deque<int> q;
    for (int i = 0 ; i < 3; i++){
        q.addLast(i);
    }
    Deque<int>::Iterator itr = q.iterator();

    
    
    q.removeNode(2);
    int size = q.size();
    cout << "size is " << size << endl;
    
    for (int i=0 ; i<size; i++){
        //q.removeNode(*itr);
        cout << *itr << endl;
        ++itr;
    }

    return 0;
}