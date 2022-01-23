#include<stdio.h>
void swap(int *num1, int *num2)
{
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}
int partition(int arr[],int start,int end)
{
    int pivot=arr[end];
    int pindex=start;
    int i=start;
    for(i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            
            swap(&arr[i],&arr[pindex]);
            pindex++;
        }
    }
    swap(&arr[end],&arr[pindex]);
    return pindex;
}

void quicksort(int arr[],int start,int end)
{
    if(start<end)
    {
        int p = partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}
void print(int arr[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void main()
{
    
    int i;
    int len;
    printf("Enter the size of array:");
    scanf("%d",&len);
    int arr[len];
    printf("\nEnter the array of size %d:",len);
    for(i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,len-1);
    print(arr,len);
}

/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc quick_sort.c -o quick_sort } ; if ($?) { .\quick_sort }
Enter the size of array:6

Enter the array of size 6:5 9 2 7 1 13
1       2       5       7       9       13

*/