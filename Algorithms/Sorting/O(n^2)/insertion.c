#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int [], int);

void insertion_sort(int array[], int n) {
  int i, d, t;
  for (i = 1; i <= n-1; i++) {
    d = i;
    while (d > 0 && array[d] < array[d-1]) {
      t = array[d];
      array[d] = array[d-1];
      array[d-1] = t;
      d--;
    }
  }
}

void main() {
  int A[100], n, i;
  printf("\nEnter no. of elements you wish to enter: ");
  scanf("%d", &n);
  printf("\nEnter: ");
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);

  insertion_sort(A, n);

  printf("\nSorted elements are: ");
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}