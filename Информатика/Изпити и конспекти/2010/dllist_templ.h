#include <cstdio>

template <typename T>
struct LElem {
  double data;
  LElem<T> *next;
  LElem<T> *prev;
};

template <typename T>
class DLList {
private:
  LElem<T>* start;
  // указател към началото на списъка
  LElem<T>* end;
  // указател към края на списъка
  LElem<T>* forwardIter;
  // итератор за обхождане напред
  LElem<T>* backwardIter; // итератор за обхождане назад
public:
  // функции от голямата четворка
  DLList();
  DLList(DLList<T> const&);
  DLList<T>& operator=(DLList<T> const&);
  ~DLList();
  // вмъква числото x пред елемента, сочен от p
  void insertBefore(LElem<T>* p, double x);
  // вмъква числото x след елемента, сочен от p
  void insertAfter(LElem<T>* p, double x);
  // изтрива елемента, сочен от p от списъка
  // и го записва в x
  void deleteElem(LElem<T>* p, double& x);
  // установява forwardIter да сочи към началото на списъка
  // или към елемента, сочен от p, ако за p е зададена
  // ненулева стойност
  void startForward(LElem<T>* p = NULL);
  // установява backwardIter да сочи към края на списъка
  // или към елемента, сочен от p, ако за p е зададена
  // ненулева стойност
  void startBackward(LElem<T>* p=NULL);
  // премества forwardIter напред и връща старата му стойност
  LElem<T>* nextForward();
  // премества backwardIter назад и връща старата му стойност
  LElem<T>* nextBackward();

  void print() {
	  for(startForward(); forwardIter != NULL; nextForward()) {
		  printf("%f \n", forwardIter->data);
	  }
  }
};

