// Linked-List Queue Implementation
#include <stdio.h>
#include <stdlib.h>

// Node
struct Node {
  int value;
  struct Node *next;
};

void enqueue(struct Node *tail) {
  int element = -1;
  printf("\nEnter an element: ");
  scanf("%d", &element);
  // Initializing new node
  struct Node new_node;
  new_node.value = element;
  new_node.next = NULL;

  tail->next = &new_node;
  tail = tail->next;
}

void dequeue(struct Node *head) {
  struct Node *temp = head;
  head = head->next;
  free(temp);
}

void display(struct Node *head) {
  struct Node *current = head;
  printf("%d, ", current->value);
  while (current->next != NULL) {
    current = current->next;
    printf("%d, ", current->value);
  }
}

int main() {
  struct Node head;
  struct Node *tail = &head;
  int ch = -2;
  while (ch != -1) {
    printf("\n-------------");
    printf("\nQueue Implementation");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");
    printf("\n-------------");
    printf("\nEnter your choice:");
    printf("\n-------------");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      enqueue(tail);
      break;
    case 2:
      dequeue(&head);
      break;
    case 3:
      display(&head);
      break;
    default:
      ch = -1;
    }
  }
  return 0;
}
