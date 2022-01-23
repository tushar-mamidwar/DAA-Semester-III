#include <stdio.h>
#include <limits.h>
int n;
void PrintSequence(int i, int j,int s[][n])
{
    if (i == j)
        printf(" M%d ", i);
    else
    {
        printf("( ");
        PrintSequence(i, s[i][j],s);
        PrintSequence(s[i][j] + 1, j,s);
        printf(" )");
    }
}
void calculateOperations(int dim[], int m[][n], int s[][n])
{
    int d, i, j, k;
    int min;
    int q;
    for (d = 1; d < n - 1; d++)
    {
        for (i = 1; i < n - d; i++)
        {
            j = i + d;
            min = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    printf("minimum no. of operations required are:%d", m[1][n - 1]);
}
void main()
{
    int i, j;
    printf("Enter no. of matrices:");
    scanf("%d", &n);
    n += 1;
    int dim[n];
    int m[n][n], s[n][n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            m[i][j] = s[i][j] = 0;
        }
    printf("Enter %d dimensions of matrices:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &dim[i]);
    }
    calculateOperations(dim, m, s);
    printf("Optimal Sequence is:");
    PrintSequence(1,n-1,s);
    printf("\nMinimum no. of operations required:%d",m[1][n-1]);

}

/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc MatrixChainMultiplication.c -o MatrixChainMultiplication } ; if ($?) { .\MatrixChainMultiplication }
Enter no. of matrices:4
Enter 5 dimensions of matrices:5 4 6 2 7
minimum no. of operations required are:158Optimal Sequence is:( (  M1 (  M2  M3  ) ) M4  )
Minimum no. of operations required:158
*/