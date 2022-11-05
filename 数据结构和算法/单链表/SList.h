#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

typedef int SLDataType;


//������ṹ�Ļ�������
//�߼��ṹ
typedef struct SListNode
{
	SLDataType data;//val  -   ������
	struct SListNode* next;//�洢��һ�����ĵ�ַ    -    ָ����
}SListNode, SLN;

//������������
SListNode* BuySListNode(SLDataType x);
//��ӡ������
void SListPrint(SListNode* phead);
//�������β��
void SListPushBack(SListNode** pphead, SLDataType x);
//�������ͷ��
void SListPushFront(SListNode** pphead, SLDataType x);
//�������βɾ
void SListPopBack(SListNode** pphead);
//�������ͷɾ
void SListPopFront(SListNode** pphead);
//������Ĳ���
SListNode* SListFind(SListNode* phead, SLDataType x);
//�ڵ�����posλ��֮ǰ��������
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x);
//�ڵ�����posλ��֮���������
void SListInsertAfter(SListNode* pos, SLDataType x);
//�ڵ�����posλ��ɾ������
void SListErase(SListNode** pphead, SListNode* pos);
//�ڵ�����pos��һ��λ��ɾ������
void SListEraseAfter(SListNode* pos);
//�����������
void SListDestroy(SListNode** pphead);
