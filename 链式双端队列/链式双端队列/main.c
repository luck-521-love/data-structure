#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* l = NULL;
Node* r = NULL;
void Initqueue()
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	l = r = s;
}
//������
void Insert_l(int k) 
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	s->data = k;
	l->pre = s;
	s->next = l;
	s->pre = NULL;

	l = s;
}

//��߳���
void Delet_l()
{
	if (l == r)
	{
		printf("�ն��У����ܳ���\n");
		return;
	}
	Node* p = l;
	l = l->next;
	l->pre = NULL;
	free(p);
	p = NULL;
}

//�ұ����
void Insert_r(int k)
{
	r->data = k;
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	r->next = s;
	s->pre = r;
	r = s;
}
//�ұ߳���
void Delet_r()
{
	if (l == r)
	{
		printf("�ն��У����ܳ�ջ\n");
		return;
	}
	printf("�ұ߳��ӵ�������%d\n", r->pre->data);
	Node* p = r;
	r = r->pre;
	r->next = NULL;
	free(p);
	p = NULL;
}

void pri()
{
	Node* p = l;
	while (p != r)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Initqueue();
	Insert_l(1);
	Insert_l(2);
	Insert_r(3);
	Insert_l(4);
	Insert_r(5);
	pri();
	Delet_l();
	Delet_r();
	Delet_r();
	Delet_r();
	pri();
}