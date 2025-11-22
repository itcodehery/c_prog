#include <stdio.h>

typedef struct {
  float x;
  float y;
  float z;
} VectorXYZ;

VectorXYZ coordinates;

// Pure Functions
void levitate(VectorXYZ coords) { coords.y += 10; }
void ground(VectorXYZ coords) { coords.y = 0; }
void move(VectorXYZ coords, int factor) { coords.x += factor; }

void display(VectorXYZ coords) {
  printf("\n\n------------------");
  printf("\nPlayer's Current Position");
  printf("\n------------------");
  printf("\nX: %.2f", coords.x);
  printf("\nY: %.2f", coords.y);
  printf("\nZ: %.2f", coords.z);
  printf("\n------------------");
  printf("\n------------------\n");
}

int main() {
  int ch = 0;

  printf("Enter the coordinates for Player: ");
  scanf_s("%f %f %f", &coordinates.x, &coordinates.y, &coordinates.z);
  while (ch != -1) {
    printf("\n-----\nMove Player\n-----");
    printf("\n1. Levitate");
    printf("\n2. Ground");
    printf("\n3. Left");
    printf("\n4. Right");
    printf("\n5. Display");
    printf("\n6. Exit");
    scanf_s("%d", &ch);
    switch (ch) {
    case 1:
      printf("\nLevitating Player...\n");
      levitate(coordinates);
      display(coordinates);
      break;
    case 2:
      printf("\nPulling Player Down to Earth...\n");
      ground(coordinates);
      display(coordinates);
      break;
    case 3:
      printf("\nMoving Player to the Left...\n");
      move(coordinates, -10);
      display(coordinates);
      break;
    case 4:
      printf("\nMoving Player to the Right...\n");
      move(coordinates, 10);
      display(coordinates);
      break;
    case 5:
      printf("\nDisplaying...\n");
      display(coordinates);
      break;
    case 6:
      printf("\nExiting...");
      ch = -1;
      break;
    default:
      printf("Invalid choice! Exiting program!");
      return 1;
    }
  }
  return 0;
}
