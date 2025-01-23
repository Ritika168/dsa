#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX_NODES 100

// Structure to represent a weighted edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Helper function to initialize subsets for union-find
void initializeSubsets(Subset subsets[], int vertices) {
    for (int i = 0; i < vertices; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
}

// Find function with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function by rank
void Union(Subset subsets[], int x, int y) {
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

// Kruskal's algorithm to find Minimum Spanning Tree
void KruskalMST(Edge edges[], int vertices, int numEdges) {
    // Sort edges by weight
    sort(edges, edges + numEdges, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    Subset subsets[MAX_NODES];
    initializeSubsets(subsets, vertices);

    Edge result[MAX_NODES];  // Array to store the MST
    int e = 0;  // Count of edges in the MST
    int i = 0;  // Index for sorted edges

    while (e < vertices - 1 && i < numEdges) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause a cycle, include it in result
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the MST
    cout << "Edges in MST:\n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
}

// Dijkstra's algorithm to find the shortest path from source to all vertices
void Dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int vertices) {
    int dist[MAX_NODES];
    bool visited[MAX_NODES] = {false};

    // Initialize distances
    for (int i = 0; i < vertices; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int min = INT_MAX, u;

        // Find the vertex with the minimum distance that hasn't been visited
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update the distance of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances from src
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main() {
    int vertices = 5;  // Number of vertices in the graph

    // Example graph represented as an adjacency matrix
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Dijkstra's Shortest Path from vertex 0:\n";
    Dijkstra(graph, 0, vertices);

    // Example edges for Kruskal's algorithm
    Edge edges[] = {
        {0, 1, 2},
        {1, 2, 3},
        {0, 3, 6},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    cout << "\nKruskal's Minimum Spanning Tree:\n";
    KruskalMST(edges, vertices, numEdges);

    return 0;
}
