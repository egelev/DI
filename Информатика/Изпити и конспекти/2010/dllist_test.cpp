#include "dllist.h"
#include <cstdio>

int main() {
	DLList dl;
	dl.insertAfter(NULL, 5);
	dl.print();
	printf("Hello world");
}

