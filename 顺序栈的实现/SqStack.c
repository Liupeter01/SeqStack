#include"SqStack.h"

void InitStack(SqStack* S)   //��ʼ��ջ
{
		  S->base = (ElemType*)malloc(sizeof(int) * STACK_INIT_SIZE); //����ռ�
		  assert(S->base != NULL);
		  S->stacksize = STACK_INIT_SIZE;
		  S->top = 0;		  //ֱ�Ӹ�ֵΪ0����ֱ������Ԫ��
}

void DestroyStack(SqStack* S)   //�ݻ�ջ
{
		  free(S->base);
		  S->base = NULL;
		  S->stacksize = 0;
}

void ClearStack(SqStack* S)   //���ջ
{
		  S->top = 0;
}

int length(SqStack S)                 //��ջ�ĳ���
{
		  return S.top;
}

ElemType GetTop(SqStack S)             //��ȡ����Ԫ��
{
		  if (!IsEmpty(&S))
		  {
					return S.base[(S.top - 1)];
		  }
		  else
		  {
					printf("ջ�ռ��ѿգ�������ȡջ��Ԫ��\n");
					return FALSE;
		  }
}

BOOL ExtendStackSize(SqStack* S)//ջ�ռ����չ
{
		  S->base = (ElemType*)realloc(S->base, sizeof(ElemType) * (S->stacksize + STACK_INC_SIZE));		//���·���
		  assert(S->base != NULL);
		  if (S->base == NULL)
		  {
					return FALSE;
		  }
		  else
		  {
					S->stacksize += STACK_INC_SIZE;
					return TRUE;
		  }
}

BOOL IsFull(SqStack* S)     //�Ƿ�����
{
		  return S->top >= S->stacksize;
}

BOOL IsEmpty(SqStack* S)     //�Ƿ�Ϊ��
{
		  return S->top == 0;
}

BOOL Push_stack(SqStack* S, ElemType x)        //��ջ
{
		  if (IsFull(S) && ExtendStackSize(S))	  ////���ǿռ䲻�������Զ�����
		  {
					printf("ջ�ռ�������%d��������ջ\n", x);
					return FALSE;
		  }
		  else
		  {
					S->base[S->top++] = x;
					return TRUE;
		  }
}

BOOL Pop_stack(SqStack* S, ElemType* x)           //��ջ
{
		  if (IsEmpty(S) && ExtendStackSize(S))				//���ǿռ䲻�������Զ�����
		  {
					printf("ջ�ռ��ѿգ������Գ�ջ\n");
					return FALSE;
		  }
		  else
		  {
					*x = S->base[--(S->top)];
					return TRUE;
		  }
}