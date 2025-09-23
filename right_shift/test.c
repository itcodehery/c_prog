#include <stdio.h>

// right Shift by k elements
int main() {
  int k = 2;
  int arr[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    int temp = arr[i];       // 1
    arr[i] = arr[i + k % 5]; // 3
    arr[5 - k + i] = temp;
  }

  printf("\nThe shifted array: ");
  for (int i = 0; i < 5; i++) {
    printf("%d, ", arr[i]);
  }
  return 0;
}
