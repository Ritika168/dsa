#include <siostream>
#include <cstdlib>
using namespace std;

#define MAX 100  // Define maximum number of vertices

// Adjacency matrix for the graph
int graph[MAX][MAX];
int visited[MAX];
int n;  // Number of vertices

// Stack structure for DFS
int stack[MAX];
int top = -1;

void push(int vertex) {
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

// Queue structure for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1)
        cout<<"Queue overflow\n";
    else {
        if (front == -1) front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

// Function to initialize the graph
void initializeGraph() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph (undirected graph)
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to perform DFS traversal using stack
void dfs(int startVertex) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    push(startVertex);
    cout<<"DFS traversal: ";
    
    while (!isStackEmpty()) {
        int vertex = pop();

        if (!visited[vertex]) {
           cout<< vertex;
            visited[vertex] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (graph[vertex][i] && !visited[i]) {
                push(i);
            }
        }
    }
    cout<<"\n";
}

// Function to perform BFS traversal using queue
void bfs(int startVertex) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    cout<<"BFS traversal: ";
    
    while (!isQueueEmpty()) {
        int vertex = dequeue();
        cout<< vertex;

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    cout<<"\n";
}

int main() {
    int edges, u, v, startVertex, choice;

    initializeGraph();
    
    cout<<"Enter the number of vertices: ";
    cin>>n;

    cout<<"Enter the number of edges: ";
    cin>>edges;

    cout<<"Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >>u >>v;
        addEdge(u, v);
    }

    while (1) {
        cout<<"\nGraph Traversal Options:\n";
        cout<<"1. DFS\n";
        cout<<"2. BFS\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice == 3) break;

        cout<<"Enter starting vertex: ";
        cin>>startVertex;

        switch (choice) {
            case 1:
                dfs(startVertex);
                break;
            case 2:
                bfs(startVertex);
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }

    return 0;
}
