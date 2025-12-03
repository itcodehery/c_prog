#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
  int vertex;
  struct Node *next;
} Node;

typedef struct {
  int vertices;
  Node *adj[MAX_VERTICES];
} Graph;

typedef struct {
  int items[MAX_VERTICES];
  int front, rear;
} Queue;

typedef struct {
  int items[MAX_VERTICES];
  int top;
} Stack;

void initQueue(Queue *q) {
  q->front = -1;
  q->rear = -1;
}

bool isQueueEmpty(Queue *q) { return q->front == -1; }

void enqueue(Queue *q, int value) {
  if (q->front == -1)
    q->front = 0;
  q->rear++;
  q->items[q->rear] = value;
}

int dequeue(Queue *q) {
  int item = q->items[q->front];
  q->front++;
  if (q->front > q->rear) {
    q->front = q->rear = -1;
  }
  return item;
}

void initStack(Stack *s) { s->top = -1; }

bool isStackEmpty(Stack *s) { return s->top == -1; }

void push(Stack *s, int value) { s->items[++(s->top)] = value; }

int pop(Stack *s) { return s->items[(s->top)--]; }

void initGraph(Graph *g) {
  g->vertices = 0;
  for (int i = 0; i < MAX_VERTICES; i++) {
    g->adj[i] = NULL;
  }
}

void addEdge(Graph *g, int src, int dest) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = dest;
  newNode->next = g->adj[src];
  g->adj[src] = newNode;
}

void freeGraph(Graph *g) {
  for (int i = 0; i < g->vertices; i++) {
    Node *temp = g->adj[i];
    while (temp != NULL) {
      Node *toFree = temp;
      temp = temp->next;
      free(toFree);
    }
  }
}

void createGraph(Graph *g) {
  int edges, src, dest;

  freeGraph(g);

  printf("\nEnter number of vertices: ");
  scanf("%d", &g->vertices);

  if (g->vertices <= 0 || g->vertices > MAX_VERTICES) {
    printf("Invalid number of vertices!\n");
    g->vertices = 0;
    return;
  }

  for (int i = 0; i < g->vertices; i++) {
    g->adj[i] = NULL;
  }

  printf("Enter number of edges: ");
  scanf("%d", &edges);

  printf("\nEnter edges (source destination) [0 to %d]:\n", g->vertices - 1);
  for (int i = 0; i < edges; i++) {
    printf("Edge %d: ", i + 1);
    scanf("%d %d", &src, &dest);

    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
      addEdge(g, src, dest);
    } else {
      printf("Invalid edge! Skipping...\n");
      i--;
    }
  }

  printf("\nGraph created successfully!\n");
}

void displayGraph(Graph *g) {
  if (g->vertices == 0) {
    printf("\nGraph is empty!\n");
    return;
  }

  printf("\nAdjacency List:\n");
  for (int i = 0; i < g->vertices; i++) {
    printf("%d -> ", i);
    Node *temp = g->adj[i];
    while (temp != NULL) {
      printf("%d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void BFT(Graph *g, int start) {
  if (g->vertices == 0) {
    printf("\nGraph is empty!\n");
    return;
  }

  bool visited[MAX_VERTICES] = {false};
  Queue q;
  initQueue(&q);

  printf("\nBFS Traversal starting from vertex %d: ", start);

  visited[start] = true;
  enqueue(&q, start);

  while (!isQueueEmpty(&q)) {
    int current = dequeue(&q);
    printf("%d ", current);

    Node *temp = g->adj[current];
    while (temp != NULL) {
      if (!visited[temp->vertex]) {
        visited[temp->vertex] = true;
        enqueue(&q, temp->vertex);
      }
      temp = temp->next;
    }
  }
  printf("\n");
}

void DFTUtil(Graph *g, int vertex, bool visited[]) {
  visited[vertex] = true;
  printf("%d ", vertex);

  Node *temp = g->adj[vertex];
  while (temp != NULL) {
    if (!visited[temp->vertex]) {
      DFTUtil(g, temp->vertex, visited);
    }
    temp = temp->next;
  }
}

void DFT(Graph *g, int start) {
  if (g->vertices == 0) {
    printf("\nGraph is empty!\n");
    return;
  }

  bool visited[MAX_VERTICES] = {false};

  printf("\nDFS Traversal starting from vertex %d: ", start);
  DFTUtil(g, start, visited);
  printf("\n");
}

bool isCyclicUtil(Graph *g, int v, bool visited[], bool recStack[]) {
  if (!visited[v]) {
    visited[v] = true;
    recStack[v] = true;

    Node *temp = g->adj[v];
    while (temp != NULL) {
      if (!visited[temp->vertex] &&
          isCyclicUtil(g, temp->vertex, visited, recStack)) {
        return true;
      } else if (recStack[temp->vertex]) {
        return true;
      }
      temp = temp->next;
    }
  }
  recStack[v] = false;
  return false;
}

bool isDAG(Graph *g) {
  if (g->vertices == 0) {
    printf("\nGraph is empty!\n");
    return false;
  }

  bool visited[MAX_VERTICES] = {false};
  bool recStack[MAX_VERTICES] = {false};

  for (int i = 0; i < g->vertices; i++) {
    if (!visited[i]) {
      if (isCyclicUtil(g, i, visited, recStack)) {
        return false;
      }
    }
  }
  return true;
}

void topologicalSortUtil(Graph *g, int v, bool visited[], Stack *s) {
  visited[v] = true;

  Node *temp = g->adj[v];
  while (temp != NULL) {
    if (!visited[temp->vertex]) {
      topologicalSortUtil(g, temp->vertex, visited, s);
    }
    temp = temp->next;
  }

  push(s, v);
}

void topologicalSort(Graph *g) {
  if (g->vertices == 0) {
    printf("\nGraph is empty!\n");
    return;
  }

  if (!isDAG(g)) {
    printf("\nTopological sort not possible! Graph contains cycle.\n");
    return;
  }

  Stack s;
  initStack(&s);
  bool visited[MAX_VERTICES] = {false};

  for (int i = 0; i < g->vertices; i++) {
    if (!visited[i]) {
      topologicalSortUtil(g, i, visited, &s);
    }
  }

  printf("\nTopological Order: ");
  while (!isStackEmpty(&s)) {
    printf("%d ", pop(&s));
  }
  printf("\n");
}

void traversalMenu(Graph *g) {
  int choice, start;

  do {
    printf("\n--- Traversal Menu ---\n");
    printf("1. BFS (Breadth First Traversal)\n");
    printf("2. DFS (Depth First Traversal)\n");
    printf("3. Back to Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      if (g->vertices > 0) {
        printf("Enter starting vertex [0 to %d]: ", g->vertices - 1);
        scanf("%d", &start);
        if (start >= 0 && start < g->vertices) {
          BFT(g, start);
        } else {
          printf("Invalid vertex!\n");
        }
      } else {
        printf("\nGraph is empty!\n");
      }
      break;

    case 2:
      if (g->vertices > 0) {
        printf("Enter starting vertex [0 to %d]: ", g->vertices - 1);
        scanf("%d", &start);
        if (start >= 0 && start < g->vertices) {
          DFT(g, start);
        } else {
          printf("Invalid vertex!\n");
        }
      } else {
        printf("\nGraph is empty!\n");
      }
      break;

    case 3:
      printf("\nReturning to main menu...\n");
      break;

    default:
      printf("\nInvalid choice! Try again.\n");
    }
  } while (choice != 3);
}

int main() {
  Graph g;
  initGraph(&g);
  int choice;

  do {
    printf("\n========================================\n");
    printf("    DIRECTED GRAPH OPERATIONS\n");
    printf("========================================\n");
    printf("1. Create a graph\n");
    printf("2. Check DAG\n");
    printf("3. Traversal (BFT & DFT)\n");
    printf("4. Topological sort\n");
    printf("5. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
      createGraph(&g);
      displayGraph(&g);
      break;

    case 2:
      if (isDAG(&g)) {
        printf("\nThe graph is a DAG (Directed Acyclic Graph).\n");
      } else {
        printf("\nThe graph is NOT a DAG. It contains cycles.\n");
      }
      break;

    case 3:
      traversalMenu(&g);
      break;

    case 4:
      topologicalSort(&g);
      break;

    case 5:
      printf("\nExiting program. Goodbye!\n");
      freeGraph(&g);
      break;

    default:
      printf("\nInvalid choice! Please try again.\n");
    }
  } while (choice != 5);

  return 0;
}
