#include <stdio.h>
#include <stdlib.h>

typedef enum {RED, BLACK} rb_colour;
typedef struct RBNode* rb_node;
typedef struct RBTree* rb_tree;

struct RBNode {
  int key;
  rb_colour colour;
  rb_node left;
  rb_node right;
  rb_node parent;
};

struct RBTree {
  rb_node root;
  rb_node nil;
};

rb_node new_rb_node(int, rb_colour, rb_node, rb_node, rb_node);
rb_tree new_rb_tree();
void insert(rb_tree, int);
void insert_fixup(rb_tree, rb_node);
void delete(rb_tree, int);
void left_rotate(rb_tree, rb_node);
void right_rotate(rb_tree, rb_node);
void preorder_traversal(rb_tree);
void preorder(rb_tree, rb_node);
void postorder_traversal(rb_tree);
void postorder(rb_tree, rb_node);
void inorder_traversal(rb_tree);
void inorder(rb_tree, rb_node);

rb_node new_rb_node(int k, rb_colour c, rb_node l, rb_node r, rb_node p) {
  rb_node n = (rb_node) malloc(sizeof(struct RBNode));
  n->key = k;
  n->colour = c;
  n->left = l;
  n->right = r;
  n->parent = p;
  return n;
}

rb_tree new_rb_tree() {
  rb_tree t = (rb_tree) malloc(sizeof(struct RBTree));
  rb_node n = new_rb_node(NULL, BLACK, NULL, NULL, NULL);
  t->nil = n;
  t->root = t->nil;
}

/*

       Y                          X
      / \     Right Rotate       / \
     X   3     ---------->      1   Y
    / \       Left Rotate          / \
   1  2       <----------         2  3

*/

void left_rotate(rb_tree t, rb_node x) {
  rb_node y = x->right;
  x->right = y->left;
  if (y->left != t->nil)
    y->left->parent = x;
  y->parent = x->parent;
  if (x->parent == t->nil) {
    t->root = y;
  }
  else if (x == x->parent->left) {
    x->parent->left = y;
  } 
  else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void right_rotate(rb_tree t, rb_node y) {
  rb_node x = y->left;
  y->left = x->right;
  if (x->right != t->nil)
    x->right->parent = y;
  x->parent = y->parent;
  if (y->parent == t->nil) {
    t->root = x;
  }
  else if (y == y->parent->left) {
    y->parent->left = x;
  }
  else {
    y->parent->right = x;
  }
  x->right = y;
  y->parent = x;
}

void insert(rb_tree t, int k) {
  rb_node n = new_rb_node(k, RED, t->nil, t->nil, t->nil);
  rb_node p = t->nil;
  rb_node walk = t->root;

  while (walk != t->nil) {
    p = walk;
    if (k > walk->key)
      walk = walk->right;
    else
      walk = walk->left;
  }
  
  n->parent = p;
  
  if (p == t->nil) {
    t->root = n;
  }
  else if (k > p->key) {
    p->right = n;
  } else {
    p->left = n;
  }

  insert_fixup(t, n);
}

void insert_fixup(rb_tree t, rb_node n) {
  rb_node z = n;
  while (z->parent->colour == RED) {
    if (z->parent == z->parent->parent->left) {
      rb_node uncle = z->parent->parent->right;
      if (uncle->colour == RED) {
        z->parent->colour = BLACK;
        uncle->colour = BLACK;
        z->parent->parent->colour = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          left_rotate(t, z);
        }
        z->parent->colour = BLACK;
        z->parent->parent->colour = RED;
        right_rotate(t, z->parent->parent);
      }
    } else { //(z->parent == z->parent->parent->right)
      rb_node uncle = z->parent->parent->left;
      if (uncle->colour == RED) {
        z->parent->colour = BLACK;
        uncle->colour = BLACK;
        z->parent->parent->colour = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          right_rotate(t, z);
        }
        z->parent->colour = BLACK;
        z->parent->parent->colour = RED;
        left_rotate(t, z->parent->parent);
      }
    }
  }
  t->root->colour = BLACK;
}

void preorder_traversal(rb_tree t) {
  printf("\nThe preorder traversal is: ");
  preorder(t, t->root);
  printf("\n");
}

void preorder(rb_tree t, rb_node n) {
  if (n == t->nil)
    return;
  printf("%d ", n->key);
  preorder(t, n->left);
  preorder(t, n->right);
}

void postorder_traversal(rb_tree t) {
  printf("\nThe postorder traversal is: ");
  postorder(t, t->root);
  printf("\n");
}

void postorder(rb_tree t, rb_node n) {
  if (n == t->nil)
    return;
  postorder(t, n->left);
  postorder(t, n->right);
  printf("%d ", n->key);
}

void inorder_traversal(rb_tree t) {
  printf("\nThe inorder traversal is: ");
  inorder(t, t->root);
  printf("\n");
}

void inorder(rb_tree t, rb_node n) {
  if (n == t->nil)
    return;
  inorder(t, n->left);
  printf("%d ", n->key);
  inorder(t, n->right);
}

void main() {
  rb_tree rb_t = new_rb_tree();
  rb_tree rb_t2 = new_rb_tree();
  int i;
  for (i = 1; i <= 60; i++) {
    insert(rb_t, i);
  }
  // 15, 8, 10, 12, 18, 25, 20.
  insert(rb_t2, 15);
  insert(rb_t2, 8);
  insert(rb_t2, 10);
  insert(rb_t2, 12);
  insert(rb_t2, 18);
  insert(rb_t2, 25);
  insert(rb_t2, 20);
  insert(rb_t2, 3);
  // insert(rb_t2, 2);
  // insert(rb_t2, 1);
  preorder_traversal(rb_t);
  postorder_traversal(rb_t);
  inorder_traversal(rb_t);
  preorder_traversal(rb_t2);
  postorder_traversal(rb_t2);
  inorder_traversal(rb_t2);
}
