#include<bits/stdc++.h>
using namespace std;
#define MX_size 10
// const int MX_size =10;

struct Stack{
	int top;
	int elements[MX_size];
};

typedef struct Stack st;

void createStack(st *s)
{
	s->top = -1;
}

int isFull(st *s)
{
	if (s->top == MX_size - 1)
	{
		return 1;
	}
	else
		return 0;
}

int isEmpty(st *s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else
		return 0;
}

void push(st *s, int element)
{
	if (isFull(s) == 1)
	{
		printf("The stack is full!\n");
	}
	else{
		s->elements[++s->top] = element;

		printf("%d is pushed to the stack\n", element);
	}
}
int pop(st *s)
{
	if (isEmpty(s))
	{
		printf("The stack is empty!\n");
	}
	else
	{
		int poppedElement = s->elements[s->top--];
		printf("%d is popped from the stack\n", poppedElement);
		return poppedElement;
	}
}
int peek(st *s)
{
	if (!isEmpty(s))
	{
		return s->elements[s->top];
	}
	else{
		printf("The stack is empty\n");
		return -1;
	}
}


int main()
{
	st stack;
	createStack(&stack);
	int arr[5] = {4, 7, 9, 2, 6};
	for (int i = 0; i < 5; ++i)
	{
		push(&stack, arr[i]);
	}
	printf("Before POP top Elememt is %d\n", peek(&stack));
	pop(&stack);
	pop(&stack);
	printf("After POP top Elememt is %d\n", peek(&stack));

	return 0;
}