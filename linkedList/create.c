#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* ptr;
};

int main()
{
	struct node *root, *first, *temp;
	first=0;


	int choice=1;
	while(choice)
	{
		root = (struct node*)malloc(sizeof(struct node));
		printf("Enter node data: ");
		scanf("%d", &root->data);
		if(first!=0)
		{
			temp->ptr = root;
			temp =  root;
		}
		else
			first = temp = root;


		printf("Add more? ");
		scanf("%d", &choice);
	}
	temp->ptr = NULL;

	temp = first;
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->ptr;
	}

	return 0;
}
