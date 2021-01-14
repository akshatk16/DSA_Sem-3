#include <stdio.h>
#include <stdlib.h>


#define MAX_ARRAY 50

int queue[MAX_ARRAY];
int end = - 1;
int start = - 1;


void insert()
{
	int val;
	if(end == MAX_ARRAY - 1)
		printf("OVERFLOW!\n");
	else
	{
		if(start == -1)
			start = 0;

		printf("Enter element to be inserted: ");
		scanf("%d", &val);

		end++;
		queue[end] = val;
	}
}

void delete()
{
	if(start == -1 || start > end)
	{
		printf("UNDERFLOW\n");
		return;
	}
	else
	{
		printf("Element deleted is %d\n", queue[start]);
		start++;
	}
}

void printQueue()
{
	if(start == -1)
		printf("EMPTY QUEUE\n");
	else
	{
		printf("\nCurrent queue is:\n");
		for(int i=start; i<=end; i++)
			printf("%d\t", queue[i]);
	}
}

int main()
{
	int choice;
	while (1)
	{
		printf("\n\n1.Insert element to queue \n");
		printf("2.Delete element from queue \n");
	    	printf("3.Display all elements of queue \n");
	    	printf("4.Quit \n");
	    	printf("\nEnter your choice : ");

	    	scanf("%d", &choice);

	    	switch (choice)
	    	{
			case 1:
		  		insert();
				break;
	  		case 2:
		  		delete();
				break;
			case 3:
				printQueue();
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid Option \n");
		}
	}
	return 0;
}
