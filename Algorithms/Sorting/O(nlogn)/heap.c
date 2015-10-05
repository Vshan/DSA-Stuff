#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2*i)
#define RIGHT(i) (2*i + 1)
#define PARENT(i) (i/2)
int heap_size;

void heap_sort(int [], int);
void max_heapify(int [], int);
void build_max_heap(int [], int);

void max_heapify(int A[], int i) {
  int a, b, c, temp, l;
  a = A[i];
  b = A[LEFT(i)];
  c = A[RIGHT(i)];
  l = i;
  if ((LEFT(i) <= heap_size) && (RIGHT(i) <= heap_size))
    l = (a > b? (a > c? i : RIGHT(i)) : (b > c? LEFT(i) : RIGHT(i)));

  if (l != i) {
    temp = A[l];
    A[l] = A[i];
    A[i] = temp;
    max_heapify(A, l);
  }
}

void build_max_heap(int A[], int n) {
  int i;
  heap_size = n-1;
  for (i = (n/2); i > 0; i--)
    max_heapify(A, i);
}

void heap_sort(int A[], int n) {
  int i, temp;
  build_max_heap(A, n);
  for (i = n; i >= 2; i--) {
    temp = A[1];
    A[1] = A[i];
    A[i] = temp;
    heap_size--;
    max_heapify(A, 1);
  }
}

void main() {
  int A[100], n, i;
  printf("\nEnter n: "); scanf("%d", &n);
  printf("\nEnter numbers: ");
  for (i = 1; i <= n; i++)
    scanf("%d", &A[i]);
  heap_sort(A, n);
  printf("\nSorted numbers: ");
  for (i = 1; i <= n; i++)
    printf("%d ", A[i]);
  printf("\n");
}