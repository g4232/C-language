#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

typedef int SLDataType;


//单链表结构的基本定义
//逻辑结构
typedef struct SListNode
{
	SLDataType data;//val  -   数据域
	struct SListNode* next;//存储下一个结点的地址    -    指针域
}SListNode, SLN;

//创建单个链表
SListNode* BuySListNode(SLDataType x);
//打印单链表
void SListPrint(SListNode* phead);
//单链表的尾插
void SListPushBack(SListNode** pphead, SLDataType x);
//单链表的头插
void SListPushFront(SListNode** pphead, SLDataType x);
//单链表的尾删
void SListPopBack(SListNode** pphead);
//单链表的头删
void SListPopFront(SListNode** pphead);
//单链表的查找
SListNode* SListFind(SListNode* phead, SLDataType x);
//在单链表pos位置之前插入数据
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x);
//在单链表pos位置之后插入数据
void SListInsertAfter(SListNode* pos, SLDataType x);
//在单链表pos位置删除数据
void SListErase(SListNode** pphead, SListNode* pos);
//在单链表pos后一个位置删除数据
void SListEraseAfter(SListNode* pos);
//单链表的销毁
void SListDestroy(SListNode** pphead);
