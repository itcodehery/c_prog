#include <stdio.h>
#define STACK_SIZE 10

int stack[STACK_SIZE];
int min_stack[STACK_SIZE];
int top = -1;
int minstktop = -1;

void push() {
  int ele;
  if (top == STACK_SIZE) {
    printf("\n--------------------");
    printf("\nTracker is full!");
    printf("\n--------------------");
    return;
  }
  printf("\nEnter the recorded volume level: ");
  scanf("%d", &ele);
  if (top == -1) {
    minstktop += 1;
    top += 1;
    stack[top] = ele;
    min_stack[minstktop] = ele;
  } else {
    top += 1;
    stack[top] = ele;
    if (min_stack[minstktop] > ele) {
      minstktop++;
      min_stack[minstktop] = ele;
    }
  }
}

void pop() {
  int temp;
  if (top != -1) {
    temp = stack[top];
    if (stack[top] == min_stack[minstktop]) {
      top--;
      minstktop--;
      printf("\n--------------------");
      printf("\nVolume Level (%d) removed successfully!", temp);
      printf("\n--------------------");
    } else {
      top--;
      printf("\n--------------------");
      printf("\nVolume Level (%d) removed successfully!", temp);
      printf("\n--------------------");
    }
  } else {
    printf("\n--------------------");
    printf("\nNo Volume Levels tracked! Record and track new volumes!");
    printf("\n--------------------");
  }
  return;
}

void getmin() {
  printf("\nThe lowest volume recorded is %d decibels.", min_stack[minstktop]);
}

// WARN: Takes O(n) Time
void display() {
  if (top > -1) {
    printf("\n");
    for (int i = 0; i <= top; i++) {
      printf("%d ", stack[i]);
    }
  } else {
    printf("\n--------------------");
    printf("No Volume Levels tracked!");
    printf("\n--------------------");
  }
}

int main() {
  int ch = 0;

  while (ch != -1) {
    printf("\n--------------------");
    printf("\nVOLUME LEVEL TRACKING");
    printf("\nEnter a choice:");
    printf("\n1. Record new Volume (in decibels)");
    printf("\n2. Remove last Volume Level");
    printf("\n3. Show lowest volume level");
    printf("\n4. List all tracked volumes (in decibels)");
    printf("\n5. Exit");
    printf("\nYour choice: ");
    scanf("%d", &ch);
    printf("\n--------------------");
    switch (ch) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      getmin();
      break;
    case 4:
      display();
      break;
    default:
      ch = -1;
      break;
    }
  }

  return 0;
}
