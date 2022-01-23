#include<stdio.h>
#include<limits.h>
int n=0;
void Print(int distance[])
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d-%d\n",i,distance[i]);
    }
}
void dijkstras(int cost[][n],int distance[],int visited[])
{
    int i,w;
    int min=INT_MAX,min_index;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        distance[i]=cost[0][i];
    }
    visited[0]=1;
    distance[0]=0;
    int k;
    for(k=1;k<n-1;k++)
    {    
        min=INT_MAX;
        for(w=0;w<n;w++)
        {
            if(distance[w]<min && !visited[w])
            {
                min = distance[w];
                min_index=w;
            }
        }
        visited[min_index]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && distance[i]>distance[min_index]+cost[min_index][i])
            {
                distance[i]=distance[min_index]+cost[min_index][i];
            }
        }
    }
    Print(distance);
        
}
void main()
{
    int i,j;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    int cost[n][n],distance[n],visited[n];
    printf("Enter diagram in matrix form:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INT_MAX;
        }
    }
    dijkstras(cost,distance,visited);

}