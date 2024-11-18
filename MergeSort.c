#include <stdio.h>
const int max_size = 50;

void merge(int arr[], int left, int k, int right){
    int i,j;
    int l = 0;
    int temp_arr[max_size];

    for (i=left, j=k+1; (i <= k) && (j <= right); ){
        if (arr[i] < arr[j]){
            temp_arr[l] = arr[i];
            i++;
            l++;
        }
        else{
            temp_arr[l] = arr[j];
            j++;
            l++;
        }
    }
    while (i <= k){
        temp_arr[l] = arr[i];
        i++;
        l++;
    }
    while (j <= right){
        temp_arr[l] = arr[j];
        j++;
        l++;
    }

    for (i = left, l=0; i <= right; i++, l++){
        arr[i] = temp_arr[l];
    }
}

void mergeSort(int arr[], int left, int right){
    int k;
    if (left < right){
        k = (left + right)/2; //index of midpoint
        mergeSort(arr,left,k);
        mergeSort(arr,k+1,right);
        // merge the two halves
        merge(arr, left, k, right);
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
    int arr[] = {8,1,5,2,4,3,15,11,28,25,21,24,23};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,0,size-1); // left=0, right = size-1 olmalıdır!!!
    print_array(arr, size);
    return 0;
}