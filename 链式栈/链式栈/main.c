#include<stdio.h>
#include<stdlib.h>

#define eleType int 
//���ṹ��
typedef struct stackNode
{
	eleType data;
	struct stackNode* next;
}SNode,*listack;
//��ջ�ĳ�ʼ��
SNode* Initstack()
{
	SNode* s = (SNode*)malloc(sizeof(SNode));
	//if(s==NULL)
	s->next = NULL;
	return s;
}
//��ջ
listack Push(listack top,eleType x)
{
	SNode* s = (SNode*)malloc(sizeof(SNode));
	s->data = x;
	s->next = top->next;
	top->next = s;
	return top;
}
//��ջ
listack Pop(listack top)
{
	if (top->next == NULL)
	{
		printf("��ջ�����ܳ�ջ\n");
		return top;
	}
	SNode* p = top->next;//��Ԫ���
	top->next = p->next;
	free(p);
	p = NULL;
	return top;
}
//�õ�ջ��Ԫ��
eleType Get(listack top)
{
	if (top->next == NULL)
	{
		printf("��ջ��û��ջ��Ԫ��\n");
		return -1;
	}
	return top->next->data;
}

int main()
{
	listack top = Initstack();
	Push(top, 1);
	Push(top, 2);
	Push(top, 3);
	printf("%d\n", Get(top));
	Pop(top);
	Pop(top);
	printf("%d\n", Get(top));
	return 0;
}