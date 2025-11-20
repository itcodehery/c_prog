# Minimum Spanning Tree for Music Studio Setup

This project implements Prim's and Kruskal's algorithms to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. The problem is modeled around setting up a music studio, where the graph's vertices represent pieces of equipment and the edge weights represent the cost of connecting them (e.g., cable cost or length).

## Graph Representation

The studio equipment is represented as follows:

*   **Vertices (Nodes):**
    1.  Audio Interface
    2.  DAW (Digital Audio Workstation)
    3.  Microphone
    4.  Synthesizer
    5.  Monitor Speakers

*   **Edges (Connections):**
    The connections and their costs (weights) are:
    *   Audio Interface - DAW: 10
    *   Audio Interface - Microphone: 20
    *   Audio Interface - Monitor Speakers: 15
    *   DAW - Microphone: 25
    *   DAW - Synthesizer: 30
    *   Microphone - Monitor Speakers: 35
    *   Synthesizer - Monitor Speakers: 5

## Algorithms Implemented

1.  **Kruskal's Algorithm:**
    *   **Implementation:** Uses an edge list to store all connections and a Disjoint Set Union (DSU) data structure to detect cycles.
    *   **Logic:** It sorts all edges by weight in non-decreasing order. Then, it iterates through the sorted edges, adding an edge to the MST if it connects two previously unconnected components of the graph.

2.  **Prim's Algorithm:**
    *   **Implementation:** Uses an adjacency matrix to represent the graph.
    *   **Logic:** It builds the MST by starting from an arbitrary vertex and iteratively adding the cheapest edge that connects a vertex in the MST to a vertex outside the tree.

## How to Compile and Run

1.  **Compile the code:**
    ```bash
    gcc mst_studio.c -o mst_studio
    ```

2.  **Run the executable:**
    ```bash
    ./mst_studio
    ```

You will be prompted to choose which algorithm to run.

## Complexity Analysis

*   **Kruskal's Algorithm:**
    *   **Time Complexity:** O(E log E), where E is the number of edges. This is dominated by the time it takes to sort the edges. The DSU operations are nearly constant time.
    *   **Space Complexity:** O(V + E), where V is the number of vertices and E is the number of edges, to store the graph and the DSU structure.

*   **Prim's Algorithm:**
    *   **Time Complexity:** O(V^2) with the current adjacency matrix implementation. It can be improved to O(E log V) with a priority queue (min-heap).
    *   **Space Complexity:** O(V^2) for the adjacency matrix.

## Correctness and Validation

*   **Validation:** The code does not include explicit input validation. It uses a hardcoded graph. For a production system, you would need to validate that the graph is connected and that edge weights are positive.
*   **Correctness:** Both algorithms are greedy algorithms that are proven to find the MST for any connected, undirected graph with weighted edges. They will produce a tree that connects all vertices with the minimum possible total edge weight.

## Manual Workout (Kruskal's Algorithm)

1.  **List all edges and sort by weight:**
    *   Synthesizer - Monitor Speakers: 5
    *   Audio Interface - DAW: 10
    *   Audio Interface - Monitor Speakers: 15
    *   Audio Interface - Microphone: 20
    *   DAW - Microphone: 25
    *   DAW - Synthesizer: 30
    *   Microphone - Monitor Speakers: 35

2.  **Build the MST:**
    *   Add **Synthesizer - Monitor Speakers (5)**.
    *   Add **Audio Interface - DAW (10)**.
    *   Add **Audio Interface - Monitor Speakers (15)**. Now {Synthesizer, Monitor Speakers, Audio Interface, DAW} are connected.
    *   Add **Audio Interface - Microphone (20)**. Now all 5 vertices are connected.
    *   Stop. The MST is formed.

3.  **Result:**
    *   Total Cost = 5 + 10 + 15 + 20 = **50**
    *   Edges: (Synthesizer, Monitor Speakers), (Audio Interface, DAW), (Audio Interface, Monitor Speakers), (Audio Interface, Microphone)

*(Note: The output of Prim's algorithm will result in the same total cost but may select a different set of edges if multiple edges have the same weight).*
