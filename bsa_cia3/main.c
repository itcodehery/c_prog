#include <stdio.h>
#include <string.h>
#define V 10
#define STR 20
#define INF 9999

char cities[V][STR];

void getCities(int num) {
  int i;
  for (i = 0; i < num; i++) {
    printf("\nEnter the name of City #%d: ", i + 1);
    scanf("%s", cities[i]);
  }

  printf("\nCities Named!\n");
}

int minDistance(int dist[V], int visited[V], int num) {
  int min = INF, min_index = -1;
  int v;
  for (v = 0; v < num; v++)
    if (visited[v] == 0 && dist[v] < min)
      min = dist[v], min_index = v;
  return min_index;
}

void showPath(int path_indices[V], int path_weights[V], int num) {
  int i;
  for (i = 0; i < num; i++) {
    printf("%s -%d-> ", cities[path_indices[i]], path_weights[i]);
  }
  int sum = 0;
  for (i = 0; i < num; i++) {
    sum += path_weights[i];
  }
  printf("\nTotal cost of construction: %d", sum);
}

void prims(int graph[V][V], int src, int num) {
  int path_indices[V], path_weights[V];
  int path_index = -1;
  int dist[V], visited[V];
  int i, count, u, v;

  for (i = 0; i < num; i++) {
    dist[i] = INF;
    visited[i] = 0;
  }
  dist[src] = 0;

  for (count = 0; count < num; count++) {
    u = minDistance(dist, visited, num);
    if (u == -1)
      break;
    visited[u] = 1;

    path_indices[++path_index] = u;
    path_weights[path_index] = dist[u];

    for (v = 0; v < num; v++) {
      if (graph[u][v] && visited[v] == 0 && graph[u][v] < dist[v])
        dist[v] = graph[u][v];
    }
  }

  showPath(path_indices, path_weights, num);
}

void initGraph(int graph[V][V], int num) {
  printf("\nEnter the connections of each city and their construction cost: ");
  int i;
  for (i = 0; i < num; i++) {
    printf("\nEnter for city %d:\n", i);
    int j;
    for (j = 0; j < num; j++) {
      printf("City %d to City %d: ", i, j);
      scanf("%d", &graph[i][j]);
    }
  }
  printf("\nCity Connections initialized!\n");
}

void showCityStructure(int graph[V][V], int num) {
  int i, j;
  for (i = 0; i < num; i++) {
    printf("\n%s to", cities[i]);
    for (j = 0; j < num; j++) {
      printf("\n%s with distance %d", cities[j], graph[i][j]);
    }
  }
}

void createCableNetwork(int num, int graph[V][V]) {
  int src;
  printf("\nSelect the start city: ");
  int i;
  for (i = 0; i < num; i++) {
    printf("\n%d. %s", i, cities[i]);
  }
  printf("\nEnter your choice: ");
  scanf("%d", &src);

  prims(graph, src, num);
}

int main() {
  int ch = 0, num = -1, graph[V][V];
  printf("\nEnter the number of cities (<10): ");
  scanf("%d", &num);

  while (ch != -1) {
    printf("\nSmart City Planning: Cable Network Project");
    printf("\n-------------");
    printf("\n1. Plan for Cities");
    printf("\n2. Show City Network Structure");
    printf("\n3. Create Cable Network from City");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      getCities(num);
      initGraph(graph, num);
      break;

    case 2:
      showCityStructure(graph, num);
      break;

    case 3:
      createCableNetwork(num, graph);
      break;

    case 4:
      ch = -1;
      break;

    default:
      printf("\nInvalid choice!! Please try again!");
      break;
    }
  }
}
