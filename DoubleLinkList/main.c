#include "header.h"

int main(){
	DoubleLinkList l;
	l.insert(46);
	l.insert(894);
	l.insert(985);
	l.insert(84);

	DoubleLinkList b;
	b.insert(46);
	b.insert(894);
	b.insert(985);
	b.insert(84);

	
	l.merge(b);
	printf("at:%d\n", l.size);
	l.print();
	return 0;
}