#include <stdio.h>


#define CAPACITY 5


int top = -1;
int stack[CAPACITY];


int isFull()
{
	if(top == CAPACITY - 1)
		return 1;
	else
		return 0;
}


int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}


void push(int x)
{
	printf("Pushing %d: ", x);
	if(isFull())
		printf("FAILED! Stack Full\n\n");
	else
	{
		top++;
		stack[top] = x;
		printf("%d pushed\n", x);
	}
}


int pop()
{
	int x;
	if(isEmpty())
		return -1;
	else
	{
		x = stack[top];
		top--;

		return x;
	}
}


int peek()
{
	if(isEmpty)
		return 0;
	else
		return stack[top];
}


void traverse()
{
	if(isEmpty())
		printf("\nSTACK EMPTY!\n");
	else
	{
		printf("\nStack looks like:\n\n");
		for(int i=top;i>=0;i--)
			printf("%d\n", stack[i]);
		printf("\n");
	}
}


int main()
{

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);

	printf("%d popped\n", pop());
	printf("%d popped\n", pop());

	traverse();

	return 0;
}
