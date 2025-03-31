#include<stdio.h>
#include<stdlib.h>
#define maxx 20
//实现一个存放int类型数据的顺序表

typedef struct ArrayList
{
	int* data;//指针模拟开数组
	int size; //记录表中数据的实际个数
}Array;
//顺序表的初始化
  Array InitArray()
   {
	   Array ar;
	   ar.data = (int*)malloc(sizeof(int) * maxx);
	   if (ar.data == NULL)
	   {
		   printf("空间申请失败\n");
		   return ar;
	   }
	   ar.size = 0;
	   return ar;
   }
//末尾插入数据k
Array add(Array a,int k)
{
	if (a.size == maxx)
	{
		printf("顺序表已满，不能插入数据\n");
		return a;
}
	a.data[a.size] = k;
	a.size++;
	return a;
}
//在指定位置插入数据-----保证i合法
Array insert(Array a, int i, int k)
{
	if (a.size == maxx)
	{
		printf("顺序表已满，不能插入数据\n");
		return a;
	}
	//倒着循环移动数据 把i位置空出来
	for(int j=a.size-1;j>=i;j--)
	{
		a.data[j + 1] = a.data[j];
	}
	a.data[i] = k;
	a.size++;
	return a;
}
//查找数据k所在的位置
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
//顺序表的删除
Array delet(Array a, int k)
{
	if (a.size == 0)
	{
		printf("空表，不能执行删除操作\n");
		return a;
	}
	int j = find(a, k);
	if (j == -1)
	{
		printf("被删除数据不存在，不能执行删除操作");
		return a;
	}
	//k存在  进行删除
	for (int i = j; i <= a.size - 2; i++)
	{
		a.data[i] = a.data[i + 1];
	}
	a.size--;
	return a;
}
//顺序表数据更改
Array change(Array a, int k, int y)
{
	if (a.size == 0)
	{
		printf("空表，数据不能被更改");
		return a;
	}
	int j = find(a, k);
	if (j == -1)
	{
		printf("表中没有被更改的数据，更改操作不能执行");
		return a;
	}
	a.data[j] = y;
	return a;
}
//输出  按顺序输出表中的数据
void printff(Array a)
{
	if (a.size == 0)
	{
		printf("空表\n");
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
