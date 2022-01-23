#include<stdio.h>
void swap(int *num1, int *num2)
{
    float temp=*num1;
    *num1=*num2;
    *num2=temp;
}
int partition(int job[],int deadline[],int arr[],int start,int end)
{
    int pivot=arr[end];
    int pindex=start;
    int i=start;

    for(i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            swap(&arr[i],&arr[pindex]);
            swap(&job[i],&job[pindex]);
            swap(&deadline[i],&deadline[pindex]);
            pindex++;
        }
    }
    swap(&arr[end],&arr[pindex]);
    swap(&job[end],&job[pindex]);
    swap(&deadline[end],&deadline[pindex]);
    return pindex;
}

void quicksort(int job[],int deadline[],int arr[],int start,int end)
{
    if(start<end)
    {
        int p = partition(job,deadline,arr,start,end);
        quicksort(job,deadline,arr,start,p-1);
        quicksort(job,deadline,arr,p+1,end);
    }
}
void job_sequencing(int job[],int deadline[],int profit[],int len)
{
    quicksort(job,deadline,profit,0,len-1);
    int i;
    int j;
    int finalProfit=0;
    int max=0;
    for(i=0;i<len;i++)
    {
        if(max<deadline[i])
        {
            max=deadline[i];
        }
    }

    int slot[max],selected[max];
    for(i=0;i<max;i++)
    { 
        slot[i]=0;
    }
    for(i=len-1;i>=0;i--)
    {
        for(j=deadline[i]-1;j>=0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                selected[j]=job[i];
                finalProfit+=profit[i];
                break;
            }
        }
    }
    printf("Job sequence:");
    for(i=0;i<max;i++)
    {
        printf("%d  ",selected[i]);
    }
    printf("\nMaximum Profit = %d\n",finalProfit);

    

}
void print(int job[],int deadline[],int profit[],int len)
{
    int i;
    printf("job names:\n");
    for(i=0;i<len;i++)
    {
        printf("%d\t",job[i]);
    }
    printf("\n\ndeadline:\n");
    for(i=0;i<len;i++)
    {
        printf("%d\t",deadline[i]);
    }
    printf("\n\nprofit:\n");
    for(i=0;i<len;i++)
    {
        printf("%d\t",profit[i]);
    }
}


void main()
{
    int len,i;
    printf("Enter the no. of jobs available:");
    scanf("%d",&len);
    printf("Enter job name, deadline and profit of %d jobs",len);
    int job[len],deadline[len],profit[len];
    for(i=0;i<len;i++)
    {
        scanf("%d%d%d",&job[i],&deadline[i],&profit[i]);
    }
    job_sequencing(job,deadline,profit,len);
    print(job,deadline,profit,len);
}
