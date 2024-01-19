#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[],int left,int right)
{
	int k,j,q,temp;
	//partition the array into two parts
	k = left;
	j = right;
	
	q = arr[(left+right)/2]; //pivot
	
	do{
		while((arr[k]<q) && (k<right))
		{
			k++;
		}
		while((arr[j]>q) && (j > left))
		{
			j--;
		}
		if(k<=j)
		{
			//exchange arr[k] & arr[j]
			temp = arr[k];
			arr[k] = arr[j];
			arr[j] = temp;
			k++;
			j--;
		}
	}while(k<=j);
	//Sort each part using quickSort
	if (left < j)
	{
		quickSort(arr,left,j);
	}
	if(k < right)
	{
		quickSort(arr,k,right);
	}
}

void print(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	int arr[] = {6,1,9,4,16,12,26,33,21,18,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr,0,size-1);
	printf("The sorted list:\n");
	print(arr,size);
	return 0;
}
