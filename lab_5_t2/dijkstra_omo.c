#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 5
#define E 7

typedef struct Node {
    char name;
    int distance_from_source;
    bool is_visited;
} Node;

typedef struct Edge {
    Node * source;
    int weight;
    Node * destination;
} Edge;

// Dijkstra's Algorithm to find the shortest path between a source vertex
// and all other vertices
void initialize_graph(Node * list_of_nodes[V], Edge * list_of_edges[E]) {
    char names[V] = {'A','B','C','D','E'};
    Node * a = (Node*) malloc(sizeof ( Node ));
    Node * b = (Node*) malloc(sizeof ( Node ));
    Node * c = (Node*) malloc(sizeof ( Node ));
    Node * d = (Node*) malloc(sizeof ( Node ));
    Node * e = (Node*) malloc(sizeof ( Node ));

    list_of_nodes = {a,b,c,d,e};
    for (int i = 0 ; i < V ; i++) {
        list_of_nodes[i]->name = names[i];
        list_of_nodes[i]->distance_from_source = INT_MAX;
        list_of_nodes[i]->is_visited = false;
    }

    Edge * e1 = (Edge*) malloc(sizeof(Edge));
    Edge * e2 = (Edge*) malloc(sizeof(Edge));
    Edge * e3 = (Edge*) malloc(sizeof(Edge));
    Edge * e4 = (Edge*) malloc(sizeof(Edge));
    Edge * e5 = (Edge*) malloc(sizeof(Edge));
    Edge * e6 = (Edge*) malloc(sizeof(Edge));
    Edge * e7 = (Edge*) malloc(sizeof(Edge));

    e1->source = a;
    e1->destination = b;
    e1->weight = 19;

    e2->source = a;
    e2->weight = 7;
    e2->destination = c;

    e3->source = b;
    e3->destination = c;
    e3->weight = 11;

    e4->source = b;
    e4->destination = d;
    e4->weight = 4; 

    e5->source = c;
    e5->destination = d;
    e5->weight = 15;

    e6->source = d;
    e6->destination = e;
    e6->weight = 13;

    e7->source = c;
    e7->destination = e;
    e7->weight = 5;

    for (int i = 0 ; i < E ; i++) {
        list_of_edges[i] = e1;
    }
}

// Entry point for the program
int main() {
    Node* list_of_nodes[V];
    Edge* list_of_edges[E];

    initialize_graph(list_of_nodes,list_of_edges);

    if (list_of_nodes == NULL) {
        printf("Bro nothing happened!");
        return 0;
    }

    for (int i = 0 ; i < E ; i++) {
        printf("%c -%d-> %c\n", list_of_edges[i]->source->name, list_of_edges[i]->weight, list_of_edges[i]->destination->name);
    }

    return 0;
}

