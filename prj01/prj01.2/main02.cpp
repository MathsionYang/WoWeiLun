#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *T;
const int N = 5;
//全局变量NUM用来给 i 赋值
int NUM = 0;

struct Node
{
	int i;
	int num;
	T next;
};

//创建空链表
T Creat(T node)
{
	if (node == NULL)
		node = (T)malloc(sizeof(struct Node));
	node->next = NULL;
	node->i = NUM;

	return node;
}

//插入元素
void Inset(T &node, int m)
{
	if (node == NULL)
		node = Creat(node);

	T temp;
	temp = (T)malloc(sizeof(struct Node));
	if (temp == NULL)
		return;

	temp->num = m;
	temp->next = node->next;
	node->next = temp;
	node->next->i = ++NUM;
}

//查找第几个元素
int Find(int num, T node)
{
	T cpynode = node->next;
	//用 i 来定义元素的位置, 直接查找 i 即可
	while (cpynode != NULL && cpynode->i != num)
		cpynode = cpynode->next;

	if (cpynode != NULL)
		return cpynode->num;
	return 0;
}


int main()
{
	int a[N] = { 23,45,76,13,67 };
	T node = NULL;
	int i;
	for (i = 0; i < N; i++)
		Inset(node, a[i]);
	scanf("%d", &i);
	printf("%d", Find(i, node));

	system("pause");
	return 0;
}
