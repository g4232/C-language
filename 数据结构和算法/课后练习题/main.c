#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Sqlist
{
	int* data;
	int length;
}Sqlist;
void PrintList(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->data[i]);
	}
}
void InitList(Sqlist* L) {
	L->data = (int*)malloc(sizeof(int) * 10);
	L->length = 0;
	if (L->data)
	{
		for (int i = 0; i < 10; i++)
		{
			L->data[i] = rand()%10+1;
			L->length++;
		}
			L->data[5] = 7;
	}
}
int Delete_Same(Sqlist* L) {
	if (L->length==0)
	{
		return 0;
	}
	int i=0, j=1;
	for (int i = 0,j=1; j <L->length; j++)
	{
		if (L->data[i]!=L->data[j])
		{
			printf("%d---%d\n",L->data[i],L->data[j]);
			L->data[++i] = L->data[j];
		}
	}
	L->length = i + 1;
	return 1;
}
//第二章 01 删除并返回最小的值
int Delete_Mix(Sqlist* L) {
	int mix = L->data[0];
	if (L->length==0)
	{
		printf("该顺序表为空!!");
	}
	for (size_t i = 1; i < L->length; i++)
	{
		if (L->data[i]<mix)
		{
			mix = L->data[i];
		}
	}
	return mix;

}
//      02 反转顺序表元素
void Reserve_List(Sqlist* L) {
	int i = 0, j = L->length-1;
	for (size_t i = 0; i < j; i++)
	{
		int middle = 0;
		middle = L->data[i];
		L->data[i] = L->data[j];
		L->data[j] = middle;
		j--;
	}


}
//      03 删除指定值的元素 O(n)时间复杂度
void Delete_assign(int data,Sqlist* L) {
	int flag = 0;
	for (size_t i = 0; i < L->length; i++)
	{
		if (L->data[i] == data)
		{
			printf("找到元素 --> %d \n",L->data[i]);
			int j = i;
			for (int j = i; j < L->length; j++)
			{
				L->data[j] = L->data[j + 1];
			}
				L->length-=1;
				i--;
		}
	}

}

int main() {
	srand((unsigned)time(NULL));
	Sqlist list;
	InitList(&list);
	//Reserve_List(&list);
	PrintList(&list);
	list.data[3] = 2;
	Delete_assign(2, &list);
	printf("-------------\n");
	PrintList(&list);
	return 0;
}