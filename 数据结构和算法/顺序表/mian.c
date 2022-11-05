#include <stdio.h>
#include <stdlib.h>
#define MaxNum 10
typedef struct Arr
{
    int *data;
    int sz;
    int max;
}Arr;



void CreateArr(Arr* p,int length){
    p->data = (int*)realloc(p->data,(length+p->max)*sizeof(int));
    if (p->data==NULL)
    {    
        perror("CreateError!");
    }
    p->max += length;
    //int* pp = p->data;
	 //��������
	//for (int i = 0; i < p->sz; i++)
	// {
	//	p->data[i] = pp[i];
	//   }
}
void InitArr(Arr* p) {
    p->sz = 0;
    p->max = MaxNum;
	p->data = (int*)malloc(MaxNum *sizeof(int));
    if (p->data == NULL)
    {
        perror("InitArrError!");
    }
    //��ʼ������
    for (int i = 0; i <MaxNum; i++)
    {
        p->data[i] = i;
        p->sz++;
    }
}

void InsertArr(Arr* p,int pos,int data) {
  //�Ӻ���ǰ�ƶ�
    printf("��ǰ�������%d %d\n",p->max,p->sz);
    if (pos>=p->max||pos<1||p->sz>p->max)
    {
        perror("����Ԫ�س���Χ");
    }
  for (int i = p->sz; i >pos; i--)
		{
			p->data[i] = p->data[i-1];
		}
		p->data[pos] = data;
		p->sz++;
}
 void DeleteArr(Arr* p,int pos) {
  //�Ӻ���ǰ�ƶ�
    printf("��ǰ�������%d %d\n",p->max,p->sz);
    if (pos>=p->max||pos<1||p->sz>p->max)
    {
        perror("����Ԫ�س���Χ");
    }
    for (int i = pos; i < p->sz; i++)
		{
			p->data[i] = p->data[i+1];
		}
		p->sz--;
}

 int FindArr(Arr*p,int data) {
     for (int i = 0; i < p->sz; i++)
     {
         if (data==p->data[i])
         {
             return i;
         }
     }
 
 }



void main() {
    Arr arr;
    InitArr(&arr);
    CreateArr(&arr,1);
    //InsertArr(&arr, 1, 2);
    //DeleteArr(&arr,9);
    int index = FindArr(&arr,9);
    //for (int i = 0; i < arr.sz; i++)
    //{
    //    printf("%d\n", arr.data[i]);
    //}
    printf("�±�%d",index);
    free(arr.data);
}