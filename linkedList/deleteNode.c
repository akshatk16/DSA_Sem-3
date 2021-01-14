#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* ptr;
};

void printList(struct node *first)
{
	printf("\nThe current list is\n");
	struct node *temp = first;
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->ptr;
	}
}
void deleteNode(struct node *head, int length)
{
	struct node* temp = head;
	int loc;

	printf("\n\nWhich node would you like to delete? ");
	scanf("%d", &loc);

	if(loc>length)
		printf("Invalid location\n");

	else if(loc==1)
	{
		// temp = head;
		head = head->ptr;
		temp->ptr = NULL;
		free(temp);

	}

	else
	{
		struct node *del;

		for(int i = 1; i<loc-1; i++)
			temp = temp->ptr;

		del = temp->ptr;
		temp->ptr = del->ptr;
		del->ptr = NULL;
		free(del);
	}
	printList(head);
}


int main()
{
	struct node *root, *first, *temp;
	first=0;


	int choice=1, count = 0;
	while(choice)
	{
		count++;
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


	printList(first);
	deleteNode(first, count);

	return 0;
}
