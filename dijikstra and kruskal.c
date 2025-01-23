#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

// Structure for representing edges in the graph (used in Kruskal's algorithm)
typedef struct {
    int u, v, weight;
} Edge;

// Function to perform Dijkstra's Shortest Path Algorithm
void dijkstra(int graph[MAX][MAX], int vertices, int start) {
    int dist[MAX], visited[MAX], i, j;

    // Initialize distance array
    for (i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < vertices - 1; i++) {
        // Find the vertex with the minimum distance that hasn't been visited
        int minDist = INF, u = -1;
        for (j = 0; j < vertices; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;  // Mark the vertex as visited

        // Update the distances of adjacent vertices
        for (j = 0; j < vertices; j++) {
            if (!visited[j] && graph[u][j] != INF && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Print the shortest distances from the start vertex
    printf("\nShortest distances from vertex %d:\n", start);
    for (i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d is unreachable\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}

// Function to find the parent of a node (used in Kruskal's algorithm)
int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Function to perform union of two sets (used in Kruskal's algorithm)
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[xroot] = yroot;
        rank[yroot]++;
    }
}

// Function to perform Kruskal's Minimum Spanning Tree Algorithm
void kruskal(Edge edges[], int vertices, int edgesCount) {
    int parent[vertices], rank[vertices], i;
    Edge result[vertices - 1];  // To store the resulting MST
    int e = 0;  // Count of edges in MST
    int iEdge = 0;  // Initial index of sorted edges

    // Initialize parent and rank arrays
    for (i = 0; i < vertices; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    // Sort the edges by weight in ascending order (using bubble sort)
    for (i = 0; i < edgesCount - 1; i++) {
        for (int j = 0; j < edgesCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges[j] and edges[j + 1]
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Process each edge in sorted order
    while (e < vertices - 1 && iEdge < edgesCount) {
        int x = findParent(parent, edges[iEdge].u);
        int y = findParent(parent, edges[iEdge].v);

        // If including this edge does not cause a cycle, include it in the MST
        if (x != y) {
            result[e++] = edges[iEdge];
            unionSets(parent, rank, x, y);
        }
        iEdge++;
    }

    // Print the edges of the MST
    printf("\nEdges in the Minimum Spanning Tree (MST):\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++) {
        printf("%d - %d (Weight: %d)\n", result[i].u, result[i].v, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

// Main function
int main() {
    int vertices, edgesCount, choice;
    int graph[MAX][MAX];
    Edge edges[MAX];
    
    // Initialize the graph with infinity (INF)
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = INF;
        }
    }

    // Take input for vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edgesCount);

    // Take input for edges (for both Dijkstra and Kruskal)
    printf("Enter the edges (u v weight) for the graph:\n");
    for (int i = 0; i < edgesCount; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        graph[edges[i].u][edges[i].v] = edges[i].weight;
        graph[edges[i].v][edges[i].u] = edges[i].weight;  // Undirected graph
    }

    while (1) {
        printf("\nSelect algorithm to run:\n");
        printf("1. Dijkstra's Shortest Path\n");
        printf("2. Kruskal's Minimum Spanning Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int start;
                printf("Enter the starting vertex for Dijkstra: ");
                scanf("%d", &start);
                dijkstra(graph, vertices, start);
                break;
            }
            case 2:
                kruskal(edges, vertices, edgesCount);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
