// Circular Queue Implementation
#include <stdio.h>
#define QUEUE_SIZE 10

void enque(int queue[], int *front, int *rear, int element) {}

int deque(int queue[], int *front, int *rear) { return 0; }

void display(int queue[], int *front, int *rear) {
  printf("\n\n----------------------\n");
  for (int i = *front; i <= *rear; i++) {
    if (i != *rear) {
      printf("%d ->", queue[i]);
    } else {
      printf("%d", queue[i]);
    }
  }
  printf("\n----------------------\n");
}

void main_loop(int queue[], int *front, int *rear) {
  int ch, ele;
  while (ch != -1) {
    printf("\n----------------");
    printf("\nCircular Queue Menu:");
    printf("\n----------------");
    printf("\n1. Enque");
    printf("\n2. Deque");
    printf("\n3. Display");
    printf("\n4. Exit");
    printf("\n----------------");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Enter the element to enque: ");
      scanf("%d", &ele);
      enque(queue, front, rear, ele);
      printf("The element %d has been enqueued.", ele);
      ele = 0;
      break;
    case 2:
      ele = deque(queue, front, rear);
      printf("The queue has been dequeued. The element removed was %d", ele);
      ele = 0;
      break;
    case 3:
      display(queue, front, rear);
      break;
    case 4:
      ch = -1;
    }
  }
  return;
}

int main() {
  int queue[QUEUE_SIZE];
  int front = -1, rear = -1;

  main_loop(queue, &front, &rear);
  return 0;
}
