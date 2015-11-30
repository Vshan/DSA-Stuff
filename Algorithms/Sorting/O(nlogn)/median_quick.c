#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int, int);
int rselect_i(int A[], int, int, int);
int mpartition(int A[], int, int);
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

int rselect_i(int A[], int p, int r, int i) {
  int q;
  if (p == r)
    return A[p];
  q = partition(A,p,r);
  int k = q - p + 1;
  if (i == k)
    return q;
  else if (i < k)
    return rselect_i(A,p,q-1,i);
  else
    return rselect_i(A,q+1,r,i);
}

int mpartition(int A[], int p, int r) {
  int med = rselect_i(A, p, r, ((p+r)/2));
  int temp = A[r];
  A[r] = A[med];
  A[med] = temp;
  partition(A, p, r);
}

void quick_sort(int A[], int p, int r) {
  int q;
  if (p < r) {
    q = mpartition(A, p, r);
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