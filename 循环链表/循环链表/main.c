#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {  //链表结点
	int data;
	struct Node* next;
}Node, * Linklist;          //用Linklist 为了增强代码可读性 可以叫我们知道是指向链表的 
// Linklist是数据类型 是结构体指针数据类型等价于Node*


Linklist Initlist()
{ //初始化一个带头结点点空链表
	/*
	Node head;   错误代码 原因是Node head 内存在栈区 代码执行完会被回收掉 使l指针成为野指针
	head.next = NULL;
	return &head;
	*/
	Node* head = (Node*)malloc(sizeof(Node)); //指针head指向了通过malloc申请的空间
	//if(head==NULL)   为了严谨可以判断malloc是否申请成功
	//{
	// printf("内存申请失败\n");
	// return NULL;
	// }
	head->next = head;
	return head;
}
//头插法
Linklist Head_insert(Linklist l, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	s->data = k;
	s->next = l->next;
	l->next = s;
	return l;
}
//尾插法
Linklist Rear_insert(Linklist l, int k)
{
	//找尾结点
	Node* p = l;//从头结点开始遍历
	while (p->next != l)
	{
		p = p->next;
	}
	//p此时指向尾结点
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = l;
	//s插入到p后面
	p->next = s;
	return l;
}
//在链表中找到数据x所在的结点
Node* find(Linklist l, int x)
{
	Node* p = l->next;//从首元结点开始找
	while (p != l && p->data != x)
	{
		p = p->next;
	}
	return p;
}
//在数据x后插入数据k
Linklist insert(Linklist l, int x, int k)
{
	Node* p = find(l, x);
	if (p == l)
	{
		printf("数据不存在，不能插入\n");
		return l;
	}
	else
	{   //插入
		Node* s = (Node*)malloc(sizeof(Node));
		//if(s==NULL)
		s->data = k;
		s->next = p->next;
		p->next = s;
		return l;
	}

}
Linklist Delet(Linklist l, int k)
{
	if (l->next ==l)
	{
		printf("空链表不能执行删除\n");
		return l;
	}
	//删除
	//先找到k以及k前面的结点
	Node* p = l;
	Node* q = l->next;
	while (q != l && q->data != k)
	{
		p = q;
		q = q->next;
	}
	if (q ==l)
	{
		printf("要删除的数据不存在\n");
		return l;
	}
	//q指向k所在的结点
	//p是q前面的结点
	p->next = q->next;
	free(q);
	q = NULL;//防止q成为野指针

	return l;
}

/*
Node* p = l;
while (p->next != NULL && p->next->data != k)
{
	p = p->next;
}
p->next = NULL;  不存在
	p->next != NULL;   q=p->next 删除
*/

//链表的修改 把数据x改成数据k
Linklist change(Linklist l, int x, int k)
{
	Node* p = find(l, x);
	if (p == l)
	{
		printf("数据不存在，不能执行修改操作\n");
		return l;
	}
	p->data = k;
	return l;
}
// 统计链表中数据的个数    数据的个数比结点的个数少一个（带头结点）
int get_size(Linklist l)
{
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
	}
	printf("\n");
}


int main()
{
	Linklist l = NULL;
	l = Initlist();// 头结点的地址赋值给了头指针l  头指针l指向了头结点; 不带头结点的就把这行注释掉
	l = Head_insert(l, 3);
	l = Head_insert(l, 2);
	l = Head_insert(l, 1);
	printff(l);
	l = Rear_insert(l, 4);
	l = Rear_insert(l, 5);
	l = Rear_insert(l, 6);
	printff(l);
	l = insert(l, 4, 9);
	l = insert(l, 5, 19);
	printff(l);
	l = Delet(l, 10);
	l = Delet(l, 5);
	printff(l);
	l = change(l, 1, 20);
	l = change(l, 3, 40);
	printff(l);
	printf("%d\n", get_size(l));
	return 0;
}