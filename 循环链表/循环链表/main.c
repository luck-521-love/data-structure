#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {  //������
	int data;
	struct Node* next;
}Node, * Linklist;          //��Linklist Ϊ����ǿ����ɶ��� ���Խ�����֪����ָ������� 
// Linklist���������� �ǽṹ��ָ���������͵ȼ���Node*


Linklist Initlist()
{ //��ʼ��һ����ͷ���������
	/*
	Node head;   ������� ԭ����Node head �ڴ���ջ�� ����ִ����ᱻ���յ� ʹlָ���ΪҰָ��
	head.next = NULL;
	return &head;
	*/
	Node* head = (Node*)malloc(sizeof(Node)); //ָ��headָ����ͨ��malloc����Ŀռ�
	//if(head==NULL)   Ϊ���Ͻ������ж�malloc�Ƿ�����ɹ�
	//{
	// printf("�ڴ�����ʧ��\n");
	// return NULL;
	// }
	head->next = head;
	return head;
}
//ͷ�巨
Linklist Head_insert(Linklist l, int k)
{
	Node* s = (Node*)malloc(sizeof(Node));
	//if(s==NULL)
	s->data = k;
	s->next = l->next;
	l->next = s;
	return l;
}
//β�巨
Linklist Rear_insert(Linklist l, int k)
{
	//��β���
	Node* p = l;//��ͷ��㿪ʼ����
	while (p->next != l)
	{
		p = p->next;
	}
	//p��ʱָ��β���
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = k;
	s->next = l;
	//s���뵽p����
	p->next = s;
	return l;
}
//���������ҵ�����x���ڵĽ��
Node* find(Linklist l, int x)
{
	Node* p = l->next;//����Ԫ��㿪ʼ��
	while (p != l && p->data != x)
	{
		p = p->next;
	}
	return p;
}
//������x���������k
Linklist insert(Linklist l, int x, int k)
{
	Node* p = find(l, x);
	if (p == l)
	{
		printf("���ݲ����ڣ����ܲ���\n");
		return l;
	}
	else
	{   //����
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
		printf("��������ִ��ɾ��\n");
		return l;
	}
	//ɾ��
	//���ҵ�k�Լ�kǰ��Ľ��
	Node* p = l;
	Node* q = l->next;
	while (q != l && q->data != k)
	{
		p = q;
		q = q->next;
	}
	if (q ==l)
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

/*
Node* p = l;
while (p->next != NULL && p->next->data != k)
{
	p = p->next;
}
p->next = NULL;  ������
	p->next != NULL;   q=p->next ɾ��
*/

//������޸� ������x�ĳ�����k
Linklist change(Linklist l, int x, int k)
{
	Node* p = find(l, x);
	if (p == l)
	{
		printf("���ݲ����ڣ�����ִ���޸Ĳ���\n");
		return l;
	}
	p->data = k;
	return l;
}
// ͳ�����������ݵĸ���    ���ݵĸ����Ƚ��ĸ�����һ������ͷ��㣩
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
	l = change(l, 1, 20);
	l = change(l, 3, 40);
	printff(l);
	printf("%d\n", get_size(l));
	return 0;
}