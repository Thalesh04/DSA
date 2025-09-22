#include <stdio.h>
#include <stdlib.h>

/*searching 

linear search - no sorted array required
binary search - sorted array required

*/
int main()
{
     
}

/* Rotate by 1

#define N 3

void rotateMatrixByOne(int matrix[N][N])
{
    int temp = matrix[0][0]; // Store the first element temporarily
    int i;
    // Move elements of the first row
    for (i = 0; i < N - 1; i++)
    {
        matrix[0][i] = matrix[0][i + 1];
    }

    // Move elements of the last column
    for (i = 0; i < N - 1; i++)
    {
        matrix[i][N - 1] = matrix[i + 1][N - 1];
    }

    // Move elements of the last row
    for (i = N - 1; i > 0; i--)
    {
        matrix[N - 1][i] = matrix[N - 1][i - 1];
    }

    // Move elements of the first column
    for (i = N - 1; i > 1; i--)
    {
        matrix[i][0] = matrix[i - 1][0];
    }

    matrix[1][0] = temp; // Place the temporarily stored element
}

void printMatrix(int matrix[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[N][N];
    int i,j;

    for(i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("enter elements:"); 
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    printMatrix(matrix);

    rotateMatrixByOne(matrix);

    printf("\nMatrix after rotating by 1 position:\n");
    printMatrix(matrix);

    return 0;
}*/