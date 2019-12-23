#pragma once
#include<iostream>
using namespace std;
template<class T>
class LinkedQueue
{
public:
	LinkedQueue() :rear(NULL), front(NULL) {};
	~LinkedQueue(makeEmpty());
	void EnQueue(const T& x);    //���      
	void DeQueue(T& x);              //����      
	bool getFront(T& x) const;
	void makeEmpty();
	bool IsEmpty() const { return front == NULL; }
	int getSize() const;
protected:
	LinkedQueue* front, * rear;
};

