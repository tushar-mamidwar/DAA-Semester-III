#include<stdio.h>
void merge(int arr[],int start,int end,int middle)
{
	int len1=middle-start+1;
	int len2=end - middle;

	int left[len1];
	int i;
	for(i=0;i<len1;i++)
	{
		left[i]=arr[start+i];
	}
	int right[len2];
	for(i=0;i<len2;i++)
	{
		right[i]=arr[middle+1+i];
	}
	i=0;
	int j=0,k=start;

	while(i<len1 && j<len2)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i];
			i++;
			k++;
		}
		else
		{
			arr[k]=right[j];
			j++;
			k++;
		}
	}
	
	while(i<len1)
	{
		arr[k]=left[i];
		i++;
		k++;

	}
	while(j<len2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[],int start, int end)
{
	if(start<end)
	{
		int middle = (start+(end-1))/2;
		merge_sort(arr,start,middle);
		merge_sort(arr,middle+1,end);
		merge(arr,start,end,middle);
	}
}
void print(int arr[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}

}
void main()
{
	int i;
	int len;
	printf("Enter the size of array:");
	scanf("%d",&len);
	int arr[len];
	printf("Enter %d array elements:",len);
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,len-1);
	print(arr,len);
}


/*
**********OUTPUT**********
C:\study material\Daa> cd "c:\study material\Daa\" ; if ($?) { gcc MergeSort.c -o MergeSort } ; if ($?) { .\MergeSort }
Enter the size of array:6
Enter 6 array elements:5 9 2 7 1 13
1       2       5       7       9       13
*/