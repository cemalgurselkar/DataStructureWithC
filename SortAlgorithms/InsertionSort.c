#include <stdio.h>

void insertionSort(int arr[], int n){
    int i,k,key;
    for (i=1;i<n;i++){
        key = arr[i];
        for(k=i-1;k>=0 && key<=arr[k];k--){
            arr[k+1] = arr[k]; // shift operation
        }
        arr[k+1] = key; // insert operations
    }
}
void print_array(int arr[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1,5,3,7,2,9,12,19,21,13};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    print_array(arr, size);
    return 0;
}