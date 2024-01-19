#include <stdio.h>
#include <stdlib.h>

typedef struct q{
	int item;
	struct q *next;
}queue;

queue *front = NULL, *last = NULL;

int enqueue(int item)
{
	queue *p;
	p = (queue *)malloc(sizeof(queue));
	if (p == NULL)
	{
		printf("Memory is full\n");
		return -1;
	}
	p->item = item;
	p->next = NULL;
	if (front == NULL)
	{
		//if queue is empty after enqueue, it has 1 element
		front = p;
		last = p;
	}
	else{
		last->next = p;
		last = p;
	}
	return 1;
}

int dequeue()
{
	queue *p;
	int item;
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	p = front;
	front = front->next;
	if (front == NULL)
	{
		last = NULL;
	}
	item = p->item;
	free(p);
	return item;
}

void reset()
{
	queue *p;
	p = front;
	while(p){
		front = front->next;
		free(p);
		p = front;
	}
	last = NULL;
}

queue *isEmpty()
{
	return front,last = NULL;
}

