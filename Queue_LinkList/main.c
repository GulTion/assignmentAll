#include "header.h"

int main(){
	Queue q;
	q.enqueue(46);
	q.enqueue(45);
	q.dequeue();
	q.enqueue(49);
	q.enqueue(79);
	q.dequeue();
	q.print();
	return 0;
}