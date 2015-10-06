#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HT_MAX_SIZE 97

struct Hashtable {
  struct Chain* chain;
  int maxsize;
};

struct Chain {
  struct Node* head;
};

struct Node {
  char* key;
  char* val;
  struct Node* next;
};

typedef struct Hashtable* ht_ptr;
typedef struct Chain* chain_ptr;
typedef struct Node* node_ptr;

ht_ptr HT;

int hash(char* key) {
  int n = 0;
  char* k = key;
  while (*k != '\0') {
  	n += (int)(*k);
  	k++;
  }
  n>>3;
  return n%(HT->maxsize);
}

ht_ptr new_Hashtable(int size) {
  ht_ptr ht;
  int i;
  ht = (ht_ptr) malloc(sizeof(struct Hashtable));
  ht->maxsize = size;
  ht->chain = (chain_ptr) malloc(sizeof(struct Chain)*size);
  for (i = 0; i < size; i++) {
    ht->chain[i].head = (node_ptr) malloc(sizeof(struct Node));
  }
  return ht;
}

node_ptr new_Node() {
  node_ptr n = (node_ptr) malloc(sizeof(struct Node));
  n->next = NULL;
  return n;
}

void set(char* key, char* value) {
  int hash_key = hash(key);
  if (HT->chain[hash_key].head->next) {
    node_ptr walk = HT->chain[hash_key].head->next;
    while(walk->next)
      walk = walk->next;
    walk->key = key;
    walk->val = value;
    node_ptr n = new_Node();
    walk->next = n;
  }
  else {
    HT->chain[hash_key].head->key = key;
    HT->chain[hash_key].head->val = value;
    node_ptr n = new_Node();
    HT->chain[hash_key].head->next = n;
  }
}

char* get(char* key) {
  return HT->chain[hash(key)].head->val;
}

void main(int argc, char** argv) {
  HT = new_Hashtable(HT_MAX_SIZE);
  set("key", "value");
  set("yodude", "sup");
  char* val = get("key");
  char* val2 = get("yodude");
  printf(val);
  printf("\n");
  printf(val2);
  printf("\n");
}


