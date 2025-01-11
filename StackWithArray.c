#include <stdio.h>
#define N 500

int S[N];
int sp = 0;

int push(int item){
    if (sp >= N){
        printf("Stack is full, no insertion is possible\n");
        return -1;
    }
    S[sp] = item;
    sp++;
    return 0;
}

int pop(){
    if (sp <= 0){
        printf("Stack is empty\n");
        return -1;
    }
    sp--;
    return S[sp];
}

void reset(){
    sp = 0;
}

int top(){
    return (sp - 1);
}

int size(){
    return sp;
}

int isEmpty(){
    if (sp == 0){
        return 1;
    }
    return 0;
}


int main(){
    char c;
    printf("Enter a string: \n");
    while ((c = getchar()) != '\n'){
        push(c);
    }

    while (sp > 0){
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}