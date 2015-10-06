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
void add_child_to(TREE, int);
TREE get_last_child(TREE);
void display_children(TREE);
void preorder_traversal(TREE);
TREE search(TREE, int);

void main() {
  while(1) {
    if (!root) {
      int ele;
      printf("Enter root of tree: ");
      scanf("%d", &ele);
      root = construct_tree(ele);
    } else {
      preorder_traversal(root);
      printf("\nEnter the element to add child to: ");
      int sea;
      scanf("%d", &sea);
      printf("\nEnter the element to be added: ");
      int ele;
      scanf("%d", &ele);
      add_child_to(search(root, sea), ele);
    }
  }
}

TREE construct_tree(int e) {
  TREE t = (TREE) malloc(sizeof(struct Tree));
  t->element = e;
  t->parent = NULL;
  t->first_child = NULL;
  t->next_sibling = NULL;
  return t;
}

TREE search(TREE t, int e) {
  TREE child = t->first_child;
  if (t->element == e) {
    return t;
  }
  while(child) {
    TREE sr = search(child, e);
    if (sr) {
      return sr;
    } else {
      child = child->next_sibling;
    }
  }
  return NULL;
}

void add_child_to(TREE t, int e) {
  TREE last_tree = get_last_child(t);
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

TREE get_last_child(TREE t) {
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
  static int depth = 0;
  int i;
  printf("%d\n", t->element);
  TREE child = t->first_child;
  if (child) {
    depth++;
    while(child) {
      for (i = 0; i < depth-1; i++) printf("  ");
      printf("|__");
      preorder_traversal(child);
      child = child->next_sibling;
    }
    depth--;
  }
}