#include<stdio.h>
#include<stdlib.h>
typedef struct qnode {
    int data;
    struct qnode* next;

}QNode;

typedef struct linkqueue {
    QNode* f;
    QNode* r;
}Queue;
Queue* Initqueue()
{
    Queue* s = (Queue*)malloc(sizeof(Queue));
    //if(s==NULL)
    s->f = (QNode*)malloc(sizeof(QNode));
    s->f->next = NULL;
    s->r = s->f;
    return s;
}
//入队
Queue* Enqueue(Queue* q, int k)
{
    QNode* s = (QNode*)malloc(sizeof(QNode));
    //if(s==NULL)
    s->data = k;
    s->next = q->r->next;
    q->r->next = s;
    q->r = s;
    return q;

}
//出队
Queue* Dequeue(Queue* q)
{
    if (q->f->next == NULL)
    {
        printf("队空，不能出队\n");
        return q;
    }
    QNode* p = q->f->next;
    q->f->next = p->next;
    printf("%d\n", p->data);
    free(p);
    p = NULL;
    if (q->f->next == NULL)
    {
        q->r = q->f;
    }
    return q;
}
int main()
{
    Queue* q = Initqueue();
   q=Enqueue(q, 1);
   q=Enqueue(q, 2);
   q=Enqueue(q, 3);
   q=Dequeue(q);
   q=Dequeue(q);
   q=Enqueue(q, 4);
   q=Enqueue(q, 5);
   q=Dequeue(q);
   q=Dequeue(q);
   q=Dequeue(q);
   q=Dequeue(q);

    return 0;
}
