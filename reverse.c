#include <stdio.h>

void reverse(int ar[], int n)
{
    int i, temp;
    int j;

    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
}

int main()
{
    int ar[10], i;

    printf("Enter 10 elements:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &ar[i]);
    }

    reverse(ar, 10);  

    printf("Reversed array:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}
