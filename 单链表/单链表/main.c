#include<stdio.h>
#include<stdlib.h>

#define eleType int 
//创建结点结构体
typedef struct ListNode
{
	eleType data; //数据域
	struct ListNode* next;//指针域  此处为struct ListNode* 类型是因为是指向下一个结点的
}Node,*Linklist;
//单链表的初始化
Linklist Initlist()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("空间申请失败\n");
		return head;
	}
	head->next = NULL;
	return head;
}
//头插法
Linklist Head_insert(Linklist l, eleType k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	s->data = k;
	s->next = l->next;
	l->next = s;
	return l;
}
//尾插法
Linklist Rear_insert(Linklist l, eleType k)
{
	Node* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = NULL;
	p->next = s;
	return l;
}
//查找函数
Node* find(Linklist l,eleType x)
{
	Node* p = l->next;
	while (p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}
//中间位置插入
Linklist insert(Linklist l, eleType x, eleType k)
{
	Node* p = find(l, x);
	if (p == NULL)
	{
		printf("数据不存在，不能执行插入操作\n");
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = p->next;
	p->next = s;
	return l;
}
//统计链表中元素个数
int Get_size(Linklist l)
{
	Node* p = l->next;
	int sum = 0;
	while (p != NULL)
	{
		sum++;
		p = p->next;
	}
	return sum;
}
//修改链表中的元素
Linklist Change(Linklist l, eleType x, eleType y)
{
	Node* p = find(l,x);
	if (p == NULL)
	{
		printf("数据不存在，不能执行修改操作\n");
	}
	p->data = y;
	return l;

}
//删除链表的元素
Linklist Delet(Linklist l, eleType k)
{

	if (l->next == NULL)
	{
		printf("空链表不能执行删除\n");
		return l;
	}
	//删除
	//先找到k以及k前面的结点
	Node* p = l;
	Node* q = l->next;
	while (q != NULL && q->data != k)
	{
		p = q;
		q = q->next;
	}
	if (q == NULL)
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

void printff(Linklist l)
{
	Node* p = l->next;
	while (p != NULL)
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
	l = Change(l, 1, 20);
	l = Change(l, 3, 40);
	printff(l);
	printf("%d\n", Get_size(l));
	return 0;
	
}