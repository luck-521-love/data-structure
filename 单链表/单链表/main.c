#include<stdio.h>
#include<stdlib.h>

#define eleType int 
//�������ṹ��
typedef struct ListNode
{
	eleType data; //������
	struct ListNode* next;//ָ����  �˴�Ϊstruct ListNode* ��������Ϊ��ָ����һ������
}Node,*Linklist;
//������ĳ�ʼ��
Linklist Initlist()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("�ռ�����ʧ��\n");
		return head;
	}
	head->next = NULL;
	return head;
}
//ͷ�巨
Linklist Head_insert(Linklist l, eleType k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	s->data = k;
	s->next = l->next;
	l->next = s;
	return l;
}
//β�巨
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
//���Һ���
Node* find(Linklist l,eleType x)
{
	Node* p = l->next;
	while (p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}
//�м�λ�ò���
Linklist insert(Linklist l, eleType x, eleType k)
{
	Node* p = find(l, x);
	if (p == NULL)
	{
		printf("���ݲ����ڣ�����ִ�в������\n");
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = p->next;
	p->next = s;
	return l;
}
//ͳ��������Ԫ�ظ���
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
//�޸������е�Ԫ��
Linklist Change(Linklist l, eleType x, eleType y)
{
	Node* p = find(l,x);
	if (p == NULL)
	{
		printf("���ݲ����ڣ�����ִ���޸Ĳ���\n");
	}
	p->data = y;
	return l;

}
//ɾ�������Ԫ��
Linklist Delet(Linklist l, eleType k)
{

	if (l->next == NULL)
	{
		printf("��������ִ��ɾ��\n");
		return l;
	}
	//ɾ��
	//���ҵ�k�Լ�kǰ��Ľ��
	Node* p = l;
	Node* q = l->next;
	while (q != NULL && q->data != k)
	{
		p = q;
		q = q->next;
	}
	if (q == NULL)
	{
		printf("Ҫɾ�������ݲ�����\n");
		return l;
	}
	//qָ��k���ڵĽ��
	//p��qǰ��Ľ��
	p->next = q->next;
	free(q);
	q = NULL;//��ֹq��ΪҰָ��

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
	l = Initlist();// ͷ���ĵ�ַ��ֵ����ͷָ��l  ͷָ��lָ����ͷ���; ����ͷ���ľͰ�����ע�͵�
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