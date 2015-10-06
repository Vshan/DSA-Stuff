#include <stdio.h>

struct Node {
  int element;
  struct Node* next;
};

typedef struct Node* NODE;

NODE head = NULL;

void addFirst(int e) {
  NODE n = (NODE) malloc (sizeof(struct Node));
  n->next = head;
  n->element = e;
  head = n;
}

void addLast(int e) {
  NODE n = (NODE) malloc (sizeof(struct Node));
  n->next = NULL;
  n->element = e;
  NODE walk = head;
  while (walk->next != NULL) {
    walk = walk->next;
  }
  walk->next = n;
}

void displayFrom(NODE n) {
  while (n->next != NULL) {
    printf("%d -> ", n->element);
    n = n->next;
  }
  printf("%d\n", n->element);
}

void main(int argc, char** argv) {
  addFirst(5);
  addFirst(2);
  addFirst(3);
  addLast(4);
  displayFrom(head);
}