#include "header.h"

int main(){
	CircularLinkList l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);

	CircularLinkList b;
	b.insert(5);
	b.insert(6);
	b.insert(7);
	b.insert(8);

	
	l.merge(b);
	printf("%d is at %d index\n",7, l.search(7));
	l.print();
	return 0;
}