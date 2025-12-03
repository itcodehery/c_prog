#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX_V 100

void printSolution(int dist[MAX_V][MAX_V], int V) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF) {
        printf("%7s", "INF");
      } else {
        printf("%7d", dist[i][j]);
      }
    }
    printf("\n");
  }
}

void floydWarshall(int graph[MAX_V][MAX_V], int V) {
  int dist[MAX_V][MAX_V];
  int i, j, k;

  // Initialize the solution matrix same as input graph matrix
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  // Add all vertices one by one to the set of intermediate vertices.
  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (dist[i][k] != INF && dist[k][j] != INF &&
            dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  printSolution(dist, V);
}

int main() {
  int V = 4;
  int graph[MAX_V][MAX_V];

  printf("Using dummy graph with %d vertices.\n", V);

  // Initialize graph
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i == j) {
        graph[i][j] = 0; // Distance to itself is 0
      } else {
        graph[i][j] = INF; // Initialize with infinity
      }
    }
  }

  // Define dummy edges
  // 0 -> 1 (5)
  // 0 -> 3 (10)
  // 1 -> 2 (3)
  // 2 -> 3 (1)
  graph[0][1] = 5;
  graph[0][3] = 10;
  graph[1][2] = 3;
  graph[2][3] = 1;

  printf("Graph initialized with dummy data.\n");

  // Run the Floyd Warshall algorithm
  floydWarshall(graph, V);

  return 0;
}