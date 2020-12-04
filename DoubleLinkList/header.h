#include <stdio.h>
#include <stdlib.h>
typedef struct Node n,*nn;
typedef struct DoubleLinkList DoubleLinkList;
struct Node{
	int data;
	nn next=NULL;
	nn prev = NULL;
};


nn node(int data){
		nn t = (nn)malloc(sizeof(n));
		t->data = data;
		t->next = NULL;
		t->prev=NULL;
		return t;
	}

struct DoubleLinkList{
	nn head=NULL;
	nn tail = NULL;
	int size=0;
	void insert(int data);
	void print();
	int remove(int loc);
	void insert(int data, int loc);
	int search(int data);
	void merge(DoubleLinkList a);
};
void DoubleLinkList::merge(DoubleLinkList a){
	tail->next = a.head;
	a.head->prev = tail; 
	size += a.size;
}


void DoubleLinkList::insert(int data){
	nn t = node(data);

	if(head==NULL)
		head = tail = t;
	else{
		tail->next= t;
		t->prev = tail;
		tail = t;
	}
	size++;
}
void DoubleLinkList::insert(int data,int loc){
	nn t = node(data);
	nn h = head;
	if(loc<=size){
		if(loc==0){
			t->next = head;
			head->prev = t;
			head = t;
		}if(loc>0){
			while(--loc){
				h=h->next;
	}
		t->next = h->next;
		h->next->prev = t;
		t->prev = h;
		h->next = t;

		}
		size++;
	
}
	else printf("Warning : Invalid Index !");
}

void DoubleLinkList::print(){
	nn t=head;
	printf("DoubleLinkList:");
	while(t!=NULL){
		printf("%d⇔", t->data);
		t=t->next;
	}
	printf("NULL\n");
}

int DoubleLinkList::remove(int loc){

	nn t=head,tmp;
	int _data=-1;
	if(loc<size){
		if(loc==0){
			tmp = head;
			head = head->next;
			head->prev = NULL;
			_data = tmp->data;
			free(tmp);
		}
		if(loc>0){
		while(t!=NULL&&(loc-1)){
			t=t->next;
			loc--;
		}
		tmp = t->next;
		t->next=tmp->next;
		t->next->prev = t;
		_data = tmp->data;
		free(tmp);

	};
	size--;
	}
	else
		printf("Warning: Invalid index ! ");

	return _data;
}

int DoubleLinkList::search(int data){
	int index = -1;
	nn t= head;
	int i=0;
	while(t!=NULL) {
	    if(t->data == data)
	    	index = i;
	    t=t->next;
	    i++;
	}
	return index;
}
