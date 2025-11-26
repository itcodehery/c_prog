#include <stdio.h>
#define MAX 5
#define INF 9999

int minDistance(int visited[MAX], int distance[MAX], int num_of_inp) {
  int min = INF, index = -1;

  for (int i = 0; i < num_of_inp; i++) {
    if (!visited[i] && distance[i] < min) {
      min = distance[i];
      index = i;
    }
  }

  return index;
}

void dijkstra(int graph[MAX][MAX], int src, int num_of_inp) {
  int dist[MAX], visited[MAX];

  // Initialize the dist and visited arrays
  for (int i = 0; i < num_of_inp; i++) {
    dist[i] = INF;
    visited[i] = 0;
  }

  // Set the source as visited
  visited[src] = 1;

  // Iterate through v-1
  for (int count = 0; count < num_of_inp - 1; count++) {
    int u = minDistance(visited, dist, MAX);
    visited[u] = 1;

    for (int v = 0; v < num_of_inp; v++) {
      if (!visited[i] && graph[u][v] != 0 && dist[u] + graph[v][u] < dist[v]) {
        dist[v] = dist[u] + graph[v][u];
      }
    }
  }
}

int main() {}
