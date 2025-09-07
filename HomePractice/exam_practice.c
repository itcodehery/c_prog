#include<stdio.h>

typedef struct {
  float x;
  float y;
  float z;
} VectorXYZ


int main() {
  VectorXYZ coordinates;
  printf("Enter the coordinates for Player: ");
  scanf("%f %f %f",&coordinates.x, &coordinates.y, &coordinates.z);
  return 0;
}
