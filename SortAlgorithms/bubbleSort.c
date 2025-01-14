#include <stdio.h>

void bubbleSort(int arr[], int n){
    int temp, move, k;
    for (move=0;move<(n-1);move++){
        for(k=0;k<(n-1-move);k++){
            if (arr[k]>arr[k+1]){
                temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
}

void print_array(int arr[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {5,1,3,2,19,11,18,13,25,21,38,23,26,30,41};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,size);
    print_array(arr,size);
    return 0;
}