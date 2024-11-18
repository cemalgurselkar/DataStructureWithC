#include <stdio.h>

void selectionSort(int arr[],int n){
    int i,j,min,index;
    for(i=0;i<n-1;i++){
        min = arr[n-1];
        index = n-1;
        for(j=i;j<(n-1);j++){
            if(arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        if (i != index){
            arr[index] = arr[i];
            arr[i] = min;
        }
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
    int arr[] = {31,2,57,1,5,3,9,7,14,22,8,16,11,29,21};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr,size);
    print_array(arr,size);
    return 0;
}