#include <stdio.h>
#include <stdlib.h>
typedef struct Node n,*nn;
typedef struct CircularLinkList CircularLinkList;
struct Node{
	int data;
	nn next=NULL;
};


nn node(int data){
		nn t = (nn)malloc(sizeof(n));
		t->data = data;
		t->next = NULL;
		return t;
	}

struct CircularLinkList{
	nn head=NULL;
	nn tail = NULL;
	int size=0;
	void insert(int data);
	void print();
	int remove(int loc);
	void insert(int data, int loc);
	int search(int data);
	void merge(CircularLinkList a);
};

void CircularLinkList::merge(CircularLinkList a){
	tail->next = a.head;
	a.tail->next = head;
	size += a.size;
}


void CircularLinkList::insert(int data){
	nn t = node(data);

	if(head==NULL){
		head = tail = t;
		tail->next = head;
	}
	else{
		tail->next= t;
		tail = t;
		tail->next = head;

	}
	size++;
}
void CircularLinkList::insert(int data,int loc){
	nn t = node(data);
	nn h = head;
	if(loc<=size){
		if(loc==0){
			t->next = head;
			head = t;
			tail->next = head;
		}if(loc>0){
			while(--loc){
				h=h->next;
	}
		t->next = h->next;
		h->next = t;
		tail->next = head;

		}
		size++;
	
}
	else printf("Warning : Invalid Index !");
}

void CircularLinkList::print(){
	nn t=head;
	printf("CircularLinkList:");
	while(t->next!=head){
		printf("%d->", t->data);
		t=t->next;
	}
	printf("NULL\n");
}

int CircularLinkList::remove(int loc){

	nn t=head,tmp;
	int _data=-1;
	if(loc<size){
		if(loc==0){
			tmp = head;
			head = head->next;
			_data = tmp->data;
			free(tmp);
		}
		if(loc>0){
		while(t->next!=head&&(loc-1)){
			t=t->next;
			loc--;
		}
		tmp = t->next;
		t->next=tmp->next;
		_data = tmp->data;
		free(tmp);

	};
	size--;
	}
	else
		printf("Warning: Invalid index ! ");

	return _data;
}

int CircularLinkList::search(int data){
	int index = -1;
	nn t= head;
	int i=0;
	while(t->next!=head) {
	    if(t->data == data)
	    	index = i;
	    t=t->next;
	    i++;
	}
	return index;
}
