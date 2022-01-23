#include <stdio.h>
int cost[10][10], visited[10], n, totalCost = 0;

int least(int c)
{
    int i, nc = 1000;
    int min = 1000, kmin;

    for (i = 0; i < n; i++)
    {
        if ((cost[c][i] != 0) && (visited[i] == 0))
        {
            if (cost[c][i] + cost[i][c] < min)
            {
                min = cost[i][0] + cost[c][i];
                kmin = cost[c][i];
                nc = i;
            }
        }
    }

    if (min != 1000)
    {
        totalCost += kmin;
    }
    return nc;
}

void mincost(int m)
{

    int i, nvertex;
    visited[m] = 1;

    printf("%d\t", m + 1);
    nvertex = least(m);

    if (nvertex == 1000)
    {
        nvertex = 0;
        printf("%d", nvertex + 1);
        totalCost += cost[m][nvertex];
        return;
    }
    mincost(nvertex);
}

int main()
{

    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter Graph in the matrix form:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nPath \n");
    mincost(0);

    printf("\nTotal Cost = %d ", totalCost);
}
/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc TravellingSalesman.c -o TravellingSalesman } ; if ($?) { .\TravellingSalesman }
Enter number of vertices: 5

Enter Graph in the matrix form:
0 4 9 8 0
4 0 4 1 0
9 4 0 3 3
8 1 3 0 4
0 0 3 4 0

Path
1       2       4       5       3       1
Total Cost = 21
*/