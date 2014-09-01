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
  node* tmp;
  if(p == NULL) {
    if(start == NULL) {
      start = new node();
      start->data = x;
      end = start;
      printf("forwardIter = %d , backwardIter  = %d, end  = %d, start  = %d\n", forwardIter , backwardIter , end , start);
    } else {
      tmp = start;
      start = new node();
      start->data = x;
      start->next = tmp;
      tmp->prev = start;
    }
  } else {
    if(p->next == NULL) {
      p->next = new node();
      p->next->prev = p;
      p->next->data = x;
      end = p->next;
    } else {
      tmp = new node();
      tmp->data = x;
      
      tmp->next = p->next;
      p->next->prev = tmp;

      tmp->prev = p;
      p->next = tmp;
    }
  }
}

DLList::DLList(DLList const & dl) {
  // dl.startForward();
  node* current, *iter;
  current = dl.start;

  while((current= current->next) != NULL) {
    insertAfter(nextForward(), current->data);
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
  if(start == NULL) {
    return NULL;
  } else {
    node* current = forwardIter;
    forwardIter = forwardIter->next;
    return current;
  }
}

node* DLList::nextBackward() {
  if(start == NULL) {
    return NULL;
  } else {
    node* current = backwardIter;
    backwardIter = backwardIter->prev;
    return current;
  }
}

