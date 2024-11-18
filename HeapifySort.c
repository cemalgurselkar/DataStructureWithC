#include <stdio.h>

int heap_size;

void heapify(int arr[], int i){
    int left_child = (2*i+1);
    int right_child = (2*i+2);
    int max, temp;
    // find the max of nodes left, right, and i
    if ((left_child<=heap_size) && (arr[left_child]>arr[i])){
       max = left_child;
    }
    else{
        max = i;
    }
    if ((right_child<=heap_size) && (arr[right_child]>arr[max])){
        max = right_child;
    }
    // if max is not the i th node, exchange
    if (max != i){
        temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
        heapify(arr, max);
    }
}

void build_heap(int arr[], int n){
    int i;
    heap_size = n-1;

    for(i=(n-1)/2;i>=0;i--)
{
    heapify(arr,i);
}
}

void heapSort(int arr[], int n){
    int i, temp;
    build_heap(arr,n);
    for(i=n-1;i>=1;i--){
        // exchange the root with the ith element
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heap_size--;
        heapify(arr,0);
    }
}

void print_array(int arr[],int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {7,1,5,3,2,6,15,11,13,20,14,33};
    int size = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,size);
    print_array(arr,size);
    return 0;
}