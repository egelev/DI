#include <unistd.h>
#include <cstdio>

struct node {
  double data;
  node* next;
  node* prev;
};

class DLList {
private:
  node* start;
  // указател към началото на списъка
  node* end;
  // указател към края на списъка
  node* forwardIter;
  // итератор за обхождане напред
  node* backwardIter; // итератор за обхождане назад
public:
  // функции от голямата четворка
  DLList();
  DLList(DLList const&);
  DLList& operator=(DLList const&);
  ~DLList();
  // вмъква числото x пред елемента, сочен от p
  void insertBefore(node* p, double x);
  // вмъква числото x след елемента, сочен от p
  void insertAfter(node* p, double x);
  // изтрива елемента, сочен от p от списъка
  // и го записва в x
  void deleteElem(node* p, double& x);
  // установява forwardIter да сочи към началото на списъка
  // или към елемента, сочен от p, ако за p е зададена
  // ненулева стойност
  void startForward(node* p = NULL);
  // установява backwardIter да сочи към края на списъка
  // или към елемента, сочен от p, ако за p е зададена
  // ненулева стойност
  void startBackward(node* p=NULL);
  // премества forwardIter напред и връща старата му стойност
  node* nextForward();
  // премества backwardIter назад и връща старата му стойност
  node* nextBackward();

  void print() {
	  for(startForward(); forwardIter != NULL; nextForward()) {
		  printf("%f \n", forwardIter->data);
	  }
  }
};

