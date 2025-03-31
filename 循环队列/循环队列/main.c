#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
#define eleType int

typedef struct
{
	int data[maxsize];
	int f, r;
}squeue;

void  Initqueue(squeue* q)
{
	q->f = q->r = 0;
}
//入队
void Enqueue(squeue* q, eleType x)
{
	if (q->f == (q->r + 1) % maxsize)
	{
		printf("队满，不能入队\n");
	}
	q->data[q->r] = x;
	q->r = (q->r + 1) % maxsize;
}
//出队
void Dequeue(squeue* q)
{
	if (q->f == q->r)
	{
		printf("队空，不能出队\n");
		return;
	}
	printf("%d\n", q->data[q->f]);
	q->f = (q->f + 1) % maxsize;
}
int main()
{
	squeue q;
	Initqueue(&q);
	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Dequeue(&q);
	Dequeue(&q);
	Enqueue(&q, 4);
	Enqueue(&q, 5);
	Dequeue(&q);
	Dequeue(&q);
	Dequeue(&q);
	Dequeue(&q);

	return 0;
}