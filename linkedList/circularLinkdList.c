
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * next;
}*head;



/*
 * Functions used in this program
 */
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtN(int data, int position);
void deleteAll(struct node ** head,int key);

int main()
{
    int n, key, data, choice;

    head = NULL;

    /*
     * Runs forever until user chooses 0
     */
    while(choice != 0)
    {
	printf("============================================\n");
	printf("CIRCULAR LINKED LIST PROGRAM\n");
	printf("============================================\n");
	printf("1. Create List\n");
	printf("2. Display list\n");
	printf("3. Insert at beginning\n");
	printf("4. Insert at any position\n");
  printf("5. Delete a key\n");
	printf("0. Exit\n");
	printf("--------------------------------------------\n");
	printf("Enter your choice : ");

	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		printf("Enter the total number of nodes in list: ");
		scanf("%d", &n);
		createList(n);
		break;
	    case 2:
		displayList();
		break;
	    case 3:
		printf("Enter data to be inserted at beginning: ");
		scanf("%d", &data);
		insertAtBeginning(data);
		break;
	    case 4:
		printf("Enter node position: ");
		scanf("%d", &n);
		printf("Enter data you want to insert at %d position: ", n);
		scanf("%d", &data);
		insertAtN(data, n);
		break;
		case 5:
		printf("Enter key to delete from list: ");
		scanf("%d", &key);
		deleteAll(&head, key);
		break;

	    case 0:
		break;
	    default:
		printf("Error! Invalid choice. Please choose between 0-4");
	}

	printf("\n\n\n\n\n");
    }
    getch();
    return 0;
}



/**
 * Creates a circular linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    if(n >= 1)
    {
	/*
	 * Creates and links the head node
	 */
	head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        /*
         * Creates and links rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            //Links the previous node with newly created node
            prevNode->next = newNode;
            //Moves the previous node ahead
            prevNode = newNode;
        }

        //Links the last node with first node
        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void deleteAll(struct node ** head, int key)
{
    int i, count;
    struct node *prev, *cur;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    count = 0;
    cur   = *head;
    prev  = cur;


    // Find node before head node
    while (prev->next != *head)
    {
        prev = prev->next;
        count++;
    }

    // Iterate till first node
    i = 0;
    while (i <= count)
    {
        if (cur->data == key)
        {
            // Link prev node with next node of current
            if (cur->next != cur)
                prev->next = cur->next;
            else
                prev->next = NULL;

            // Adjust head node if needed
            if (cur == *head)
                *head = prev->next;

            // Delete current node
            free(cur);

            // Move current node ahead
            if (prev != NULL)
                cur = prev->next;
            else
                cur = NULL;
        }
        else
        {
            prev = cur;
            cur  = cur->next;
        }


        i++;

    }
}




/**
 * Displays the content of the list
 */
void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}



/**
 * Inserts a new node at the beginning of the list
 * @data Data of the first node
 */
void insertAtBeginning(int data)
{
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        /*
         * Creates new node, assign data and links it to head
         */
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;

        /*
         * Traverses to last node and links last node
         * with first node which is new node
         */
        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

        /*Makes new node as head node*/
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY\n");
    }
}



/**
 * Inserts a new node at any position in the list
 * @data Data of the new node
 * @position Position where to insert new node
 */
void insertAtN(int data, int position)
{
    struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(position == 1)
    {
        insertAtBeginning(data);
    }
    else
    {
        /*
         * Creates new node and assign data to it
         */
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;

        /*
         * Traverse to n-1 node
         */
        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }

        /* Links new node with node ahead of it and previous to it*/
        newNode->next = current->next;
        current->next = newNode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }
}
