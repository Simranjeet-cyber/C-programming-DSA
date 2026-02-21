#include <stdio.h>

void create(int r, int c, int mat[r][c]);
void display(int r, int c, int mat[r][c]);
void matadd(int r, int c, int mat1[r][c], int mat2[r][c], int mat3[r][c]);

int main()
{
    int mat1[3][4], mat2[3][4], mat3[3][4];
    printf("Enter elements for first array:\n");
    create(3, 4, mat1);
    printf("Enter elements for second array:\n");
    create(3, 4, mat2);
    printf("First Array:\n");
    display(3, 4, mat1);
    printf("Second Array:\n");
    display(3, 4, mat2);
    matadd(3, 4, mat1, mat2, mat3);
    printf("After Addition:\n");
    display(3, 4, mat3);

    return 0;
}
/* creates matrix mat */
void create(int r, int c, int mat[r][c])
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter the element: ");
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
}
/* displays the contents of matrix */
void display(int r, int c, int mat[r][c])
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
/* adds two matrices m1 and m2 */
void matadd(int r, int c, int m1[r][c], int m2[r][c], int m3[r][c])
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            m3[i][j] = m1[i][j] + m2[i][j];
    }
}
}