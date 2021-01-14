#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *ptr;
};

struct node* findNode(struct node* head, int val)
{
    struct node *temp = head;
    while(temp)
    {
        if (temp->val == val)
		return temp;

        temp = temp->ptr;
    }
    return NULL;
}

void printList(struct node *head)
{
    printf("\nThe current list is:\n");
    while(head)
    {
        printf("%d\t", head->val);
        head = head->ptr;
    }

}

void insertFront(struct node **head, int value)
{
    struct node* newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
        printf("Failed to insert element. Out of memory");


    newNode->val = value;
    newNode->ptr = *head;

    *head = newNode;
}

void insertEnd(struct node **head, int value)
{
    struct node* newNode = NULL;
    struct node* last = NULL;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL)
        printf("Failed to insert element. Out of memory");


    newNode->val = value;
    newNode->ptr = NULL;

    if( *head == NULL)
    {
        *head = newNode;
        return;
    }

    last = *head;
    while(last->ptr) last = last->ptr;

    last->ptr = newNode;
}

void insertAfter(struct node *pos, int value)
{
    struct node* newNode = NULL;
    if (pos == NULL) return;

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Failed to insert element. Out of memory");

    newNode->val = value;
    newNode->ptr = pos->ptr;
    pos->ptr = newNode;
}

void insertBefore(struct node **head, struct node *pos, int value)
{
    struct node* newNode = NULL;
    struct node* tempNode = NULL;

    if (pos == NULL) return;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    newNode->val = value;

    if(*head == pos)
    {
        newNode->ptr = pos;
        *head = newNode;
        return;
    }

    tempNode = *head;

    while(tempNode->ptr != pos)
    {
        tempNode = tempNode->ptr;

        if(tempNode == NULL) return;
    }

    newNode->ptr = tempNode->ptr;
    tempNode->ptr = newNode;
}

void main()
{
    int count = 0, i, val, pos;
    struct node* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printList(head);

    printf("\n\nEnter a value to enter at the front of the list: ");
    scanf("%d", &val);
    insertFront(&head, val);
    printList(head);

    printf("\n\nEnter a value to enter at the end of the list: ");
    scanf("%d", &val);
    insertEnd(&head, val);
    printList(head);

    printf("\n\nEnter a value to insert in the list: ");
    scanf("%d", &val);
    printf("Insert after: ");
    scanf("%d", &pos);
    insertAfter(findNode(head, pos), val);
    printList(head);

    printf("\n\nEnter a value to insert in the list: ");
    scanf("%d", &val);
    printf("Insert before: ");
    scanf("%d", &pos);
    insertBefore(&head, findNode(head, pos), val);
    printList(head);
}
