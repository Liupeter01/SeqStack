#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType int

#define STACK_INIT_SIZE 8               //初始空间大小
#define STACK_INC_SIZE 3               //空间扩展增量大小

typedef struct SqStack
{
          ElemType* base;       //栈底
          int stacksize;           //栈的大小
          int top;                      //栈顶
}SqStack;

void InitStack(SqStack* S);   //初始化栈
void DestroyStack(SqStack* S);   //摧毁栈
void ClearStack(SqStack* S);   //清除栈
int length(SqStack S);                  //求栈的长度
ElemType GetTop(SqStack S);             //获取顶部元素
BOOL ExtendStackSize(SqStack* S);//栈空间的扩展

/*出入栈*/
BOOL Push_stack(SqStack* S, ElemType x);          //入栈
BOOL Pop_stack(SqStack* S, ElemType* x);           //出栈

/*栈的判断系列*/
BOOL IsFull(SqStack* S);      //是否已满
BOOL IsEmpty(SqStack* S);      //是否为空