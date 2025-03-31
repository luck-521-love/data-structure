#include<stdio.h>
#include<stdlib.h>
#define maxx 20
//ʵ��һ�����int�������ݵ�˳���

typedef struct ArrayList
{
	int* data;//ָ��ģ�⿪����
	int size; //��¼�������ݵ�ʵ�ʸ���
}Array;
//˳���ĳ�ʼ��
  Array InitArray()
   {
	   Array ar;
	   ar.data = (int*)malloc(sizeof(int) * maxx);
	   if (ar.data == NULL)
	   {
		   printf("�ռ�����ʧ��\n");
		   return ar;
	   }
	   ar.size = 0;
	   return ar;
   }
//ĩβ��������k
Array add(Array a,int k)
{
	if (a.size == maxx)
	{
		printf("˳������������ܲ�������\n");
		return a;
}
	a.data[a.size] = k;
	a.size++;
	return a;
}
//��ָ��λ�ò�������-----��֤i�Ϸ�
Array insert(Array a, int i, int k)
{
	if (a.size == maxx)
	{
		printf("˳������������ܲ�������\n");
		return a;
	}
	//����ѭ���ƶ����� ��iλ�ÿճ���
	for(int j=a.size-1;j>=i;j--)
	{
		a.data[j + 1] = a.data[j];
	}
	a.data[i] = k;
	a.size++;
	return a;
}
//��������k���ڵ�λ��
int find(Array a, int k)
{
	for (int i = 0; i <= a.size - 1; i++) {
		if (a.data[i] == k)
		{
			return i;
		}
	}
	return -1;
}
//˳����ɾ��
Array delet(Array a, int k)
{
	if (a.size == 0)
	{
		printf("�ձ�����ִ��ɾ������\n");
		return a;
	}
	int j = find(a, k);
	if (j == -1)
	{
		printf("��ɾ�����ݲ����ڣ�����ִ��ɾ������");
		return a;
	}
	//k����  ����ɾ��
	for (int i = j; i <= a.size - 2; i++)
	{
		a.data[i] = a.data[i + 1];
	}
	a.size--;
	return a;
}
//˳������ݸ���
Array change(Array a, int k, int y)
{
	if (a.size == 0)
	{
		printf("�ձ����ݲ��ܱ�����");
		return a;
	}
	int j = find(a, k);
	if (j == -1)
	{
		printf("����û�б����ĵ����ݣ����Ĳ�������ִ��");
		return a;
	}
	a.data[j] = y;
	return a;
}
//���  ��˳��������е�����
void printff(Array a)
{
	if (a.size == 0)
	{
		printf("�ձ�\n");
		return;
	}
	for (int i = 0; i < a.size; i++)
	{
		printf("%d ", a.data[i]);
		
	}
	printf("\n");
}

int main() 
{
	Array a;
	a = InitArray();
	a = add(a, 8);
	a = add(a, 9);
	a = insert(a, 0, 10);
	
	printff(a);
	return 0;
}
