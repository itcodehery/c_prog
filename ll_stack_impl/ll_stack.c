// Linked List Stack Implementation
#include <stdio.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

int main() {
  Node head;
  printf("\nEnter a initial value: ");
  scanf("%d", &head.value);
  int ch = 0, val;
  while (ch != -1) {
    printf("\nDo you want to add another node?");
    scanf("%d", &ch);
    if (ch == 1) {
      printf("\nEnter a new value: ");
      scanf("%d", &val);
    }
  }
  return 0;
}
