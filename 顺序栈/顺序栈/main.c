#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

typedef struct {
	int* data;//ָ��ģ�⿪����
	int top;//ջ��ָ��
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
		printf("ջ����������ջ\n");
		return;
	}
	s->top++;
	s->data[s->top] = k;
	return;
 }
//�п�
int Empty(sstack* s)
{
	if (s->top == -1) {
		return 1;//��ջ
	}
	else return 0;//�ǿ�

}
void Pop(sstack* s)
{
	if (Empty(s))
	{
		printf("��ջ�����ܳ�ջ\n");
		return;
	}
	s->top--;
}

int Get(sstack s)
{
	if (Empty(&s))
	{
		printf("��ջ��û��ջ��Ԫ��\n");
		return -1;//����ջ�������ǷǸ���
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