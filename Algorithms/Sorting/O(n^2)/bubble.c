#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int [], int);

void bubble_sort(int A[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
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

  bubble_sort(A, n);

  printf("\nSorted elements are: ");
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}