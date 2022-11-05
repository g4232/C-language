#include <stdio.h>
#define MaxNum 10
typedef struct Arr
{
  int data[MaxNum];
  int sz;

}Arr;





void InitArr(Arr* p){
  for (int i = 0; i < MaxNum; i++)
  {
    p->data[i] = i;
  } 
  p->sz=0;

}



void main(){
  Arr arr;

  InitArr(&arr); 
  printf("%d",arr.data[8]);
}