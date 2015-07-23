#include <stdio.h>

struct Node {
  int element;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node* NODE;

NODE construct_node(int x) {
  NODE new_node = (NODE) malloc(sizeof(struct Node));
  new_node->element = x;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

NODE sentinel;
int size;

void addFront(int e) {
  NODE n = construct_node(e);
  if (size) {
    n->next = sentinel->next;
    n->prev = sentinel;
    sentinel->next->prev = n;
    sentinel->next = n;
  } else {
    sentinel->next = n;
    n->prev = sentinel;
    n->next = sentinel;
    sentinel->prev = n;
  }
  size++;
}

void addBack(int e) {
  NODE n = construct_node(e);
  if (size) {
    sentinel->prev->next = n;
    n->prev = sentinel->prev;
    n->next = sentinel;
    sentinel->prev = n;
  }
  else {
    sentinel->next = n;
    n->prev = sentinel;
    n->next = sentinel;
    sentinel->prev = n; 
  }
  size++;
}

void display() {
  NODE start = sentinel->next;
  while (start->next != sentinel) {
    printf("%d -> ", start->element);
    start = start->next;
  }
  printf("%d\n", start->element);
}

void main() {
  size = 0;
  sentinel = construct_node(NULL);
  addFront(1);
  addFront(2);
  addFront(3);
  addBack(4);
  addBack(20);
  addFront(10);
  display();
}