#include<stdio.h>
#include<limits.h>
int len;
void printMST(int finalEdges[][2],int cost[][len])
{
    int i;
    printf("Edges   weights\n");
    for(i=0;i<len;i++)
    {
        printf("%d----%d = %d\n",finalEdges[i][0]+1,finalEdges[i][1]+1,cost[finalEdges[i][0]][finalEdges[i][1]]);
    }
}
void mincost(int cost[][len],int *k,int *l)
{
    int i=0,j=0;
    int min=INT_MAX;
    for(i=0;i<len;i++)
        for(j=0;j<len;j++)
            if(cost[i][j]<min && cost[i][j])
            {
                min=cost[i][j];
                *k=i;
                *l=j;
            }
}

void prims(int cost[][len],int finalEdges[][2],int near[])
{
    int k,l;
    mincost(cost,&k,&l);
    finalEdges[0][0]=k;
    finalEdges[0][1]=l;
    int i,j;
    for(i=0;i<len;i++)
    {
        
        if(cost[i][l]<cost[i][k] && cost[i][l] || cost[i][k]==0)
            near[i]=l;
        else
            near[i]=k;
    }
    near[k]=near[l]=-1;
    int min=INT_MAX,min_index;
    for(i=1;i<len-1;i++)
    {
        min=INT_MAX;
        for(j=0;j<len;j++)
        {
            if(near[j]!=-1 && min>cost[j][near[j]] && cost[j][near[j]])
            {
                min_index=j;
                min=cost[j][near[j]];
            }
        }
        finalEdges[i][0]=min_index;
        finalEdges[i][1]=near[min_index];
        near[min_index]=-1;
        
        for(k=0;k<len;k++)
        {
            if(near[k]!=-1 && cost[k][near[k]]>cost[k][min_index] && cost[k][min_index])
                near[k]=min_index;
        }
        
    }
    printMST(finalEdges,cost);
    

}
void main()
{
    printf("Enter no. of vertices:");
    scanf("%d",&len);
    int cost[len][len],i,j;
    int finalEdges[len][2];
    int near[len];
    printf("Enter the diagram in the form of adjacency cost:\n");
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    prims(cost,finalEdges,near);

}

/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc primsBookAlgo.c -o primsBookAlgo } ; if ($?) { .\primsBookAlgo }
Enter no. of vertices:cd "c:\study material\Daa\" ; if ($?) { gcc primsBookAlgo.c -o primsBookAlgo } ; if ($?) { .\primsBookAlgo }
Enter the diagram in the form of adjacency cost:
Edges   weights
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc primsBookAlgo.c -o primsBookAlgo } ; if ($?) { .\primsBookAlgo }
Enter no. of vertices:5
Enter the diagram in the form of adjacency cost:
0 4 9 8 0
4 0 4 1 0
9 4 0 3 3
8 1 3 0 4
0 0 3 4 0
Edges   weights
2----4 = 1
3----4 = 3
5----3 = 3
1----2 = 4
*/