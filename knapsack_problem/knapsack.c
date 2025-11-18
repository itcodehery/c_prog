#include <stdio.h>
#include <stdlib.h>
#define MAX_WEIGHT 20
#define OBJ_COUNT 6
// Given two arrays P and W where P has the prices of the objects
// and W has the weights of the objects. Determine best approach
// for a weight limit of 20

typedef struct Object {
  int value;
  int index;
} Object;

int compare_object(const void *a, const void *b) {
  Object *a_o = (Object *)a;
  Object *b_o = (Object *)b;
  if (a_o->value < b_o->value) {
    return 1;
  } else if (a_o->value == b_o->value) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  int prices[OBJ_COUNT] = {30, 10, 52, 67, 19, 20};
  int weights[OBJ_COUNT] = {5, 1, 6, 8, 3, 4};

  // Approach: array for Profit/Weight Ratio
  Object prwe[OBJ_COUNT];
  for (int i = 0; i < OBJ_COUNT; i++) {
    prwe[i].value = prices[i] / weights[i];
    prwe[i].index = i;
  }

  // Sort the array
  // O(n.log(n))
  qsort(prwe, OBJ_COUNT, sizeof(Object), compare_object);

  // Choose the best at every iteration
  // for (int i = 0; i < OBJ_COUNT; i++) {
  // }
  printf("- ");
  for (int i = 0; i < OBJ_COUNT; i++) {
    printf("%d - ", prwe[i].value);
  }

  int weights_chosen = 0;
  for (int i = 0; i < OBJ_COUNT; i++) {
    if (MAX_WEIGHT - weights_chosen == 0 ||
        MAX_WEIGHT - weights_chosen < prwe[i].value) {
      break;
    }
    weights_chosen += weights[prwe[i].index];
    printf("\nWeight at iteration %d: %d\n== Chosen object %d", i + 1,
           weights_chosen, prwe[i].index);
  }

  printf("\nWeights Chosen: %d", weights_chosen);
}
