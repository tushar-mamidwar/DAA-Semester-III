#include <stdio.h>
int max(int a, int b)
{
     return (a > b) ? a : b;
}
int knapSack(int capacity, int weight[], int val[], int len)
{
    int i, w;
    int Memory[len + 1][capacity + 1];
    for (i = 0; i <= len; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                Memory[i][w] = 0;
            else if (weight[i - 1] <= w)
                Memory[i][w] = max(val[i - 1] + Memory[i - 1][w - weight[i - 1]], Memory[i - 1][w]);
            else
                Memory[i][w] = Memory[i - 1][w];
        }
    }
    return Memory[len][capacity];
}
int main()
{
    int i, len, val[20], weight[20], capacity;

    printf("Enter no. of items:");
    scanf("%d", &len);

    printf("Enter size of knapsack:");
    scanf("%d", &capacity);

    printf("Enter value and weight of items in matrix form:\n");
    for (i = 0; i < len; ++i)
    {
        scanf("%d%d", &val[i], &weight[i]);
    }

    printf("Maximum profit : %d", knapSack(capacity, weight, val, len));
    return 0;
}