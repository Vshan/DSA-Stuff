#include <stdio.h>

struct Node {
  int element;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node* NODE;

NODE sentinel = (NODE) malloc (sizeof(struct Node));

void addFront(int e) {
  NODE n = (NODE) malloc (sizeof(struct Node));
  n->element = e;
  n->next = sentinel->next;
  n->prev = sentinel;
  sentinel->next->prev = n;
  sentinel->next = n;
}

void display() {
  NODE start = sentinel->next;
  while (start->next != sentinel) {
    printf("%d -> ", start->element);
  }
  printf("%d\n", start->element);
}

void main(int argc, char** argv) {
  addFront(1);
  addFront(2);
  addFront(3);
}