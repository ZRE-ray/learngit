#include "Remove.h"
#include<iostream>
using namespace std;

Remove::Remove()
{
}

void Remove::removever(int v)
{
	int position = -1; //��ʾɾ�������ڶ��������е�λ��
	edg* p = NULL;
	edg* q = NULL;
	edg* r = NULL;
	cout << "л��" << endl;
	//�����������飬��ɾ�����������еı�ɾ����
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
		cout << "������������ϢΪ" << v << "�Ķ���" << endl;
	}
	else
	{
		//ɾ����ɾ�������ӵı���Ϣ
		while (p)
		{
			q = p->link;
			delete p;
			p = q;
		}
		//ɾ��������������position��صı߽��
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
		while (p != NULL && p->dest != ad2)     //v1��Ӧ���������ұ�ɾ��               
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{          //�ҵ���ɾ�߽��                
			if (p == s)
				nodetable[ad1].head = p->link;  //�ý���Ǳ������׽��              
			else
				q->link = p->link;
			delete p;
		}
		else
			cout << "δ�ҵ�Ҫɾ���ı�" << endl;	//û���ҵ���ɾ�߽��           
		p = nodetable[ad2].head;
		q = NULL;
		s = p;//v2��Ӧ��������ɾ��         
		while (p->dest != ad1)      //Ѱ�ұ�ɾ�߽��              
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			nodetable[ad2].head = p->link;   //�ý���Ǳ������׽��         
		else
			q->link = p->link;
		delete p;
		nume--;
	}
	//û���ҵ���� 
}

Remove::~Remove()
{
}
