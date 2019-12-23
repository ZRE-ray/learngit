#include "Remove.h"
#include<iostream>
using namespace std;

Remove::Remove()
{
}

void Remove::removever(int v)
{
	int position = -1; //表示删除顶点在顶点数组中的位置
	edg* p = NULL;
	edg* q = NULL;
	edg* r = NULL;
	cout << "谢孜" << endl;
	//遍历顶点数组，并删除顶点数组中的被删顶点
	for (int i = 0; i < numv; i++)
	{
		if (nodetable[i].data == v)
		{
			position = i;
			p = nodetable[i].head;
			for (int j = i + 1; j < numv; j++)
			{
				nodetable[j - 1].data = nodetable[j].data;
				nodetable[j - 1].head = nodetable[j].head;
			}
			numv--;
			break;
		}
	}
	if (position == -1)
	{
		cout << "不存在数据信息为" << v << "的顶点" << endl;
	}
	else
	{
		//删除被删顶点链接的边信息
		while (p)
		{
			q = p->link;
			delete p;
			p = q;
		}
		//删除其它顶点中与position相关的边结点
		for (int i = 0; i < numv; i++)
		{
			p = nodetable[i].head;
			while (p)
			{
				if (p->dest == position)
				{
					if (p == nodetable[i].head)
					{
						nodetable[i].head = p->link;
					}
					else
					{
						r->link = p->link;
					}
					q = p;
					p = p->link;
					delete q;
				}
				else
				{
					if (p->dest > position)
					{
						p->dest--;
					}
					r = p;
					p = p->link;
				}
			}
		}
	}
}

void Remove::removeedg(int v1, int v2)
{
	int ad1 = -1;
	int ad2 = -1;
	for (int i = 0; i < numv; i++)
	{
		if (nodetable[i].data == v1)
		{
			ad1 = i;
			break;
		}
	}
	for (int i = 0; i < numv; i++)
	{
		if (nodetable[i].data == v2)
		{
			ad2 = i;
			break;
		}
	}
	if (ad1 != -1 && ad2 != -1)
	{
		edg* p = nodetable[ad1].head, * q = NULL, * s = p;
		while (p != NULL && p->dest != ad2)     //v1对应边链表中找被删边               
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{          //找到被删边结点                
			if (p == s)
				nodetable[ad1].head = p->link;  //该结点是边链表首结点              
			else
				q->link = p->link;
			delete p;
		}
		else
			cout << "未找到要删除的边" << endl;	//没有找到被删边结点           
		p = nodetable[ad2].head;
		q = NULL;
		s = p;//v2对应边链表中删除         
		while (p->dest != ad1)      //寻找被删边结点              
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			nodetable[ad2].head = p->link;   //该结点是边链表首结点         
		else
			q->link = p->link;
		delete p;
		nume--;
	}
	//没有找到结点 
}

Remove::~Remove()
{
}
