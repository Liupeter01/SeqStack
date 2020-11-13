#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType int

#define STACK_INIT_SIZE 8               //��ʼ�ռ��С
#define STACK_INC_SIZE 3               //�ռ���չ������С

typedef struct SqStack
{
          ElemType* base;       //ջ��
          int stacksize;           //ջ�Ĵ�С
          int top;                      //ջ��
}SqStack;

void InitStack(SqStack* S);   //��ʼ��ջ
void DestroyStack(SqStack* S);   //�ݻ�ջ
void ClearStack(SqStack* S);   //���ջ
int length(SqStack S);                  //��ջ�ĳ���
ElemType GetTop(SqStack S);             //��ȡ����Ԫ��
BOOL ExtendStackSize(SqStack* S);//ջ�ռ����չ

/*����ջ*/
BOOL Push_stack(SqStack* S, ElemType x);          //��ջ
BOOL Pop_stack(SqStack* S, ElemType* x);           //��ջ

/*ջ���ж�ϵ��*/
BOOL IsFull(SqStack* S);      //�Ƿ�����
BOOL IsEmpty(SqStack* S);      //�Ƿ�Ϊ��