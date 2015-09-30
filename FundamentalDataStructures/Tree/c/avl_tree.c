#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
  int element;
  struct AVLNode* left;
  struct AVLNode* right;
  int height;
};

typedef struct AVLNode* node;

node new_Node(int);
node insert(node, int);
node search(int);
node left_rotate(node);
node right_rotate(node);
int get_balance(node);
int height(node);
int max(int, int);
void preorder(node);
void postorder(node);
void inorder(node);


int max(int a, int b) {
  int c = (a > b)? a : b;
  return c;
}

int height(node n) {
  if (!n) return 0;
  return n->height;
}

node new_Node(int e) {
  node n = (node) malloc(sizeof(struct AVLNode));
  n->element = e;
  n->left = NULL;
  n->right = NULL;
  n->height = 1;
  return n;
}

//       Y                          X
//      / \     Right Rotate       / \
//     X   3     ---------->      1   Y
//    / \       Left Rotate          / \
//   1  2       <----------         2   3

node right_rotate(node y) {
  node x = y->left;
  node t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

node left_rotate(node x) {
  node y = x->right;
  node t2 = y->left;

  y->left = x;
  x->right = t2;
  
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int get_balance(node n) {
  if (!n) return 0;
  return height(n->left) - height(n->right);
}

node insert(node n, int e) {
  if (!n)
    return new_Node(e);

  if (e < n->element)
    n->left = insert(n->left, e);
  else
    n->right = insert(n->right, e);

  n->height = max(height(n->left), height(n->right)) + 1;

  int balance = get_balance(n);

  // Left-Left case
  if (balance > 1 && e < n->left->element)
    return right_rotate(n);

  // Left-Right case
  if (balance > 1 && e > n->left->element) {
    n->left = left_rotate(n->left);
    return right_rotate(n);
  }

  // Right-Right case
  if (balance < -1 && e > n->right->element)
    return left_rotate(n);

  // Right-Left case
  if (balance < -1 && e < n->right->element) {
    n->right = right_rotate(n->right);
    return left_rotate(n);
  }

  return n;

}

void preorder(node n) {
  if (!n) return;
  printf("%d ", n->element);
  preorder(n->left);
  preorder(n->right);
}

void postorder(node n) {
  if (!n) return;
  postorder(n->left);
  postorder(n->right);
  printf("%d ", n->element);
}

void inorder(node n) {
  if (!n) return;
  inorder(n->left);
  printf("%d ", n->element);
  inorder(n->right);
}

void main() {
  node root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  printf("\nThe preorder traversal is: ");
  preorder(root);
  printf("\n");
}
