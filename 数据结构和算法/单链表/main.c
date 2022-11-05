#pragma once
#define InitSize 5 
#include <stdio.h>
#include "SList.h"
#include <stdlib.h>
typedef struct Lnode {
	int data;
	struct Lnode* next;
} Lnode,*LinkList;
SListNode* InitNode() {
	SListNode*	L = (SListNode*)malloc(sizeof(SListNode));
	if (L==NULL)
	{
		perror("InitNodeError");
	
	}
	else {
	L->data = 0;
	L->next = NULL;
	return L;
	}
}
void CreateNode(SListNode* L) {
	int size = InitSize;
	for (int i = 0; i < size ;  i++)
	{
		Lnode*s = (Lnode*)malloc(sizeof(Lnode));
		if (s!=NULL)
		{
			s->data = i;	
			L->next = s;
			L = L->next;
		}
	}
	 L->next = NULL;
}
void InsertNode(LinkList L, int pos, int data) {
	if (pos<1) return ;
	Lnode* p;
	int j = 0;
	p = L;
	while (p!=NULL && j<pos-1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) perror("p==NULL");
	Lnode* s = (Lnode*)malloc(sizeof(Lnode));
	if (s!=NULL&&p!=NULL)
	{
		s->data = data;
		s->next = p->next;
		p->next = s;
		printf("%d 插入成功,位置 %d\n",data,pos);
	}
}
void Print(SListNode* L) {
	while (L!=NULL)
	{
		printf("%d=>",L->data);
		L = L->next;
	}
}
int main() {
	SListNode* L= InitNode();

	//for (int i = 0; i < 10; i++)
	//{
	//	SListPushFront(&L,i);
	//}
	CreateNode(L);
	Print(L);
	SListDestroy(&L);
	return 0;

}
