#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void buildHeap(int arr[], int n) {
  int i;
  for ( i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
  buildHeap(arr, n);
  int i;
  for ( i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void printArray(int arr[], int n) {
  int i;
  for ( i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
   int size, i;
   printf("Enter size of the Array: ");
   scanf("%d",&size);
   int A[size];
   printf("Enter %d element in the Array: ",size);
   for(i = 0; i < size; i++){
     scanf("%d",&A[i]);
   }

   printf("Given array is \n");
   printArray(A, size);

   heapSort(A, size);

   printf("Sorted array is \n");
   printArray(A, size);

   
}