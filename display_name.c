#include <stdio.h>
int hundred(int i) {
  if (i != 100) {
    printf("Hari\n");
    hundred(++i);
  }
  return 0;
}

int main() {
  hundred(0);
  return 0;
}
