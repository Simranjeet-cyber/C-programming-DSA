#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,*ptr,sum=0;
    printf(" Enter number of Elements\n");
    scanf("%d",&n);
    ptr= (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d", ptr+i);
        sum+=*(ptr+i);
    }
    printf("Sum of given %d numbers = %d",n,sum);
    free(ptr);
    return 0;
}