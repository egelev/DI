#include "dllist.h"

DLList::DLList() {
  start = end = forwardIter = backwardIter = NULL;
}

DLList::~DLList() {
  double tmp;
  startForward();
  while(forwardIter) {
    deleteElem(forwardIter, tmp);
    nextForward();
  }
  start = end = forwardIter = backwardIter = NULL;
}

DLList::DLList(DLList const & dl) {
  node* current;
  current = dl.start;

  while((current= current->next) != NULL) {
    insertAfter(nextForward(), current->data);
  }
}

DLList& DLList::operator=(DLList const & dl) {

	node *current = dl.start;

	while(current) {

		insertAfter(current, current->data);
		current = current->next;
	}

	return *this;
}

void DLList::deleteElem(node* p, double& x) {
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
    node *tmp = p;
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    delete tmp;
  }
}

void DLList::insertAfter(node* p, double x) {
  node* tmp = new node();
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

void DLList::insertBefore(node* p, double x) {
  node* tmp = new node();
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

void DLList::startForward(node* p) {
  if(p == NULL) {
	  forwardIter = start;
  } else {
	  forwardIter = p;
  }
}

void DLList::startBackward(node* p) {
  if(p == NULL) {
    backwardIter = end;
  } else {
    backwardIter = p;
  }
}

node* DLList::nextForward() {
  if(forwardIter == NULL) {
    return NULL;
  } else {
    node* current = forwardIter;
    forwardIter = forwardIter->next;
    return current;
  }
}

node* DLList::nextBackward() {
  if(backwardIter == NULL) {
    return NULL;
  } else {
    node* current = backwardIter;
    backwardIter = backwardIter->prev;
    return current;
  }
}
