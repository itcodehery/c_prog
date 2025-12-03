#include <limits.h>
#include <stdio.h>

#define V 6 // Number of vertices

// Find minimum weight edge from visited to unvisited vertices
int minKey(int key[], int visited[]) {
  int min = INT_MAX;
  int min_index = -1;

  for (int i = 0; i < V; i++) {
    if (visited[i] == 0 && key[i] < min) {
      min = key[i];
      min_index = i;
    }
  }

  return min_index;
}

// Prim's Algorithm
void prims(int graph[V][V]) {
  int visited[V]; // Track which vertices are in MST
  int key[V];     // Minimum edge weight to connect each vertex
  int parent[V];  // Store parent of each vertex in MST tree

  // Initialize all vertices as not visited
  for (int i = 0; i < V; i++) {
    visited[i] = 0;
    key[i] = INT_MAX;
    parent[i] = -1;
  }

  // Start with first vertex
  key[0] = 0;

  // Build MST with V vertices
  for (int count = 0; count < V; count++) {
    // Find minimum key vertex not yet in MST
    int u = minKey(key, visited);

    if (u == -1)
      break; // No more vertices to add

    // Add vertex to MST
    visited[u] = 1;

    // Update key values of adjacent vertices
    for (int v = 0; v < V; v++) {
      // If edge exists, v not visited, and edge weight < current key
      if (graph[u][v] > 0 && visited[v] == 0 && graph[u][v] < key[v]) {
        key[v] = graph[u][v];
        parent[v] = u;
      }
    }
  }

  // Print MST edges and total weight
  printf("Edge\tWeight\n");
  int total_weight = 0;

  for (int i = 1; i < V; i++) {
    printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    total_weight += graph[i][parent[i]];
  }

  printf("\nTotal MST Weight: %d\n", total_weight);
}

int main() {
  // Adjacency matrix (0 means no edge)
  int graph[V][V] = {{0, 4, 2, 0, 0, 0},  {4, 0, 1, 5, 0, 0},
                     {2, 1, 0, 8, 10, 0}, {0, 5, 8, 0, 2, 6},
                     {0, 0, 10, 2, 0, 3}, {0, 0, 0, 6, 3, 0}};

  prims(graph);

  return 0;
}
