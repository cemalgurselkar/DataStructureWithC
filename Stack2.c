#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}stack;

stack *top=0;

void push(int x)
{
	stack *newnode;
	newnode = (stack *)malloc(sizeof(stack));
	newnode->data = x;
	newnode->link = top;
	top=newnode;
}

void display()
{
	stack *temp;
	temp=top;
	if(top==0)
	{
		printf("List is empty.\n");
	}
	else{
		while(temp!=0)
		{
			printf("%d \n",temp->data);
			temp = temp->link;
		}
	}
}

void peek()
{
	if(top==0)
	{
		printf("List is empty.\n");
	}
	else{
		printf("Top element is %d \n",top->data);
	}
}

void pop()
{
	stack *temp;
	temp=top;
	if(top==0)
	{
		printf("List is empty.\n");
	}
	else{
		printf("Popped element is %d \n",top->data);
		top = top->link;
		free(temp);
	}
}

int main()
{
	push(2);
	push(3);
	push(10);
	display();
	peek();
	pop();
	return 0;
}
