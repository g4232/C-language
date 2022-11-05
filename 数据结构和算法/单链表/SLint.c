#include "SList.h"
//������Ĵ�ӡ
void SListPrint(SListNode* phead)
{
	//assert(phead); - ����Ҫ���� - ���Ϊ��ָ��Ļ����ǿ�����
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}
//����һ���µĽ��
SListNode* BuySListNode(SLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	//��malloc��������ֵ���ж�
	if (newnode == NULL)
	{
		//printf("malloc fail\n");
		printf("%s\n", strerror(errno)); //��������
		exit(-1);  //��������
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	return newnode;
}
//�������β�� - ���´����Ľ��ӵ�ԭ��������ȥ
void SListPushBack(SListNode** pphead, SLDataType x)
{
	assert(pphead);  //pphead - ��ͷָ��ĵ�ַ

	//����һ���µĽ��
	SListNode* newnode = BuySListNode(x);

	if (*pphead == NULL)//�������β��
	{
		*pphead = newnode;
	}
	else              //���ӵ����һ����� ����(��β)
	{
		SListNode* tail = *pphead;
		//��β
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		//���µ�ͷ�ĵ�ַ�������һ��������ָ�������
		//�µĽ���ͷָ���ԭ�������βָ�붼�ڶ�����
	}
}
//�������ͷ��
void SListPushFront(SListNode** pphead, SLDataType x)
{
	//����һ���µĽ��
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;

}
void SListPopBack(SListNode** pphead)
{
	assert(pphead);

	//1.������
	//2.һ�����
	//3.������

	//����������

	//������� - assert(*pphead != NULL);
	if (*pphead == NULL)//������
	{
		return;
	}
	//ֻ��һ���������
	else if ((*pphead)->next == NULL)//�����úͼ�ͷ�����ȼ�һ��������Ҫ������
	{
		free(*pphead);
		*pphead = NULL;
	}
	//����������
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
//�������ͷɾ
void SListPopFront(SListNode** pphead)
{
	assert(pphead);

	//1.��
	//2.�ǿ�

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
//������Ĳ���
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
//�ڵ�����posλ��֮ǰ��������
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x)
{
	assert(pphead);
	assert(pos);//�������ų�

	//1.pos�ǵ�һ�����
	//2.pos���ǵ�һ�����

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
//�ڵ�����posλ��֮���������
//����һ:(�޹�˳��)
//void SListInsertAfter(SListNode* pos, SLDataType x)
//{
//	assert(pos);
//	SListNode* next = pos->next;
//	SListNode* newnode = BuySListNode(x);
//	pos->next = newnode;
//	newnode->next = next;
//
//}

//������:(ע��˳��)
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//�ڵ�����posλ��ɾ������
void SListErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead);
	assert(pos);

	//����ͷָ��ʱ
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
//�ڵ�����pos��һ��λ��ɾ������(��������ͷɾ)
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
//�����������
void SListDestroy(SListNode** pphead)
{
	assert(pphead);

	//һ��һ������ͷ�
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;

}












