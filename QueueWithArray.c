#include <stdio.h>

#define N 500

int Q[N];
int last = 0;

int enqueue(int item){
    if (last == N){
        printf("Queue is full!!\n");
        return -1;
    }
    Q[last] = item;
    last++;
    return 0;
}

int dequeue(){
    int item, i;

    if (last == 0){
        printf("Queue is empty!\n");
        return -1;
    }
    item = Q[0];

    for (i=1;i<last;i++){
        Q[i-1] = Q[i];
    }
    last--;
    return item;
}

void reset(){
    last = 0;
}

int isEmpty(){
    if (last == 0){
        return 1;
    }
    return 0;
}

int main(){
    enqueue(15);
    enqueue(56);
    enqueue(61);
    enqueue(63);
    enqueue(65);

    while (!isEmpty()){
        printf("%d ",dequeue());
    }
    printf("\n");
    return 0;
}