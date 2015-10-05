#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2*i)
#define RIGHT(i) (2*i + 1)
#define PARENT(i) (i/2)

void heap_sort(int []);
void max_heapify(int [], int);
void build_max_heap(int []);

void max_heapify(int A[], int i) {
  int a, b, c, temp;
  a = A[i]
  b = A[LEFT(i)];
  c = A[RIGHT(i)];
  int l = (a > b? (a > c? i : RIGHT(i)) : (b > c? LEFT(i) : RIGHT(i)));

  if (l != i) {
    temp = A[l];
    A[l] = A[i];
    A[i] = temp;
    max_heapify(A, l);
  }
}