// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void append(Node **ptr, int data)
{
    Node *n= createNode(data);
    if(*ptr==NULL)
    { 
        *ptr=n;
        
    }
    else{
    Node *temp=*ptr;
    
    while(temp->next!=NULL)
    {
         temp=temp->next;
       
    }
     temp->next=n;
        n->prev=temp;
    }
    
}

void traverseForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    
        (*head)->prev = newNode;
 
    *head = newNode;
}
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAfter(Node* prevNode,int loc, int data) {
    int i=1;
   while(prevNode !=NULL && i<loc)
   {
    prevNode=prevNode->next;
    i++;
   }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    prevNode->next = newNode;
}
void deleteFromFront(Node** head) {
    if (*head == NULL) {
        printf("The list is already empty\n");
        return;
    }
    
    Node* temp = *head;
    *head = (*head)->next;
            (*head)->prev = NULL;
        free(temp);
}
void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("The list is already empty\n");
        return;
    }
    
    Node* temp = *head;
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
      
        temp->prev->next = NULL;
        free(temp);
}
void reverseList(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* temp = NULL;
    Node* current = *head;

    while (current != NULL) {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is previous before swap)
        current = current->prev;
    }

    // Update head
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    // Creating individual nodes
    Node* head = NULL;
    append(&head,3);
    append(&head,5);
    append(&head,8);

    printf("Forward traversal: ");
    traverseForward(head);

    printf("Backward traversal: ");
    traverseBackward(head);
    insertAtFront(&head,12);
    traverseForward(head);
    insertAtEnd(&head,15);
    traverseForward(head);
    insertAfter(head,3,42);
    traverseForward(head);
    deleteFromFront(&head);
    traverseForward(head);
    deleteFromEnd(&head);
    traverseForward(head);
    reverseList(&head);
    printf("After reversing: ");
    traverseForward(head);
      return 0;

}
