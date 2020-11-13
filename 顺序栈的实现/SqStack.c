#include"SqStack.h"

void InitStack(SqStack* S)   //初始化栈
{
		  S->base = (ElemType*)malloc(sizeof(int) * STACK_INIT_SIZE); //申请空间
		  assert(S->base != NULL);
		  S->stacksize = STACK_INIT_SIZE;
		  S->top = 0;		  //直接赋值为0可以直接填入元素
}

void DestroyStack(SqStack* S)   //摧毁栈
{
		  free(S->base);
		  S->base = NULL;
		  S->stacksize = 0;
}

void ClearStack(SqStack* S)   //清除栈
{
		  S->top = 0;
}

int length(SqStack S)                 //求栈的长度
{
		  return S.top;
}

ElemType GetTop(SqStack S)             //获取顶部元素
{
		  if (!IsEmpty(&S))
		  {
					return S.base[(S.top - 1)];
		  }
		  else
		  {
					printf("栈空间已空，不可以取栈顶元素\n");
					return FALSE;
		  }
}

BOOL IsFull(SqStack* S)     //是否已满
{
		  return S->top >= S->stacksize;
}

BOOL IsEmpty(SqStack* S)     //是否为空
{
		  return S->top == 0;
}

BOOL Push_stack(SqStack* S, ElemType x)        //入栈
{
		  if (!IsFull(S))	  //没有满
		  {
					S->base[S->top++] = x;
					return TRUE;
		  }
		  else
		  {
					printf("栈空间已满，%d不可以入栈\n", x);
					return FALSE;
		  }
}

BOOL Pop_stack(SqStack* S, ElemType* x)           //出栈
{
		  if (!IsEmpty(S))
		  {
					*x = S->base[--(S->top)];
					return TRUE;
		  }
		  else
		  {
					printf("栈空间已空，不可以出栈\n");
					return FALSE;
		  }
}

