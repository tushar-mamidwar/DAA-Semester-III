#include<stdio.h>
#include<limits.h>
int n;
void BellmanFord(int weights[][n], int distance[])
{
    int i,j,k;
    for(k=1;k<n;k++)
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(weights[i][j] && distance[i]+weights[i][j]<distance[j])
                {
                    distance[j]=distance[i]+weights[i][j];
                }
            }
        }

}
void Print_lengths(int distance[])
{
    int i;
    printf("Vertex   Distance\n");
    for(i=0;i<n;i++)
    {
        printf("%d        %d\n",i+1,distance[i]);
    }
}

void main()
{
    int i,j;
    printf("Enter no. vertices:");
    scanf("%d",&n);
    int weights[n][n],distance[n];
    printf("Enter the the graph in matrix format:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&weights[i][j]);
    distance[0]=0;
    for(i=1;i<n;i++)
    {
        distance[i]=INT_MAX;
    }
    BellmanFord(weights,distance);
    Print_lengths(distance);
}

/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc BellmanFord.c -o BellmanFord } ; if ($?) { .\BellmanFord }
Enter no. vertices:5
Enter the the graph in matrix format:
0 6 5 0 0
0 0 0 -1 0
0 -2 0 4 3
0 0 0 0 3
0 0 0 0 0
Vertex   Distance
1        0
2        3
3        5
4        2
5        5
*/