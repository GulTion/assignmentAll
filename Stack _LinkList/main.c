#include "header.h"

int main(){
	Stack s;
	printf("isEmpty:%s\n", s.isEmpty?"true":"false");
	s.push(45);
	s.push(95);
	s.push(35);
	s.push(85);
	printf("Pop:%d\n", s.pop());
	
	s.push(15);
	printf("Top:%d\n", s.top);
	printf("isEmpty:%s\n", s.isEmpty?"true":"false");
	s.print();

	return 0;
}