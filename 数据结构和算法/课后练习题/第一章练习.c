#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "index.h"
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
void Sort(Sqlist* L1) {
	for (size_t i = 0; i < L1->length; i++)
	{
		for (size_t j = i+1; j < L1->length; j++)
		{
			if (L1->data[j]>L1->data[i])
			{
				int middle = L1->data[i];
				L1->data[i] = L1->data[j];
				L1->data[j] = middle;
			}
		}
	}
}
void InitList(Sqlist* L) {
	L->data = (int*)malloc(sizeof(int) * 30);
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
//�ڶ��� 01 ɾ����������С��ֵ
int Delete_Mix(Sqlist* L) {
	int mix = L->data[0];
	if (L->length==0)
	{
		printf("��˳���Ϊ��!!");
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
//      02 ��ת˳���Ԫ��
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
//      03 ɾ��ָ��ֵ��Ԫ�� O(n)ʱ�临�Ӷ�
void Delete_assign(int data,Sqlist* L) {
	int flag = 0;
	for (size_t i = 0; i < L->length; i++)
	{
		if (L->data[i] == data)
		{
			printf("�ҵ�Ԫ�� --> %d \n",L->data[i]);
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
//      04 ɾ��s-t֮���Ԫ�ز����s-t�ĺϷ���
void Delete_s_t(int s,int t,Sqlist* L) {
	if (s>t || s<0 || t>L->length)
	{
		perror("s or t is not assert!!");
	}
	int loop = t - s + 1;
	for (size_t i = s; loop <L->length ; i++)
	{
		L->data[i] = L->data[i + 3];
		}
	L->length -= loop;
}
//      07 ����������˳���ϲ�Ϊһ���µ�����˳����������µ�˳���
int migate_List(Sqlist* A,Sqlist* B,Sqlist* C) {
	if (A->length+B->length>C->length)
	{
		return 0;
	}
	int i = 0, j = 0, k = 0;
	while (i < A->length && j < B->length) {
		if (A->data[i]<=B->length)
		{
			C->data[k++] = A->data[i];
		}
		else
		{
			C->data[k++] = B->data[j];
		}
		while (i<A->length)
		{
			C->data[k++] = A->data[i++];
		}
		while (j < B->length)
		{
			C->data[k++] = B->data[j++];
		}
		C->length = k;
		return 1;
	}
	
}
//      08 ���������Ա��Ԫ�ؽ��л���
void Exchange_List(Sqlist* L1,Sqlist* L2) {
	int data[20];
	for (int i = 0; i < 20; i++)
	{
		if (i<10)
		{
			data[i] = L1->data[i];
		}
		else {
			data[i] = L2->data[i-10];
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (i>10)
		{
			data[i] = L1->data[i-10];
		}
		else {
			data[i] = L2->data[i];
		}
	}

	for (size_t i = 0; i < 20; i++)
	{
		printf("---%d---\n",data[i]);
	}
}
//      09 ���������б��е�x(���ֲ���)�����򽻻����Ԫ�أ�û�����������
void Find_Or_insert(Sqlist* L1,int x) {
	Sort(L1);
	int left = 0;
	int flag = 0;
	int right = L1->length;
	int middle = (left + right) / 2;
	while (right-left!=1)
	{
		if (L1->data[middle]>x)
		{
			left = middle;
			middle = (left + right) / 2;
		}
		if (L1->data[middle]<x)
		{
			right = middle;
			middle = (left + right) / 2;
		}
		if (L1->data[middle]==x)
		{
			printf("�ҵ�%d,λ��%d\n",x,middle);
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		int temp = 0;
		for (int i =L1->length-1; i>middle; i--)
			{
				printf("δ�ҵ�,2�Ѳ���%dλ��\n",i);
				L1->data[i+1] = L1->data[i];
			}
		L1->data[middle] = x;
	}
	L1->length + 1;
}
//      10 �������е�Ԫ��ѭ������p��
void Revese(Sqlist* R,int from,int to) {
	int i, temp;
	for (int i = 0; i < (to-from+1)/2; i++)
	{
		temp = R->data[from + i];
		R->data[from + i] = R->data[to - i];
		R->data[to - i] = temp;
	}

	}
void Converse(Sqlist* R,int n,int p) {
	Reserve_List(R,0,p-1);
	Reserve_List(R,p,n-1);
	Reserve_List(R,0,n-1);

}
//      11 �ҵ��������кϲ������λ��
int Find_middle(Sqlist* A, Sqlist* B) {
	Sqlist temp;
	temp.data = (int*)malloc(sizeof(int) * 10);
	temp.length = 0;
	A->data = (int*)malloc(sizeof(int) * 5);
	B->data = (int*)malloc(sizeof(int) * 5);
	A->length = 0;
	B->length = 0;
	int i = 0, j = 2;
	for (int i = 0; i < 5; i++,j++)
	{
		A->data[i] = i;
		B->data[i] = j;
		A->length++;
		B->length++;
	}
	PrintList(A);
	printf("-----------------\n");
	PrintList(B);
	printf("-----------------%d\n",A->length);
	int k = 0, f = 0,g=0;
	for (; g < A->length+B->length;g++ )
	{
		if (A->data[k]<B->data[f]&& k<A->length)
		{
			temp.data[g] = A->data[k];
			temp.length++;
			k++;
		}
		else
		{
			if (f > B->length) break;
			temp.data[g] = B->data[f];
			temp.length++;
			f++;
		}
	}
	/*if (k!=A->length)
	{
		for ( ; k < A->length; k++)
		{
			temp.data[k] = A->data[k];
			temp.length++;
		}
	}
	if (f!=B->length)
	{
		for (; f < A->length; f++)
		{
			temp.data[k] = A->data[f];
			temp.length++;
		}
	}*/
	PrintList(&temp);
	return temp.data[temp.length/2];
}
//      12 �ҳ�һ���б��е���Ԫ�أ���Ԫ�ظ�������������һ��
int Find_main_num(int data[],int len){
	int max = 0;
	int num = 0;
	for (int i = 0; i <	len; i++)
	{
		int temp = 1;
	
		for (int j = i+1; j < len; j++)
		{
			if (data[i]==data[j])
			{
				temp++;
			}
		}
		if (max<temp)
		{
			max = temp;
			num = data[i];
		}
	}
	printf("��Ԫ����  %d,������%d��\n", num,max);
}
//      13 �ҳ������г��ֵ���С������
int Find_min_num(int data[], int len) {
	int flag = 1;
	for (size_t i = 0; i < len; i++)
	{
		if (i==len && data[i]!=flag)
		{
			break;
		}
		if (data[i]==flag)
		{
			flag++;
			i = 0;
		}
			}
	printf("���ֵ���С��������%d\n", flag);
}
//      14 �ҳ���������֮�����֮�;���ֵ����Сֵ
int abs_(int a) {
	if (a < 0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}
int xls_min(int a, int b, int c) {
	if (a<=b&&a<=c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
#define INT_MAX 0x7fffffff
int Find_Each_Min_num(int A[], int B[], int C[], int n, int m, int p) {
	int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
	while (i < n && j < m && k < p && D_min>0)
	{
		D = (abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]));
		if (D<D_min)
		{
			D_min = D;
		}
		if (xls_min(A[i], B[j], C[k]))
		{
			i++;
		}
		else if (xls_min(B[j], C[k], A[i]))
		{
			j++;
		}
		else k++;
		}
	return D_min;
}

int main() {
	srand((unsigned)time(NULL));
	Sqlist A, B;
	int s1[] = {-1,0,9};
	int s2[] = { -25,-10,10,11 };
	int s3[] = {2,9,17,30,41};
	Find_Each_Min_num(s1, &s2, s3, 3, 4, 5);
	return 0;
}	