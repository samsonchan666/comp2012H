#ifndef RANDOMIZEDQUEUE_H
#define RANDOMIZEDQUEUE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
using namespace std;

#define MAX_NUM_NODE 32

/* randomizedQueue interface */
template<typename T>
class RandomizedQueue
{
private:
	struct Node {
		T data;
	};
	int counter, arr_size;
	Node** node_array;
public:
	class Iterator;

	RandomizedQueue();
	~RandomizedQueue() {};

	inline bool isEmpty() { return (!counter) ;}
	inline int size() { return counter; }

	void enqueue(T item);
	T dequeue();
	T sample();
	Iterator iterator();
};

template<typename T>
class RandomizedQueue<T>::Iterator
{
private:
	int arr_size, index;
	Node** arr_elem;	//create node array
public:
	Iterator() {}
	~Iterator() {}

	Iterator(const RandomizedQueue<T>& q);

	Iterator& operator++() ;	//overload ++ operator

	T& operator*() ;	//overload deference operator
};

/* randomizedQueue implementation */
template<typename T>
RandomizedQueue<T>::RandomizedQueue()
: counter(0), arr_size(MAX_NUM_NODE) ,node_array(new Node*[MAX_NUM_NODE]) 
{
	memset(node_array, 0, arr_size * sizeof(Node*)) ;
}

template<typename T>
void RandomizedQueue<T>::enqueue(T item)
{
	Node **new_arr;
	Node* tmp = new Node;
	tmp->data = item;
	if (counter == arr_size) // enlarge the array
	{
		new_arr = new Node*[arr_size*2];
		arr_size*=2;
		memcpy(new_arr,node_array,arr_size*sizeof(Node*));
		delete[] node_array;
		node_array = new_arr;
	}
	node_array[counter] = tmp;
	counter++;
}

template<typename T>
T RandomizedQueue<T>::dequeue()
{
	if (isEmpty()) { throw runtime_error("Remove from empty ran_deque");}
	int pointerNum;
	T item;
	Node** new_arr;

	pointerNum = rand() % (counter);
	item = node_array[pointerNum]->data;
	node_array[pointerNum] = node_array[counter-1];
	counter--;
	
	return item;
}

template<typename T>
T RandomizedQueue<T>::sample()
{
	int pointerNum;
	T item;
	pointerNum = rand() % (counter);
	item = node_array[pointerNum]->data;

	return item;
}

template<typename T>
typename RandomizedQueue<T>::Iterator RandomizedQueue<T>::iterator()
{
	return Iterator(*this);
}

/* Iteration implementatin */
template<typename T>
RandomizedQueue<T>::Iterator::Iterator(const RandomizedQueue& q)
:arr_elem(new Node*[q.counter]), arr_size(q.counter), index(0)
{
	int i;
	for ( i = 0; i < arr_size; i++)
	{
		arr_elem[i] = q.node_array[i];
	}
}

template<typename T>
typename RandomizedQueue<T>::Iterator& RandomizedQueue<T>::Iterator::operator++()
{
	index++;
	return *this;
}

template<typename T>
T& RandomizedQueue<T>::Iterator::operator*()
{
	return arr_elem[index]->data;
}


#endif


