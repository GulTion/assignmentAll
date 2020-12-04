#include <stdio.h>
#include <stdlib.h>

typedef struct Node nn,*N;


struct Node{
	int data;
	N next;
};
N node(int data){
	N t = (N)malloc(sizeof(nn));
	t->data = data;t->next=NULL;
	return t;
}
struct Queue{
	N head=NULL;
	N tail =NULL;
	bool isEmpty();
	void enqueue(int data);
	void print();
	int dequeue();
};

bool Queue::isEmpty(){
	return (head==NULL);
}

void Queue::enqueue(int data){
	N t = node(data);
	if(head==NULL){
		head = tail = t;
	}else{
		tail->next = t;
		tail = t;
	}
}

void Queue::print(){
	N t=head;
	printf("Queue : ");
	while(t!=NULL){
		printf("%d->", t->data);
		t=t->next;
	}
	printf("NULL\n");
}

int Queue::dequeue(){
	N t=head;int data;
	head = head->next;
	data = t->data;
	free(t);
	return data;
}