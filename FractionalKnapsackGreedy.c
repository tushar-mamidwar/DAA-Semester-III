#include<stdio.h>
//swap(), partition() and quicksort() functions are part of quick sort algorithm
//to sort the val_wt[][] and ratio[] arrays according to values of ratio[]
void swap(float *num1, float *num2)
{
    float temp=*num1;
    *num1=*num2;
    *num2=temp;
}
int partition(float val_wt[][2],float ratio[],int start,int end)
{
    int pivot=ratio[end];
    int pindex=start;
    int i=start;

    for(i=start;i<end;i++)
    {
        if(ratio[i]<pivot)
        {
            
            swap(&ratio[i],&ratio[pindex]);
            swap(&val_wt[i][0],&val_wt[pindex][0]);
            swap(&val_wt[i][1],&val_wt[pindex][1]);
            pindex++;
        }
    }
    swap(&ratio[end],&ratio[pindex]);
    swap(&val_wt[end][0],&val_wt[pindex][0]);
    swap(&val_wt[end][1],&val_wt[pindex][1]);
    return pindex;
}

void quicksort(float val_wt[][2],float ratio[],int start,int end)
{
    if(start<end)
    {
        int p = partition(val_wt,ratio,start,end);
        quicksort(val_wt,ratio,start,p-1);
        quicksort(val_wt,ratio,p+1,end);
    }
}
float knapsack(float val_wt[][2],float ratio[],int len,float cap)
{
    quicksort(val_wt,ratio,0,len-1);

    int i;
    float max_profit=0;
    for(i=len-1;i>=0;i--)
    {
        //add the item to the knapsack if weight of the item is less than remaining capacity of knapsack
        if(val_wt[i][1]<=cap)
        {
            cap-=val_wt[i][1];
            max_profit+=val_wt[i][0];
        }
        //if there is not enough capacity remaining in the knapsack for the item 
        //add fraction of that item weight of which should be equal to remaining capacity
        else
        {
            max_profit+=val_wt[i][0]*cap/val_wt[i][1];
            break;
        }
        
    }
    return max_profit;
}
void print(float val_wt[][2],float arr2[],int len)
{
    int i;
    printf("value:\n");
    for(i=0;i<len;i++)
    {
        printf("%f\t", val_wt[i][0]);
    }

    printf("\n\nweights:\n");
    for(i=0;i<len;i++)
    {
        printf("%f\t",val_wt[i][1]);
    }
    
    printf("\n\nratio:\n");
    for(i=0;i<len;i++)
    {
        printf("%f\t",arr2[i]);
    }
    
}

void main()
{
    int len; //variable for no. of items
    printf("Enter no. of items:");
    scanf("%d",&len);
    int i;
    float val_wt[len][2]; //2d array to store values of profit and weight of respective items
    printf("enter maximum weight capacity:");
    float cap; //variable for maximum capacity
    scanf("%f",&cap);

    printf("Enter values of %d item in pairs of profit and weight:\n",len);
    for(i=0;i<len;i++)
    {
        scanf("%f%f",&val_wt[i][0],&val_wt[i][1]);
    }

    float ratio[len]; //Array to store profit/weight ratio of respective item

    for(i=0;i<len;i++)
    {
        ratio[i]=val_wt[i][0]/val_wt[i][1];
    }
    float max_profit=knapsack(val_wt,ratio,len,cap);
    print(val_wt,ratio,len);
    printf("\n\nmaximum profit:%f\n",max_profit);
}

/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc FractionalKnapsackGreedy.c -o FractionalKnapsackGreedy } ; if ($?) { .\FractionalKnapsackGreedy }
Enter no. of items:5
enter maximum weight capacity:20
Enter values of 5 item in pairs of profit and weight:
52 7
20 9
60 3
5 6
10 4
value:
5.000000        10.000000       20.000000       52.000000       60.000000

weights:
6.000000        4.000000        9.000000        7.000000        3.000000

ratio:
0.833333        2.500000        2.222222        7.428571        20.000000

maximum profit:134.500000
*/