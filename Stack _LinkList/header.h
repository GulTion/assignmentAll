#include <stdio.h>
#include <stdlib.h>

typedef struct Node n,*nn;
typedef struct Stack Stack;
struct Node{
	int data;
	nn next=NULL;
};
nn node(int data){
	nn t = (nn)malloc(sizeof(nn));
	t->data = data;
	t->next = NULL;
	return t;
}
struct Stack{
	nn head=NULL;
	int size=0;
	int top=-1;
	bool isEmpty=true;
	void push(int data);
	int pop();
	void print();

};

void Stack::push(int data){
	nn t=node(data);
	t->next = head;
	head = t;
	top=head->data;
	isEmpty = head==NULL?true:false;
	size++;
}

int Stack::pop(){
	nn tmp;
	tmp=head;
	head=head->next;
	int _data = tmp->data;
	free(tmp);
	top=head->data;
	isEmpty = head==NULL?true:false;
	size--;
	return _data;
}

void Stack::print(){
	nn t = head;

	while(t!=NULL){
		printf("%d->", t->data);
		t=t->next;
	}
	printf("NULL\n");
}	

