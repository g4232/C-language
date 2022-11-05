#include <stdio.h>
#define MaxSize 10

typedef struct {
	char data[MaxSize];
	int top;
} SqStack;
void InitStack(SqStack *S) {
	S->data[0] = '{';
	S->data[1] = '[';
	S->data[2] = '(';
	S->top = 2;
}
int StackEmpty(SqStack *S) {
	if (S->top=0)
	{
		return 0;
	}
	return 1;
}
int Push(SqStack* S,char* str ) {
	S->data[S->top] = *str;
	S->top += 1;
}
int Pop(SqStack* S,char* str) {
	*str = S->data[S->top];
	S->top -= 1;
}
int BracketCheck(char str[],int length) {
	SqStack S;
	InitStack(&S);
	for (int i = 0; i < length; i++)
	{
		if (str[i]=='(' || str[i] =='[' ||str[i]=='{')
		{
			Push(&S, str[i]);
		}
		else
		{
			if (StackEmpty(&S))
			{
				return 1;
			}
			char topElem;
			Pop(&S, topElem);
			if (str[i]==')' && topElem !='(')
			{
				return 0;
			}
			if (str[i]==']' && topElem!=']')
			{
				return 0;
			}
			if (str[i]=='}' && topElem!='{')
			{
				return 0;
			}
		}
	}
	return StackEmpty(&S);
}
void main() {
	char str[] = { '}',']',')' };
	int state = BracketCheck(str,3);
	printf("%d", state);

}