#include <stdio.h>
#include <stdlib.h>

typedef struct q
{
    int item;
    struct q *next;
}queue;

queue *front = NULL, *last = NULL;

int enqueue(int item){
    queue *p;
    p = (queue *)malloc(sizeof(queue));
    if (p == NULL){
        printf("Memory is full!\n");
        return -1;
    }

    p->item = item;
    p->next = NULL;

    if (front == NULL){
        front = p;
        last = p;
    }
    else{
        last->next = p;
        last = p;
    }
    return 0;
}

int dequeue(){
    queue *p;
    int item;

    if (front == NULL){
        printf("Queue is empty!\n");
        return -1;
    }

    p = front;
    front = front->next;

    if (front == NULL){
        last = NULL;
    }
    item = p->item;
    free(p);
    return item;
}

void reset(){
    queue *p;
    p = front;

    while (p){
        front = front->next;
        free(p);
        p = front;
    }
    last = NULL;
    printf("Queue has been emptied!!\n");
}

int isEmpty(){
    return front == NULL;
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(5);
    enqueue(7);
    enqueue(10);

    while (!isEmpty()){
        printf("%d ",dequeue());
    }
    printf("\n");
    return 0;
}