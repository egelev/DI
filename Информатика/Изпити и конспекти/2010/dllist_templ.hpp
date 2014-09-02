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
  DLList() {
    start = end = forwardIter = backwardIter = NULL;
  }

  ~DLList() {
	  double tmp;
	  startForward();
	  while(forwardIter) {
		deleteElem(forwardIter, tmp);
		nextForward();
	  }
	  start = end = forwardIter = backwardIter = NULL;
	}

  DLList(DLList<T> const& dl) {
	  LElem<T>* current;
	  current = dl.start;

	  while((current= current->next) != NULL) {
	    insertAfter(nextForward(), current->data);
	  }
	}


  DLList<T>& operator=(DLList<T> const& dl) {
		if(&dl == this) {
			return *this;
		}

		double tmp;
		while(start) {
			deleteElem(start, tmp);
		}

		LElem<T> *current = dl.start;
		while(current) {
			insertAfter(current, current->data);
			current = current->next;
		}

		return *this;
	}

  // вмъква числото x пред елемента, сочен от p
  void insertBefore(LElem<T>* p, T x) {
	  LElem<T>* tmp = new LElem<T>();
	  tmp->data = x;
	  if(p == NULL) {
	    if(end == NULL) {
	      end = tmp;
	      start = end;
	    } else {
	      tmp->prev = end;
	      end->next = tmp;
	      end = tmp;
	    }
	  } else {
	    if(p->prev == NULL) {
	      p->prev = tmp;
	      tmp->next = p;
	      start = tmp;
	    } else {
	      tmp->prev = p->prev;
	      p->prev->next = tmp;

	      tmp->next = p;
	      p->prev = tmp;
	    }
	  }
	}

  // вмъква числото x след елемента, сочен от p
  void insertAfter(LElem<T>* p, T x) {
	  LElem<T>* tmp = new LElem<T>();
	  tmp->data = x;
	  if(p == NULL) {
	    if(start == NULL) {
	      start = tmp;
	      end = start;
	    } else {
	      tmp->next = start;
	      start->prev = tmp;
	      start = tmp;
	    }
	  } else {
	    if(p->next == NULL) {
	      p->next = tmp;
	      tmp->prev = p;
	      end = tmp;
	    } else {
	      tmp->next = p->next;
	      p->next->prev = tmp;

	      tmp->prev = p;
	      p->next = tmp;
	    }
	  }
	}

  // изтрива елемента, сочен от p от списъка
  // и го записва в x
  void deleteElem(LElem<T>* p, T & x) {
	  x = p->data;
	  if(p == forwardIter) {
	    forwardIter = start;
	  }
	  if(p == backwardIter) {
	    backwardIter = end;
	  }
	  if(p->prev == NULL) {
	    if(p->next == NULL) {
	      start = end = forwardIter = backwardIter = NULL;
	      delete p;
	    } else {
	      start = p->next;
	      start->prev = NULL;
	      delete p;
	      if(start->next == NULL) {
	        end = start;
	      }
	    }
	  } else if(p->next == NULL) {
	    end = p->prev;
	    end->next = NULL;
	    delete p;
	    if(end->prev == NULL) {
	      start = end;
	    }
	  } else {
	    LElem<T> *tmp = p;
	    tmp->next->prev = tmp->prev;
	    tmp->prev->next = tmp->next;
	    delete tmp;
	  }
	}

  // установява forwardIter да сочи към началото на списъка
  // или към елемента, сочен от p, ако за p е зададена
  // ненулева стойност
  void startForward(LElem<T>* p = NULL){
	  if(p == NULL) {
		  forwardIter = start;
	  } else {
		  forwardIter = p;
	  }
	}

  // установява backwardIter да сочи към края на списъка
  // или към елемента, сочен от p, ако за p е зададена
  // ненулева стойност
  void startBackward(LElem<T>* p=NULL) {
	  if(p == NULL) {
	    backwardIter = end;
	  } else {
	    backwardIter = p;
	  }
	}

  // премества forwardIter напред и връща старата му стойност
  LElem<T>* nextForward() {
	  if(forwardIter == NULL) {
	    return NULL;
	  } else {
	    LElem<T>* current = forwardIter;
	    forwardIter = forwardIter->next;
	    return current;
	  }
	}

  // премества backwardIter назад и връща старата му стойност
  LElem<T>* nextBackward() {
	  if(backwardIter == NULL) {
	    return NULL;
	  } else {
	    LElem<T>* current = backwardIter;
	    backwardIter = backwardIter->prev;
	    return current;
	  }
	}


  void print() {
	  for(startForward(); forwardIter != NULL; nextForward()) {
		  printf("%f \n", forwardIter->data);
	  }
  }
};

