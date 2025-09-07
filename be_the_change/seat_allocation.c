#include <stdio.h>
#include <string.h>
#define ROWS 4
#define COLS 3

int main() {
  char program_codes[5][4] = {"BCA", "BSc", "BCo", "BBA", "BTe"};
  char seats[COLS][ROWS][4] = {};
  char prev[4] = "";
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      if (strcmp(prev, program_codes[i]) == 0) {
        strcpy(prev, "");
        continue;
      } else {
        strcpy(seats[i][j], program_codes[i]);
        strcpy(prev, seats[i][j]);
      }
    }
  }

  printf("Seats:\n");
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      printf("%s\t", seats[j][i]);
    }
    printf("\n");
  }
  return 0;
}
