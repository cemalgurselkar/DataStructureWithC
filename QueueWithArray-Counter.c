#include <stdio.h>
#define N 500

int q[N];
int front = 0, last = 0, count=0;

int enqueue(int item){
    if (count >= N){
        printf("Queue is full\n");
        return -1;
    }
    q[last] = item;
    last = (last + 1) % N;
    count++;
    return 0;
}

int dequeue(){
    int item;

    if(count == 0){
        printf("Queue is empty\n");
        return -1;
    }
    item = q[front];
    front = (front + 1) % N;
    count--;
    return item;
}

void reset(){
    front = 0;
    last = 0;
    count = 0;
}

int isEmpty(){
    if (count == 0){
        return 1;
    }
    return 0;
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    while (!isEmpty()){
        printf("%d ",dequeue());
    }
    printf("\n");
    return 0;
}