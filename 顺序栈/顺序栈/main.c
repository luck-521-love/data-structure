#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

typedef struct {
	int* data;//指针模拟开数组
	int top;//栈顶指针
}sstack;
sstack Initsatck()
{
	sstack s;
	s.data = (int*)malloc(sizeof(int) * maxsize);
	s.top = -1;
	return s;
}
void Push(sstack* s, int k)
{
	if (s->top == maxsize - 1)
	{
		printf("栈满，不能入栈\n");
		return;
	}
	s->top++;
	s->data[s->top] = k;
	return;
 }
//判空
int Empty(sstack* s)
{
	if (s->top == -1) {
		return 1;//空栈
	}
	else return 0;//非空

}
void Pop(sstack* s)
{
	if (Empty(s))
	{
		printf("空栈，不能出栈\n");
		return;
	}
	s->top--;
}

int Get(sstack s)
{
	if (Empty(&s))
	{
		printf("空栈，没有栈顶元素\n");
		return -1;//假设栈中数据是非负的
	}
	return s.data[s.top];
}

int main()
{
	sstack s = Initsatck();
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	printf("%d\n", Get(s));
	Push(&s, 16);
	printf("%d\n", Get(s));
	Pop(&s);
	Pop(&s);
	printf("%d\n", Get(s));
}