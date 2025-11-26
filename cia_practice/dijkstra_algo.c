#include <stdio.h>
#define MAX 5
#define INF 9999

int minDistance(int distance[], int visited[], int n) {
  int min = INF, index = -1;

  for (int i = 0; i < n; i++) {
    // If node is not visited and the distance rn is lesser
    // than the current min
    if (!visited[i] && distance[i] < min) {
      min = distance[i];
      index = i;
    }
  }

  return index;
}

void dijkstra(int graph[MAX][MAX], int src, int number_of_inputs) {
  // dijkstra's algo
  int dist[MAX];
  int visited[MAX];

  // Iterate through array
  for (int i = 0; i < number_of_inputs; i++) {
    dist[i] = INF;
    visited[i] = 0;
  }

  dist[src] = 0;

  // Actual algo
  for (int i = 0; i < number_of_inputs; i++) {
    int u = minDistance(dist, visited, number_of_inputs);
    if (u == -1)
      break;
    visited[u] = 1;

    for (int v = 0; v < number_of_inputs; v++) {
      if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
    // Check the cost
  }
  for (int i = 0; i < number_of_inputs; i++) {
    printf("Node %d: %d\n", i + 1, dist[i]);
  }
}

int main() {
  int graph[MAX][MAX] = {{0, 2, 0, 5, 0},
                         {0, 0, 1, 2, 0},
                         {6, 0, 0, 2, 4},
                         {0, 3, 8, 0, 2},
                         {7, 3, 6, 0, 0}};
  dijkstra(graph, 1, 5);
  return 0;
}
