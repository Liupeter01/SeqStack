#include"SqStack.h"

int main()
{
		  SqStack stack;
		  InitStack(&stack);
		  for (int i = 0; i < 5; ++i)
		  {
					Push_stack(&stack, i);
		  }
		  DestroyStack(&stack);
		  return 0;
}