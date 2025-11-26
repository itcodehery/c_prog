#include <stdio.h>
#define V 5

int breadth_first_search(int v, int adj[V], int s) {
  int level[V];
  level[s] = 0;
  int lvl_count = 1;
  int recently_visited[V] = {s};

  return 0;
}

int main() {
  int adj[V];
  int start;

  breadth_first_search(V, adj, start);
  return 0;
}
