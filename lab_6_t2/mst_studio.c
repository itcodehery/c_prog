#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// Kruskal's Algorithm Structures
struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V, E;
  struct Edge *edge;
};

struct subset {
  int parent;
  int rank;
};

struct Graph *createGraph(int V, int E) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
  return graph;
}

int find(struct subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
  else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int myComp(const void *a, const void *b) {
  struct Edge *a_edge = (struct Edge *)a;
  struct Edge *b_edge = (struct Edge *)b;
  return a_edge->weight > b_edge->weight;
}

void KruskalMST(struct Graph *graph, char *vertices[]) {
  int V = graph->V;
  struct Edge result[V];
  int e = 0;
  int i = 0;

  qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

  struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

  for (int v = 0; v < V; ++v) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  while (e < V - 1 && i < graph->E) {
    struct Edge next_edge = graph->edge[i++];

    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    if (x != y) {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }

  printf("\nMinimum Spanning Tree (Kruskal's Algorithm):\n");
  int minimumCost = 0;
  for (i = 0; i < e; ++i) {
    printf("%s -- %s == %d\n", vertices[result[i].src],
           vertices[result[i].dest], result[i].weight);
    minimumCost += result[i].weight;
  }
  printf("Minimum Cost: %d\n", minimumCost);
  free(subsets);
}

// Prim's Algorithm
int minKey(int key[], int mstSet[], int V) {
  int min = INF, min_index = -1;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == 0 && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

void printPrimMST(int parent[], int **graph, int V, char *vertices[]) {
  printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
  int minimumCost = 0;
  for (int i = 1; i < V; i++) {
    printf("%s -- %s == %d\n", vertices[parent[i]], vertices[i],
           graph[i][parent[i]]);
    minimumCost += graph[i][parent[i]];
  }
  printf("Minimum Cost: %d\n", minimumCost);
}

void PrimMST(int **graph, int V, char *vertices[]) {
  int parent[V];
  int key[V];
  int mstSet[V];

  for (int i = 0; i < V; i++) {
    key[i] = INF;
    mstSet[i] = 0;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; count++) {
    int u = minKey(key, mstSet, V);
    if (u == -1)
      continue;
    mstSet[u] = 1;

    for (int v = 0; v < V; v++)
      if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
        parent[v] = u;
        key[v] = graph[u][v];
      }
  }

  printPrimMST(parent, graph, V, vertices);
}

int main() {
  int V = 5;
  char *vertices[5] = {"Audio Interface", "DAW", "Microphone", "Synthesizer",
                       "Monitor Speakers"};

  // Adjacency Matrix for Prim's
  int **adjMatrix = (int **)malloc(V * sizeof(int *));
  for (int i = 0; i < V; i++) {
    adjMatrix[i] = (int *)malloc(V * sizeof(int));
  }

  int matrix[5][5] = {{0, 10, 20, 0, 15},
                      {10, 0, 25, 30, 0},
                      {20, 25, 0, 0, 35},
                      {0, 30, 0, 0, 5},
                      {15, 0, 35, 5, 0}};

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      adjMatrix[i][j] = matrix[i][j];
    }
  }

  // Edge list for Kruskal's
  int E = 7;
  struct Graph *graph = createGraph(V, E);

  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].weight = 10;

  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].weight = 20;

  graph->edge[2].src = 0;
  graph->edge[2].dest = 4;
  graph->edge[2].weight = 15;

  graph->edge[3].src = 1;
  graph->edge[3].dest = 2;
  graph->edge[3].weight = 25;

  graph->edge[4].src = 1;
  graph->edge[4].dest = 3;
  graph->edge[4].weight = 30;

  graph->edge[5].src = 2;
  graph->edge[5].dest = 4;
  graph->edge[5].weight = 35;

  graph->edge[6].src = 3;
  graph->edge[6].dest = 4;
  graph->edge[6].weight = 5;

  int choice;
  printf("Music Studio Equipment Network MST\n");
  printf("Vertices: Audio Interface, DAW, Microphone, Synthesizer, Monitor "
         "Speakers\n\n");
  printf("Choose an algorithm:\n");
  printf("1. Kruskal's Algorithm\n");
  printf("2. Prim's Algorithm\n");
  printf("Enter your choice: ");
  scanf_s("%d", &choice);

  switch (choice) {
  case 1:
    KruskalMST(graph, vertices);
    break;
  case 2:
    PrimMST(adjMatrix, V, vertices);
    break;
  default:
    printf("Invalid choice.\n");
  }

  for (int i = 0; i < V; i++) {
    free(adjMatrix[i]);
  }
  free(adjMatrix);
  free(graph->edge);
  free(graph);
  return 0;
