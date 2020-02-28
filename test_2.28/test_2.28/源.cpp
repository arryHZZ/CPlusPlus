#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main()
//{
//	int number;
//	scanf("%d", &number);
//	unsigned mask = 1u << 31;
//	for (; mask; mask >>= 1){
//		printf("%d", number&mask ? 1 : 0);
//	}
//	printf("\n");
//	return 0;
//}

//int f(void);
//int gALL=12;//全局变量
//int main(int argc,char const *argv[])
//{
//    f();
//    f();
//    f();
//    return 0;
//}
//int f(void)
//{
//    int k=0;
//    static int all=1;
//    printf("&gALL=%p\n",&gALL);
//    printf("&all=%p\n",&all);
//    printf("&k=%p\n",&k);
//    printf("in %s all=%d\n",_func_,all);
//    gALL+=2;
//    printf("agn in %s all=%d\n",_func_,all);
//    return all;
//}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ElemType int
#define MAXSIZE 100
#define ERROR 0
#define OK 1
typedef struct SeqStack
{
	ElemType data[MAXSIZE];
	int top;
}SeqStack, *Stack;
int Push(Stack S, int x);
void TraverseStack(Stack S);

int main()
{
	int a;
	Stack S;
	S = (Stack)malloc(sizeof(SeqStack));  //初始化
	S->top = -1;
	printf("请输入入栈的元素,以-1结束：\n");
	scanf("%d", &a);
	while (a != -1)
	{
		Push(S, a);
		scanf("%d", &a);
	}
	printf("栈中的元素为：\n");
	TraverseStack(S);

	return 0;
}
int Push(Stack S, int x)
{
	if (S->top == MAXSIZE - 1)
		return (ERROR);
	else
	{
		S->top++;
		S->data[S->top] = x;
		return (OK);
	}
}
void TraverseStack(Stack S)
{
	int i;
	for (i = 0; i <= S->top; i++)
	{
		printf("%d ", S->data[i]);
	}
}
