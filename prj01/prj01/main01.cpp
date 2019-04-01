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
//输入函数
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
	printf("打印记录\n ");
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
	//用 i 来定义元素的位置, 直接查找 i 即可
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
	//正序
	head = input(n);
	output(head);
	//倒序
	head1 = input1(n);
	output(head1);

	LNode *f1;
	f1 = input(n);
	
	//打印cug
	printf("中国地质大学:");
	Find(3,f1);//c
	Find(21, f1);//u
	Find(7, f1);//g
	printf("\n");

	system("pause");
	return 0;

}
