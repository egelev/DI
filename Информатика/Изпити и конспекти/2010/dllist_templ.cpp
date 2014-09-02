#include "dllist_templ.h"

template <typename T>
DLList<T>::DLList() {
  start = end = forwardIter = backwardIter = NULL;
}

template <typename T>
DLList<T>::~DLList() {
  double tmp;
  startForward();
  while(forwardIter) {
    deleteElem(forwardIter, tmp);
    nextForward();
  }
  start = end = forwardIter = backwardIter = NULL;
}

template <typename T>
DLList<T>::DLList(DLList<T> const & dl) {
  LElem<T>* current;
  current = dl.start;

  while((current= current->next) != NULL) {
    insertAfter(nextForward(), current->data);
  }
}

template <typename T>
DLList<T>& DLList<T>::operator=(DLList<T> const & dl) {
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

template <typename T>
void DLList<T>::deleteElem(LElem<T>* p, double& x) {
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

template <typename T>
void DLList<T>::insertAfter(LElem<T>* p, double x) {
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

template <typename T>
void DLList<T>::insertBefore(LElem<T>* p, double x) {
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

template <typename T>
void DLList<T>::startForward(LElem<T>* p) {
  if(p == NULL) {
	  forwardIter = start;
  } else {
	  forwardIter = p;
  }
}

template <typename T>
void DLList<T>::startBackward(LElem<T>* p) {
  if(p == NULL) {
    backwardIter = end;
  } else {
    backwardIter = p;
  }
}

template <typename T>
LElem<T>* DLList<T>::nextForward() {
  if(forwardIter == NULL) {
    return NULL;
  } else {
    LElem<T>* current = forwardIter;
    forwardIter = forwardIter->next;
    return current;
  }
}

template <typename T>
LElem<T>* DLList<T>::nextBackward() {
  if(backwardIter == NULL) {
    return NULL;
  } else {
    LElem<T>* current = backwardIter;
    backwardIter = backwardIter->prev;
    return current;
  }
}
