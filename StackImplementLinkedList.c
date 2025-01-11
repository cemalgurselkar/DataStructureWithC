#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int item;
    struct s *next;
}stack;

stack *sp = NULL;

int push(int item){
    stack *p;
    p = (stack *)malloc(sizeof(stack));

    if (p == NULL){
        printf("Stack is empty! \n");
        return -1;
    }
    p->item = item;
    p->next = sp;
    sp = p;
    return 0;
}

int pop(){
    stack *p;
    int i;
    if (sp == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    p = sp;
    i = sp->item;
    sp = sp->next;
    free(p);
    return i;
}

void reset(){
    stack *p;
    while(sp != NULL){
        p = sp;
        sp = sp->next;
        free(p);
    }
    printf("Stack has been emptied!!\n");
}

stack *top(){
    return sp;
}

int size(){
    stack *p;
    int i = 0;
    p = sp;
    while (p){
        i++;
        p = p->next;
    }
    return i;
}

stack *isEmpty(){
    return sp;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(52);
    push(67);

    printf("Top item: %d\n", top()->item);
    printf("Stack size: %d\n", size());

    printf("Popped item: %d\n", pop());
    printf("Stack size after pop: %d\n", size());

    reset();
    return 0;
}