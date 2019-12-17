#pragma once
#include<iostream>
using namespace std;
template<class T>
class LinkedQueue
{
public:
	LinkedQueue() :rear(NULL), front(NULL) {};
	~LinkedQueue(makeEmpty());
	void EnQueue(const T& x);    //入队      
	void DeQueue(T& x);              //出队      
	bool getFront(T& x) const;
	void makeEmpty();
	bool IsEmpty() const { return front == NULL; }
	int getSize() const;
protected:
	LinkedQueue* front, * rear;
};

