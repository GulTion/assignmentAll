#include "header.h"

int main(){
	LinkList l;
	l.insert(46);
	l.insert(894);
	l.insert(985);
	l.insert(84);

	LinkList b;
	b.insert(46);
	b.insert(894);
	b.insert(985);
	b.insert(84);
	b.remove(46);
	
	l.merge(b);
	
	l.print();
	return 0;
}