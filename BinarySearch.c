#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int size,int key)
{
	int left = 0;
	int right = size-1;
	int middle;
	
	while(left <= right)
	{
		middle = (left+right)/2;
		if (key == arr[middle])
		{
			return middle;
		}
		else if(key >= arr[middle])
		{
			left = middle+1;
		}
		else
		{
			right = middle-1;
		}
	}
	return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr,size, x);
    (result == -1) ? printf("Element is not present"
                            " in array")
                   : printf("Element is present at "
                            "index %d",
                            result);
    return 0;
}
