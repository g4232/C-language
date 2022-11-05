#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}ListNode;
ListNode* Createlist() {
	ListNode* headNode = (ListNode*)malloc(sizeof(ListNode));
	if (headNode!=NULL)
	{
		headNode->next = NULL;
		return headNode;
	}
}
void PrintList(ListNode* headNode) {
	ListNode* pMove = headNode->next;
	while (pMove)
	{
		printf("%d\n",pMove->data);
		pMove = pMove->next;
	}
	}
ListNode* createNode(int data) {

	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertNode(ListNode* headNode,int s) {
	ListNode* newNode = createNode(s);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void DeleteNode(ListNode* L,int data) {
	ListNode* posNode = L->next;
	ListNode* preNode = L;
	while (posNode->data != data & &posNode!=NULL) {
		preNode = posNode;
		posNode = posNode->next;
		if (posNode==NULL)
		{
			printf("未找到指定位置");
			return;
		}
	}
	preNode->next = posNode->next;
	free(posNode);
}
void main1() {
	ListNode* list = Createlist();
	for ( int i = 0; i < 100; i++)
	{
		insertNode(list, i);
	}
	//DeleteNode(list, 10);
	PrintList(list);

}