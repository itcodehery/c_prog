#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
  int dest;
  int weight;
  struct AdjListNode *next;
};

struct AdjList {
  struct AdjListNode *head;
};

struct Graph {
  int V;
  struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest, int weight) {
  struct AdjListNode *newNode =
      (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

struct Graph *createGraph(int V) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
  for (int i = 0; i < V; ++i)
    graph->array[i].head = NULL;
  return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight) {
  struct AdjListNode *newNode = newAdjListNode(dest, weight);
  newNode->next = graph->array[src].head;
  graph->array[src].head = newNode;

  newNode = newAdjListNode(src, weight);
  newNode->next = graph->array[dest].head;
  graph->array[dest].head = newNode;
}

struct PQNode {
  int vertex;
  int distance;
};

struct PriorityQueue {
  struct PQNode *nodes;
  int size;
  int capacity;
};

struct PriorityQueue *createPriorityQueue(int capacity) {
  struct PriorityQueue *pq =
      (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
  pq->nodes = (struct PQNode *)malloc(capacity * sizeof(struct PQNode));
  pq->size = 0;
  pq->capacity = capacity;
  return pq;
}

void swapNodes(struct PQNode *a, struct PQNode *b) {
  struct PQNode temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyDown(struct PriorityQueue *pq, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < pq->size &&
      pq->nodes[left].distance < pq->nodes[smallest].distance)
    smallest = left;

  if (right < pq->size &&
      pq->nodes[right].distance < pq->nodes[smallest].distance)
    smallest = right;

  if (smallest != idx) {
    swapNodes(&pq->nodes[idx], &pq->nodes[smallest]);
    heapifyDown(pq, smallest);
  }
}

int isEmpty(struct PriorityQueue *pq) { return pq->size == 0; }

void insert(struct PriorityQueue *pq, int vertex, int distance) {
  if (pq->size == pq->capacity) {
    fprintf(stderr, "Priority queue is full!\n");
    return;
  }

  int i = pq->size;
  pq->nodes[i].vertex = vertex;
  pq->nodes[i].distance = distance;
  pq->size++;

  while (i != 0 && pq->nodes[i].distance < pq->nodes[(i - 1) / 2].distance) {
    swapNodes(&pq->nodes[i], &pq->nodes[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

struct PQNode extractMin(struct PriorityQueue *pq) {
  if (isEmpty(pq)) {
    struct PQNode emptyNode = {-1, INT_MAX};
    return emptyNode;
  }

  struct PQNode root = pq->nodes[0];
  pq->nodes[0] = pq->nodes[pq->size - 1];
  pq->size--;
  heapifyDown(pq, 0);

  return root;
}

void printSolution(int dist[], int n, char *rooms[]) {
  printf("Room \t\t Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%-15s \t %d\n", rooms[i], dist[i]);
}

void dijkstra(struct Graph *graph, int src, char *rooms[]) {
  int V = graph->V;
  int dist[V];

  for (int i = 0; i < V; ++i) {
    dist[i] = INT_MAX;
  }

  struct PriorityQueue *pq = createPriorityQueue(V * V);

  dist[src] = 0;
  insert(pq, src, 0);

  while (!isEmpty(pq)) {
    struct PQNode currentNode = extractMin(pq);
    int u = currentNode.vertex;
    int d = currentNode.distance;

    // If we've found a shorter path already, skip this one
    if (d > dist[u]) {
      continue;
    }

    struct AdjListNode *pCrawl = graph->array[u].head;
    while (pCrawl != NULL) {
      int v = pCrawl->dest;
      int weight = pCrawl->weight;

      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        insert(pq, v, dist[v]);
      }
      pCrawl = pCrawl->next;
    }
  }

  printSolution(dist, V, rooms);
  free(pq->nodes);
  free(pq);
}

// --- Main Function ---
int main() {
  int V = 5;
  char *rooms[] = {"Lobby", "Recording Room", "Control Room", "Vocal Booth",
                   "Lounge"};

  struct Graph *graph = createGraph(V);

  addEdge(graph, 0, 1, 5); // Lobby -> Recording Room (5 mins)
  addEdge(graph, 0, 2, 2); // Lobby -> Control Room (2 mins)
  addEdge(graph, 1, 3, 3); // Recording Room -> Vocal Booth (3 mins)
  addEdge(graph, 1, 2, 2); // Recording Room -> Control Room (2 mins)
  addEdge(graph, 2, 4, 4); // Control Room -> Lounge (4 mins)
  addEdge(graph, 3, 2, 1); // Vocal Booth -> Control Room (1 min)
  addEdge(graph, 4, 0, 3); // Lounge -> Lobby (3 mins)

  dijkstra(graph, 0, rooms);

  // Free graph memory
  for (int i = 0; i < V; i++) {
    struct AdjListNode *pCrawl = graph->array[i].head;
    while (pCrawl != NULL) {
      struct AdjListNode *temp = pCrawl;
      pCrawl = pCrawl->next;
      free(temp);
    }
  }
  free(graph->array);
  free(graph);

  return 0;
}
