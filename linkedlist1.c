#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}; 


// create node function
struct node *create_node(int d)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    return n;
}

// append at end
void append(struct node **ptr, int data)
{
    struct node *n, *temp;
    n = create_node(data);

    if (*ptr == NULL)
        *ptr = n;
    else
    {
        temp = *ptr;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }
}

// insert at beginning
void insertBeg(struct node **ptr, int data)
{
    struct node *n;
    n = create_node(data);
    n->next = *ptr;
    *ptr = n;
}

// display list
void display(struct node *start)
{
    while (start != NULL)
    {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL");
}

int main()
{
    struct node *start = NULL;

    append(&start, 20);
    append(&start, 30);
    append(&start, 50);

    insertBeg(&start, 24);

    display(start);

    return 0;
}