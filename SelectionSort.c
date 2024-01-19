#include <stdio.h>
void selectionSort(int arr[],int size)
{
	int i,index,j,min;
	for(i=0;i<(size-1);i++)
	{
		min=arr[size-1];
		index = size-1;
		for(j=i;j<(size-1);j++)
		{
			if(arr[j]<min)
			{
				min = arr[j];
				index = j;
			}
		}
		if (i != index)
		{
			arr[index] = arr[i];
			arr[i] = min;
		}
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
	selectionSort(arr,size);
	printf("The sorted list:\n");
	print(arr,size);
	return 0;
}
