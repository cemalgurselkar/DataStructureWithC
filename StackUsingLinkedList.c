#include <stdio.h>
#include <stdlib.h>

typedef struct s{
	int item;
	struct s *next;
}stack;

stack *sp = NULL;

int push(int item)
{
	stack *p;
	p = (stack*)malloc(sizeof(stack));
	if(p == NULL)
	{
		printf("Error, not enough memory\n");
		return -1;
	}
	else{
		p->item = item;
		p->next = sp;
		sp = p;
		return 0;
	}
}

int pop(){
	stack *p;
	int i;
	if (sp == NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		p = sp;
		i = sp->item;
		sp = sp->next;
		free(p);
		return i;
	}
}

void reset()
{
	stack *p;
	while (sp != NULL)
	{
		p = sp;
		sp = sp->next;
		free(p);
	}
}

stack *top() //returns the address of the top element
{
	return sp;
}

int size()
{
	//Returns the # of elements in the stack
	stack *p;
	int i = 0;
	p = sp;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

stack *isEmpty()
{
	return sp == NULL;
}

//Driver Function
int main()
{
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(90);
	
	printf("The Stack is:\n");
	while (!isEmpty())
	{
		int data = pop();
		printf("%d ",data);
	}
	return 0;
}
