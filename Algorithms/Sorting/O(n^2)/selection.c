#include <stdio.h>
#include <stdlib.h>

void selection_sort(int [], int);

void selection_sort(int A[], int n) {
  int i, j, min, temp;
  for (i = 0; i < n; i++) {
    min = i;
    for (j = i+1; j < n; j++) {
      if (A[j] < A[min])
        min = j;
    }
    temp = A[i];
    A[i] = A[min];
    A[min] = temp;
  }
}

void main() {
  int A[100], n, i;
  printf("\nEnter no. of elements you wish to enter: ");
  scanf("%d", &n);
  printf("\nEnter: ");
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);

  selection_sort(A, n);

  printf("\nSorted elements are: ");
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}