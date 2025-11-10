// Dijkstra Implementation using Arrays (Adjacency Matrix)

#include <limits.h> // For INT_MAX
#include <stdio.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[]) {
  // Initialize min value
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++) {
    if (sptSet[v] == 0 && dist[v] <= min) {
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[]) {
  printf("Vertex \t\t Distance from Source\n");
  for (int i = 0; i < V; i++) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src) {
  int dist[V];

  int sptSet[V];

  // Initialize all distances as INFINITE and sptSet[] as false
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    sptSet[i] = 0;
  }

  // Distance of source vertex from itself is always 0
  dist[src] = 0;

  // Find shortest path for all vertices
  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet);

    // Mark the picked vertex as processed
    sptSet[u] = 1;

    // Update dist value of the adjacent vertices of the picked vertex.
    for (int v = 0; v < V; v++) {
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }
  printSolution(dist);
}

// driver program to test above function
int main() {
  int graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};

  dijkstra(graph, 0);

  return 0;
}
