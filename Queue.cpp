#include "Queue.h"
template<class T>
void LinkedQueue<T>::EnQueue(const T& x)
{ //����Ԫ��x���뵽���еĶ�β  
	if (front == NULL)
	{              //������һ�����          
		front = rear = new LinkNode<T>(x);
		if (front == NULL) 
			return NULL;
	}   //����ʧ��       
	else {                                                        //���в���, ����           
		rear->link = new LinkNode<T>(x);
		if (rear->link == NULL) 
			return NULL;
		rear = rear->link;
	}
}

template<class T>
void LinkedQueue<T>::DeQueue(T& x)
{ //������в��գ�����ͷ������ʽ������ɾȥ       
	while (!IsEmpty()) 
		return NULL;    //�жӿ�      
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
		cout << "����Ϊ��" << endl;
	}
	return  front->link;
}
