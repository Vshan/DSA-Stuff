#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int, int);
void quick_sort(int A[], int, int);

int partition(int A[], int p, int r) {
  int pivot = A[r];

  int i = p - 1;
  int j, temp;

  for (j = p; j < r; j++) {
    if (A[j] <= pivot) {
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }

  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return i+1;
}

void quick_sort(int A[], int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, p, r);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);
  }
}

void main() {
  int A[50], n, i;

  printf("Enter no. of elements: "); scanf("%d", &n);

  printf("\nEnter: ");
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);

  quick_sort(A, 0, n-1);

  printf("\nSorted array: ");
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
}