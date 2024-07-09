#include <iostream>

const int MAX_VERTICES = 6;  // Maximum number of vertices in the graph

class Graph {
public:
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];


    // Constructor to initialize the graph with a given number of vertices
    Graph(int v) : vertices(v) {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    // Function to add a directed edge from vertex u to vertex v
     void addEdge(int u, int v) {
        // Add an edge from vertex u to vertex v
        adjacencyMatrix[u][v] = 1;
    }

    // Function to perform BFS traversal starting from a given vertex
    void BFS(int startVertex) {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = -1, rear = -1;

        // Enqueue the starting vertex
        queue[++rear] = startVertex;
        visited[startVertex] = true;

        // BFS traversal
        while (front != rear) {
            // Dequeue a vertex from the queue and print it
            int currentVertex = queue[++front];
            std::cout << currentVertex << " ";

            // Enqueue all adjacent vertices of the dequeued vertex that have not been visited
            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    queue[++rear] = i;
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph myGraph(6);

    // Add edges to the graph
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(2, 5);

    // Perform BFS traversal starting from vertex 0
    std::cout << "BFS Traversal starting from vertex 0: ";
    myGraph.BFS(0);
    std::cout << std::endl;

    return 0;
}
