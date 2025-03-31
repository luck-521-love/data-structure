#include<stdio.h>
#include<stdlib.h>

#define eleType int 
//结点结构体
typedef struct stackNode
{
	eleType data;
	struct stackNode* next;
}SNode,*listack;
//链栈的初始化
SNode* Initstack()
{
	SNode* s = (SNode*)malloc(sizeof(SNode));
	//if(s==NULL)
	s->next = NULL;
	return s;
}
//入栈
listack Push(listack top,eleType x)
{
	SNode* s = (SNode*)malloc(sizeof(SNode));
	s->data = x;
	s->next = top->next;
	top->next = s;
	return top;
}
//出栈
listack Pop(listack top)
{
	if (top->next == NULL)
	{
		printf("空栈，不能出栈\n");
		return top;
	}
	SNode* p = top->next;//首元结点
	top->next = p->next;
	free(p);
	p = NULL;
	return top;
}
//得到栈顶元素
eleType Get(listack top)
{
	if (top->next == NULL)
	{
		printf("空栈，没有栈顶元素\n");
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