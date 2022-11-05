#include <stdio.h>
#include <stdlib.h>
typedef struct Sqlist
{
	int* data;
	int length;
}Sqlist;
void PrintList(Sqlist* L) {
	for (int i = 0; i < 10; i++)
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
			L->data[i] = i;
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
int main() {
	Sqlist list;
	InitList(&list);
	Delete_Same(&list);
	PrintList(&list);
	return 0;
}