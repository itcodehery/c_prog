#include <stdio.h>
#define V 9
#define INF 9999

// Returns the index of the node with minimum distance
int minDistance(int dist[], int visited[]) {
  // Initialize min value
  int min = INF, min_index;

  for (int v = 0; v < V; v++) {
    // If node not visited and distance of node is less than the current minimum
    if (!visited[v] && dist[v] <= min) {
      // Minimum is updated
      min = dist[v], min_index = v;
    }
  };

  return min_index;
}

// to print the constructed distance array
void printSolution(int dist[], int n) {
  printf("\nVertex Distance from Source\n");
  for (int i = 0; i < V; i++) {
    if (dist[i] != INF) {
      printf("\t%d\t\t\t\t %d\n", i, dist[i]);
    } else {
      printf("\t%d\t\t\t\t INF\n", i);
    }
  }
}

// Function to implement Dijkstra's Algo
void dijkstra(int graph[V][V], int src) {
  // The output array. Dist[i] will hold the shortest distance
  // from src to i
  int dist[V];
  int visited[V];

  // Initialize all distances as INF and visited[] as false
  for (int i = 0; i < V; i++) {
    dist[i] = INF;
    visited[i] = 0;
  }

  // Set the distance of src to src to 0 obviously
  dist[src] = 0;

  // Find the shortest path for all the vertices
  for (int count = 0; count < V - 1; count++) {
    // Pick the minimum distance vertex from the set of
    // vertices not yet processed. u is always equal to src in the first
    // iteration
    int u = minDistance(dist, visited);

    // Mark the picked vertex as visited
    visited[u] = 1;

    // Update the distance of adjacent vertices of the picked vertex
    for (int v = 0; v < V; v++) {
      // Update dist[v] only if it is not in visited[]
      // There is an edge from u to v, and total
      // weight of path from src to v through u is
      // smaller than current value of dist[v]
      if (!visited[v] && graph[u][v] && dist[u] != INF &&
          dist[u] + graph[u][v] < dist[v]) {
        // Update distance
        dist[v] = dist[u] + graph[u][v];
      }
    }
    // print the distance array:
    printSolution(dist, V);
  }
}

int main() {
  int graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};

  dijkstra(graph, 0);
  // Time Complexity: O(V^2)
  // Space Complexity: O(V)

  return 0;
}
