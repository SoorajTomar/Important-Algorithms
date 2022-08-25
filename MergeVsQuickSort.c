#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int main() {
  srand(time(0));int n;
    printf("Enter size:");
    scanf("%d",&n);int a[n],b1[n];
    for(int i=0;i<n;i++)
    {a[i]=rand() % (999 + 1 - 1) + 1;
    b1[i]=a[i];}
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    for(int i=0;i<n;i++)
    printf("%d ",b1[i]);
    printf("\n");
    clock_t t;
    t = clock();
    quickSort(a,0,n-1);
    printArray(a,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    clock_t t1;
    t1 = clock();
    mergeSort(b1,0,n-1);
    printArray(b1,n);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("\nMerge Sort took %f seconds to sort \n", time_taken1);
    printf("\nQuick Sort took %f seconds to sort \n", time_taken);
}
