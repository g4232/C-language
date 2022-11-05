#include "SList.h"
//单链表的打印
void SListPrint(SListNode* phead)
{
	//assert(phead); - 不需要断言 - 如果为空指针的话就是空链表
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}
//创建一个新的结点
SListNode* BuySListNode(SLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	//对malloc函数返回值的判断
	if (newnode == NULL)
	{
		//printf("malloc fail\n");
		printf("%s\n", strerror(errno)); //报出错误
		exit(-1);  //结束程序
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	return newnode;
}
//单链表的尾插 - 将新创建的结点接到原来链表上去
void SListPushBack(SListNode** pphead, SLDataType x)
{
	assert(pphead);  //pphead - 是头指针的地址

	//创建一个新的结点
	SListNode* newnode = BuySListNode(x);

	if (*pphead == NULL)//空链表的尾插
	{
		*pphead = newnode;
	}
	else              //链接到最后一个结点 遍历(找尾)
	{
		SListNode* tail = *pphead;
		//找尾
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		//将新的头的地址链表最后一个结点里的指针变量。
		//新的结点的头指针和原来链表的尾指针都在堆区。
	}
}
//单链表的头插
void SListPushFront(SListNode** pphead, SLDataType x)
{
	//创建一个新的结点
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;

}
void SListPopBack(SListNode** pphead)
{
	assert(pphead);

	//1.空链表
	//2.一个结点
	//3.多个结点

	//空链表的情况

	//暴力检查 - assert(*pphead != NULL);
	if (*pphead == NULL)//温柔检查
	{
		return;
	}
	//只有一个结点的情况
	else if ((*pphead)->next == NULL)//解引用和箭头的优先级一样高这里要带括号
	{
		free(*pphead);
		*pphead = NULL;
	}
	//多个结点的情况
	else
	{
		SListNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}
//单链表的头删
void SListPopFront(SListNode** pphead)
{
	assert(pphead);

	//1.空
	//2.非空

	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}

}
//单链表的查找
SListNode* SListFind(SListNode* phead, SLDataType x)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}
//在单链表pos位置之前插入数据
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x)
{
	assert(pphead);
	assert(pos);//空链表排除

	//1.pos是第一个结点
	//2.pos不是第一个结点

	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SListNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}
//在单链表pos位置之后插入数据
//方法一:(无关顺序)
//void SListInsertAfter(SListNode* pos, SLDataType x)
//{
//	assert(pos);
//	SListNode* next = pos->next;
//	SListNode* newnode = BuySListNode(x);
//	pos->next = newnode;
//	newnode->next = next;
//
//}

//方法二:(注意顺序)
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//在单链表pos位置删除数据
void SListErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead);
	assert(pos);

	//当传头指针时
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}

}
//在单链表pos后一个位置删除数据(不可能是头删)
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->next;
	if (next != NULL)
	{
		pos->next = pos->next->next;
		free(next);
		next = NULL;
	}
}
//单链表的销毁
void SListDestroy(SListNode** pphead)
{
	assert(pphead);

	//一个一个结点释放
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;

}












