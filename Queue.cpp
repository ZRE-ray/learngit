#include "Queue.h"
template<class T>
void LinkedQueue<T>::EnQueue(const T& x)
{ //将新元素x插入到队列的队尾  
	if (front == NULL)
	{              //创建第一个结点          
		front = rear = new LinkNode<T>(x);
		if (front == NULL) 
			return NULL;
	}   //分配失败       
	else {                                                        //队列不空, 插入           
		rear->link = new LinkNode<T>(x);
		if (rear->link == NULL) 
			return NULL;
		rear = rear->link;
	}
}

template<class T>
void LinkedQueue<T>::DeQueue(T& x)
{ //如果队列不空，将队头结点从链式队列中删去       
	while (!IsEmpty()) 
		return NULL;    //判队空      
	LinkNode<T>* p = front;
	x = front->data;
	front = front->link;
	delete p;
}

template<class T>
bool LinkedQueue<T>::getFront(T& x) const
{
	if (isEmpty())
	{
		cout << "队列为空" << endl;
	}
	return  front->link;
}
