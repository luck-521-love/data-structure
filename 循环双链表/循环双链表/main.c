#include<stdio.h>
#include<stdlib.h>
//˫����Ľ��ṹ
typedef struct ListNode
{
	int data;//������ 
	struct ListNode* next;//ָ����һ������ָ���� 
	struct ListNode* pre;//ָ����һ������ָ����
}Node, * Linklist;
//��ǿ�ɶ���//Linklist  �ȼ��� Node*
//Linklist ������ָ����� ǿ����ָ��ָ����һ����������ָ����ͷָ��
//Node* ������ָ����� ǿ����ָ��ָ����һ�����
Node* Initlist()
{
	Node* head = (Node*)malloc(sizeof(Node));
	//if(h==NULL)  
	head->pre = head;
	head->next = head;
	return head;
}
//˫�������ҵ�����x���ڵĽ�� 
Node* find(Linklist l, int x)
{
	Node* p = l->next;//����Ԫ��㿪ʼ��	
	while (p != l && p->data != x)
	{
		p = p->next;
	}
	return p;
}
//ͷ�巨
Linklist Head_insert(Linklist l, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	//s==NULL   
	s->data = k;
	s->next = l->next;
	l->next->pre = s;
	l->next = s;
	s->pre = l;
	return l;
}
Linklist Rear_insert(Linklist l, int k)
{
	Node* p = l;
	while (p->next != l)
	{
		p = p->next;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	//s==NULL  
	s->data = k;
	s->next = p->next;
	p->next = s;
	s->pre = p;
	return l;
}
Linklist insert(Linklist l, int x, int k)
{
	Node* p = find(l, x);
	if (p == l)
	{
		printf("���ݲ����ڣ����ܲ���\n");
		return l;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	//s==NULL   
	s->data = k;
	s->next = p->next;
	p->next->pre = s;
	p->next = s;
	s->pre = p;
	return l;
}
Linklist Delet(Linklist l, int k)
{
	Node* p = find(l, k);
	if (p == l)
	{
		printf("���ݲ����ڣ�����ɾ��\n");
		return l;
	}
	/*Node* x=p->pre;
	Node* y=p->next;
	x->next=y;
	if(y!=NULL)
	{
	y->pre=x;
	}   */
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
	p = NULL;
	return l;
}
int get_size(Linklist l)
{//ͳ�����������ݵĸ���	
	Node* p = l->next;
	int sum = 0;	
	while (p != l)
	{
		sum++;
		p = p->next;
	}
	return sum;
}
void printff(Linklist l)
{
	Node* p = l->next;
	while (p != l)
	{
		printf("%d ", p->data);
		p = p->next;
	}	printf("\n");
}
int main() {
	Linklist l = NULL;
	l = Initlist();//������һ����ͷ���Ŀ�����   
	l = Head_insert(l, 3);
	l = Head_insert(l, 2);
	l = Head_insert(l, 1);
	printff(l);
	l = Rear_insert(l, 7);
	l = Rear_insert(l, 8);
	printff(l);
	l = insert(l, 2, 11);
	l = insert(l, 8, 12);
	printff(l);
	l = Delet(l, 3);
	l = Delet(l, 12);
	printff(l);
	printf("%d\n", get_size(l));
	printf("%d\n", l->pre->data);
	return 0;
}