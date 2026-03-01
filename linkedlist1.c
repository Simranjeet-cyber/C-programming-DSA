#include <stdio.h>
#include <stdlib.h> 
struct node
{
 int data ; struct node * next ;
} ; 
struct node* createNode(int data) {
struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}
/* adds a node at the end of a linked list */
void append ( struct node **ptr, int num )
{
 struct node *temp,*n ;
 n = createNode(num);
 if ( *ptr == NULL ) /* if the list is empty, create first node */
 {
 *ptr = n ;
 }
 else
 {
 temp = *ptr ;
 /* go to last node */
 while ( temp -> next != NULL )
    temp = temp -> next ;
 /* add node at the end */
 temp -> next = n ;
 }
} 
/* adds a new node at the beginning of the linked list */
void insertBeg ( struct node **ptr, int num )
{
 struct node *n ;
 /* add new node */
 n = createNode(num);
 n -> next = *ptr ;
 *ptr = n ;
} 
void display ( struct node *ptr )
{
 /* traverse the entire linked list */
 while ( ptr != NULL )
 {
 printf ( "%d ", ptr -> data ) ;
 ptr=ptr->next;
 }
 printf ( "\n" ) ;
} 
void deleteFirst(struct node** ptr) {
    if (*ptr == NULL) {
        printf("List is empty\n");
       // return head;
    }
    struct node* temp = *ptr;
    *ptr = temp->next;
    free(temp);
    //return head;
}
int count ( struct node * ptr )
{
 int c = 0 ;
 /* traverse the entire linked list */ 
 while ( ptr != NULL )
 {
 ptr = ptr -> next ;
 c++ ;
 }
 return c ;
} 
void insertAfter(struct node** ptr, int loc, int val)
{
    struct node *n=createNode(val);
    struct node *temp=*ptr;
    int i=1;
    while(i<loc&& temp!=NULL)
    {
       temp=temp->next;
        i++;
    }
    n->next=temp->next;
    temp->next=n;
    
}

void deleteEnd(struct node** ptr) {
  
    struct node* temp = *ptr, *prev=*ptr;
    if (temp->next == NULL) {
        free(temp);
        *ptr = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev=temp;
        temp = temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void deleteVal(struct node **ptr, int val)
{
    struct node* temp=*ptr, *prev=*ptr;
    while(temp!=NULL)
    {
        if (temp->data==val)
            break;
        prev=temp;
        temp=temp->next;
    }
    //when value to be deleted is of first node
    if(temp==*ptr)
    {
        *ptr=(*ptr)->next;
        free(temp);
    }
    else
    {
        prev->next=temp->next;
        free(temp);
    }
}
int main( )
{
 struct node *start ;
 start = NULL ; 
 printf ( "No. of elements in the Linked List = %d\n", count ( start ) ) ;
 append ( &start, 14 ) ; 
 append ( &start, 30 ) ; 
 append ( &start, 25 ) ;
 append ( &start, 42 ) ;
 append ( &start, 17 ) ;
 display ( start) ;
 insertBeg ( &start, 99 ) ; 
 insertBeg ( &start, 88 ) ; 
 insertBeg ( &start, 77 ) ;
 display ( start ) ;
 insertAfter(&start,3,26);
 display ( start ) ;
  printf ( "No. of elements in the Linked List = %d\n", count ( start ) ) ;
 deleteFirst(&start);
 display ( start ) ;
 deleteEnd(&start);
 display ( start ) ;
 deleteVal(&start,99);
 display ( start ) ;
 return 0;
}
