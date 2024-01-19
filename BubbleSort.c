#include <stdio.h>

void bubbleSort(int arr[],int size)
{
	int temp,k,move;
	for(move=0;move<(size-1);move++)
	{
		for(k=0;k<(size-1-move);k++)
		{
			if(arr[k]>arr[k+1])
			{
				
				//Exchange the values
				temp=arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
				
			}
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
	bubbleSort(arr,size);
	printf("The sorted list:\n");
	print(arr,size);
	return 0;
}
