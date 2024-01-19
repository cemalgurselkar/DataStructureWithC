#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[],int size)
{
	int i,k,key;
	for(i=1;i<size;i++)
	{
		key = arr[i];
		for(k = i-1;k>=0 && key<=arr[k];k--){
			arr[k+1] = arr[k]; //shift operation
		}
		arr[k+1] = key; //insert key
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
	insertionSort(arr,size);
	printf("The sorted list:\n");
	print(arr,size);
	return 0;
}

