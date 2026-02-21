#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sp[4][5] = {
                    {0,0,5,4,0},
                    {3,4,0,0,0},
                    {0,0,1,2,0},
                    {4,0,0,2,1}};

    int size = 0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            if(sp[i][j]!=0)
            {
                size++;
            }
        }
    }
    int cp[3][size],k=0;

    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            if(sp[i][j]!=0)
            {
                cp[0][k]=i;
                cp[1][k]=j;
                cp[2][k] = sp[i][j];
                k++;
            }
        }
    }
    printf("Display \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d\t" , cp[i][j]);
        }
    }
    return 0;
}