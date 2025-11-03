#include <stdio.h>

int main() {
  int a[10] = {23, 141, 24, 3, 23, 54, 234, 51, 2, 12};
  int key;

  printf("Enter a number: ");
  scanf("%d", &key);
  for (int i = 0; i < 10; i++) {
    if (a[i] == key) {
      printf("Found at %d", i);
      return 0;
    }
  }
  printf("Not found!");
  return 0;
}
