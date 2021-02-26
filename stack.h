
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top = NULL;
	int size = 0;
}Stack;

typedef Stack * StackPtr;

void push(StackPtr s, char value){
  NodePtr now = (NodePtr)malloc(sizeof(NodePtr));
  if(now){
    now->data = value;
    now->nextPtr = s->top;
    s->size += 1;
    s->top = now;
  }
}

char pop(StackPtr s){
  char val;
  NodePtr n = s->top;
  if(s->top!=NULL){
    val = n->data;
    s->top = n->nextPtr;
    free(n);
    s->size -= 1;
    return val;
  }
  else return NULL;
}
void pop_all(StackPtr s);
#endif
