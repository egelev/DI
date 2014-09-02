#include <cstdio>
#include "dllist_templ.hpp"

int main() {
	double elems[] = {1, 2, 5, 6, 10};
	int n = sizeof(elems) / sizeof(double);

	DLList<double> dl;
	dl.insertAfter(NULL, elems[0]);
	dl.startForward();
	LElem<double> *current = dl.nextForward();

	for(int i = 1; i < n; i++) {

	dl.insertAfter(current, elems[i]);
	current = current->next;
	}

	dl.startForward();
	dl.print();
}
