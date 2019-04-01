#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *T;
const int N = 5;
//ȫ�ֱ���NUM������ i ��ֵ
int NUM = 0;

struct Node
{
	int i;
	int num;
	T next;
};

//����������
T Creat(T node)
{
	if (node == NULL)
		node = (T)malloc(sizeof(struct Node));
	node->next = NULL;
	node->i = NUM;

	return node;
}

//����Ԫ��
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

//���ҵڼ���Ԫ��
int Find(int num, T node)
{
	T cpynode = node->next;
	//�� i ������Ԫ�ص�λ��, ֱ�Ӳ��� i ����
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
