#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int NUM = 0;
typedef struct LNode
{
	
	int data;
	struct LNode *next;
}LNode;
//���뺯��
LNode *input(int n)
{
	LNode *head, *tail, *p;
	head = (LNode*)malloc(sizeof(LNode));
	tail = head;
	for (int i = 0; i <= n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));

		p->data = 'a' + i;
		
		tail->next = p;
		tail = p;
		tail->next = NULL;
		
	}
	return head;
}
LNode *input1(int n)
{
	LNode *head, *tail, *p;
	head = (LNode*)malloc(sizeof(LNode));
	tail = head;
	for (int i = 0; i <= n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->data = 'z' - i;
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	return head;
}
void output(LNode *head)
{
	LNode *p;
	p = head->next;
	printf("��ӡ��¼\n ");
	while (p)
	{
		
		printf("%c", p->data);
		p = p->next;
		if (p)
			printf(" ");
		else
			printf("\n");
	}
}
int Find(int num, LNode *head)
{
	LNode *h;
	int result;
    h = head->next;
	//�� i ������Ԫ�ص�λ��, ֱ�Ӳ��� i ����
	int j = 1;
	while (h&&j<num)
	{
		h = h->next;
		j += 1;
	}
	if (!h||j>num)
	{
		return 0;
	}
	result = h->data;
	printf("%c", result);
	
}
int main()
{
	LNode *head, *head1;
	
	int n = 'z' - 'a';
	//����
	head = input(n);
	output(head);
	//����
	head1 = input1(n);
	output(head1);

	LNode *f1;
	f1 = input(n);
	
	//��ӡcug
	printf("�й����ʴ�ѧ:");
	Find(3,f1);//c
	Find(21, f1);//u
	Find(7, f1);//g
	printf("\n");

	system("pause");
	return 0;

}
