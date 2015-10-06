#include<stdio.h>
#include<stdlib.h>

struct BSTNode {
  int key;
  struct BSTNode* parent;
  struct BSTNode* right;
  struct BSTNode* left;
};

struct BSTTree {
  struct BSTNode* root;
};

typedef struct BSTNode* node;
typedef struct BSTTree* BST;

BST new_BST();
node new_BSTNode();
void insert(BST, int);
void search(BST, int);
void delet(BST, int);
void preorder(node);
void preorder_traversal(BST);
void postorder(node);
void postorder_traversal(BST);
void inorder(node);
void inorder_traversal(BST);


void preorder_traversal(BST t) {
  printf("\nPreorder traversal: ");
  preorder(t->root);
  printf("\n");
}

void preorder(node n) {
  if (!n) return;
  printf("%d ", n->key);
  preorder(n->left);
  preorder(n->right);
}

void postorder_traversal(BST t) {
  printf("\nPostorder traversal: ");
  postorder(t->root);
  printf("\n");
}

void postorder(node n) {
  if (!n) return;
  postorder(n->left);
  postorder(n->right);
  printf("%d ", n->key);
}

void inorder_traversal(BST t) {
  printf("\nInorder traversal: ");
  inorder(t->root);
  printf("\n");
}

void inorder(node n) {
  if (!n) return;
  inorder(n->left);
  printf("%d " , n->key);
  inorder(n->right);
}

BST new_BST() {
  BST n = (BST) malloc(sizeof(struct BSTTree));
  node n2 = new_BSTNode();
  n->root = n2;
  n2->parent = NULL;
  return n;
}

node new_BSTNode() {
  node n = (node) malloc(sizeof(struct BSTNode));
  n->key = NULL;
  n->parent = NULL;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void insert(BST t, int key) {
  node tmp;
  if (!t->root->key) {
    t->root->key = key;
    return;
  }

  node walk = t->root;

  while (walk) {
    tmp = walk;
    if (key > walk->key)
      walk = walk->right;
    else
      walk = walk->left;
  }

  node n = new_BSTNode();
  n->key = key;
  n->parent = tmp;

  if (key > tmp->key)
    tmp->right = n;
  else
    tmp->left = n;

}

void search(BST bst, int key) {

}

void delet(BST bst, int key) {
}


void main() {
  BST bst = new_BST();
  insert(bst, 2);
  insert(bst, 4);
  insert(bst, 1);
  insert(bst, 10);
  insert(bst, 5);
  insert(bst, 9);
  insert(bst, 11);
  insert(bst, 20);
  preorder_traversal(bst);
  postorder_traversal(bst);
  inorder_traversal(bst);
}
