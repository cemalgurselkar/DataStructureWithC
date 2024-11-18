#include <stdio.h>

void quickSort(int arr[],int left, int right){
    int k, j, q, temp;
    
    //partition the array into two parts
    k = left;
    j = right;

    q = arr[(left+right)/2]; //pivot

    while (k <= j){
        while ((arr[k]<q) && (k < right)){
            k++;
        }
        while ((arr[j]>q) && (j > left)){
            j--;
        }
        if (k <= j){//exchange arr[k] and arr[j]
            temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
            k++;
            j--;            
        }
    }
    //Sort each part using quicksort
    if (left < j){
        quickSort(arr, left, j);
    }
    if (k < right){
        quickSort(arr,k,right);
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
    int arr[] = {6,1,2,5,16,9,7,24,10,33,11,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    print_array(arr,size);
    return 0;
}