#include <stdio.h>

typedef struct st{
    int student_id;
    char name[15];
    char surname[15];
    char department[40];
    float gpa;
}student;

int secondaryKeySearch(student arr[], int n,int result[],char *key){
    int i=0,k;
    for(k=0;k<n;k++){
        if(strcmp(arr[k].surname,key)==0){
            //found, insert into Result array
            Result[i]=k;
            i++;
        }
    }
    return i;
}

int main(){
    return 0;
}