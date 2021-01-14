#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* ptr;
}* top;


int isEmpty()
{
	return top == NULL;
}


void push(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("%d pushed\n", x);


	if (!temp) {
		printf("OVERFLOW!\n");
		exit(1);
	}

	temp->data = x;
	temp->ptr = top;
	top = temp;
}


void pop()
{
	struct node* temp;

	if (top == NULL) {
		printf("UNDERFLOW!\n");
		exit(1);
	}
	else {
		temp = top;
		top = top->ptr;
		temp->ptr = NULL;
		free(temp);
		printf("Popping...\n");
	}
}


int peek()
{
	if (isEmpty())
		exit(1);
	else
		return top->data;
}


void printStack()
{
	struct node* temp;

	if (top == NULL) {
		printf("UNDERFLOW!\n");
		exit(1);
	}
	else {
		temp = top;
		printf("\nCurrent Stack is:\n");
		while (temp != NULL) {
			printf("%d\n", temp->data);
			temp = temp->ptr;
		}
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

	printf("\nPeeking top element: %d \n\n", peek());

	pop();
	pop();

	printStack();

	return 0;
}
