#include <stdio.h>
void insert(int ar[], int pos, int val)
{ int i;
    
    for (i=4;i>=pos;i--)
        ar[i]=ar[i-1];
    ar[i]=val;    
}
void display(int ar[])
{
    for(int i=0;i<5;i++)
      printf("%d",ar[i]);
}
void del(int ar[], int pos)
{ int i;
    for (i=pos;i<5;i++)
        ar[i-1]=ar[i];
    ar[i-1]=0; 
}
int main() {
    // Write C code here
   int arr[ 5 ] ;
 insert ( arr, 1, 11 ) ;
 insert ( arr, 2, 12 ) ;
 insert ( arr, 3, 13 ) ;
 insert ( arr, 4, 14 ) ;
 insert ( arr, 5, 15 ) ;
 printf ( "Elements of Array:\n" ) ;
 display ( arr ) ; 
 del ( arr, 5 ) ;
 del ( arr, 2 ) ;
 printf ( "After deletion:\n" ) ;
 display ( arr ) ;
 insert ( arr, 2, 222 ) ;
 insert ( arr, 5, 555 ) ;
 printf ( "After insertion:\n" ) ;
 display ( arr ) ; /*reverse ( arr ) ;
 printf ( "After reversing:\n" ) ;
 display ( arr ) ;
 search ( arr, 222 ) ;
 search ( arr, 666 ) ;*/
 return 0 ; 
   
}