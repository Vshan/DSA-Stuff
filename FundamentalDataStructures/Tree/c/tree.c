#include <stdio.h>

struct Tree {
  struct Tree* parent;
  int element;
  struct Tree* first_child;
  struct Tree* next_sibling;
};

typedef struct Tree* TREE;

TREE root;
TREE construct_tree(int);
void addChildTo(TREE, int);
TREE getLastChild(TREE);
void display_children(TREE);
void preorder_traversal(TREE);

void main() {
  root = construct_tree(1);
  addChildTo(root, 2);
  addChildTo(root, 3);
  addChildTo(root, 4);
  display_children(root);
  addChildTo(root->first_child, 5);
  printf("CHeck this out!\n");
  preorder_traversal(root);
}

TREE construct_tree(int e) {
  TREE t = (TREE) malloc(sizeof(struct Tree));
  t->element = e;
  t->parent = NULL;
  t->first_child = NULL;
  t->next_sibling = NULL;
  return t;
}

void addChildTo(TREE t, int e) {
  TREE last_tree = getLastChild(t);
  if (last_tree) {
    TREE new_tree = construct_tree(e);
    last_tree->next_sibling = new_tree;
    new_tree->parent = t;
  } else {
    TREE new_tree = construct_tree(e);
    t->first_child = new_tree;
    new_tree->parent = t;
  }
}

TREE getLastChild(TREE t) {
  if (t->first_child) {
    TREE child = t->first_child;
    while (child->next_sibling) {
      child = child->next_sibling;
    }
    return child;
  }
  return NULL;
}

void display_children(TREE t) {
  TREE child = t->first_child;
  if (child) {
    while (child) {
      printf("%d\n", child->element);
      child = child->next_sibling;
    }
  }
}

void preorder_traversal(TREE t) {
  printf("%d\n", t->element);
  TREE child = t->first_child;
  if (child) {
    while(child) {
      printf("  ");
      preorder_traversal(child);
      child = child->next_sibling;
    }
  }
}