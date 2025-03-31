#include<stdio.h>
#include<stdlib.h>
//双链表的结点结构
typedef struct ListNode
{
	int data;//数据域 
	struct ListNode* next;//指向下一个结点的指针域 
	struct ListNode* pre;//指向上一个结点的指针域
}Node, * Linklist;
//增强可读性//Linklist  等价于 Node*
//Linklist 声明的指针变量 强调该指针指向了一个链表，即该指针上头指针
//Node* 声明的指针变量 强调该指针指向了一个结点
Node* Initlist()
{
	Node* head = (Node*)malloc(sizeof(Node));
	//if(h==NULL)  
	head->pre = head;
	head->next = head;
	return head;
}
//双链表中找到数据x所在的结点 
Node* find(Linklist l, int x)
{
	Node* p = l->next;//从首元结点开始找	
	while (p != l && p->data != x)
	{
		p = p->next;
	}
	return p;
}
//头插法
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
		printf("数据不存在，不能插入\n");
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
		printf("数据不存在，不能删除\n");
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
{//统计链表中数据的个数	
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
	l = Initlist();//建立了一个带头结点的空链表   
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