#include <stdio.h>

#define N 4
#define INF 9999

int dist[N][N] = {
    {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

// Memoization table
int dp[1 << N][N];

int next_city[1 << N][N];

int tsp(int mask, int pos) {
  if (mask == ((1 << N) - 1)) {
    return dist[pos][0];
  }

  if (dp[mask][pos] != -1) {
    return dp[mask][pos];
  }

  int minCost = INF;
  int bestNext = -1;

  for (int city = 0; city < N; city++) {
    if ((mask & (1 << city)) == 0) { // If city is not in mask
      int currentCost = dist[pos][city] + tsp(mask | (1 << city), city);

      if (currentCost < minCost) {
        minCost = currentCost;
        bestNext = city;
      }
    }
  }

  next_city[mask][pos] = bestNext;

  return dp[mask][pos] = minCost;
}

void printTour() {
  int mask = 1;
  int pos = 0;
  printf("Tour: 0");

  while (mask != ((1 << N) - 1)) {
    int next = next_city[mask][pos];
    printf(" -> %d", next);

    mask |= (1 << next);
    pos = next;
  }

  printf(" -> 0\n");
}

int main() {
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }

  printf("Traveling Salesperson Problem using Dynamic Programming\n");
  printf("Number of cities: %d\n\n", N);

  printf("Cost Matrix:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%4d", dist[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int minCost = tsp(1, 0);

  printf("Minimum Cost: %d\n", minCost);
  printTour();

  return 0;
}
