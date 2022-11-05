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
	 //复制数组
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
    //初始化数据
    for (int i = 0; i <MaxNum; i++)
    {
        p->data[i] = i;
        p->sz++;
    }
}

void InsertArr(Arr* p,int pos,int data) {
  //从后往前移动
    printf("当前最大容量%d %d\n",p->max,p->sz);
    if (pos>=p->max||pos<1||p->sz>p->max)
    {
        perror("插入元素超范围");
    }
  for (int i = p->sz; i >pos; i--)
		{
			p->data[i] = p->data[i-1];
		}
		p->data[pos] = data;
		p->sz++;
}
 void DeleteArr(Arr* p,int pos) {
  //从后往前移动
    printf("当前最大容量%d %d\n",p->max,p->sz);
    if (pos>=p->max||pos<1||p->sz>p->max)
    {
        perror("插入元素超范围");
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
    printf("下标%d",index);
    free(arr.data);
}