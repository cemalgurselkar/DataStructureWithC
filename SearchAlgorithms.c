#include <stdio.h>

int sequentialSearch(int arr[],int key, int n){
    int i;
    for (i=0;i<n;i++){
        if (key == arr[i]){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int key, int n){
    int left = 0;
    int right = n-1;
    int middle;

    while (left<=right){
        middle = (left+right)/2;
        if (key == arr[middle]){
            return middle;
        }
        else if (key > arr[middle]){
            left = middle+1;
        }
        else{
            right = middle-1;
        }
    }
    return -1;
}


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key, result_2;
    printf("Enter the value you want search:\n");
    scanf("%d",&key);
    // result = sequentialSearch(arr,key,size); (Linear Search Algorithms)
    result_2 = binarySearch(arr,key,size);
    if (result_2 == -1){
        printf("The value is not here!!!\n");
    }
    else{
        printf("The value is ith index: %d\n", result_2);
    }
    return 0;
}