#include <iostream>

// Define the maximum number of vertices
#define MAX_VERTICES 100

class Graph {
private:
    int vertices;
    int adjacencyList[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int v) : vertices(v) {
        // Initialize the adjacency matrix
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                adjacencyList[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        // Add an edge from vertex u to vertex v
        adjacencyList[u][v] = 1;
    }

    void DFSUtil(int vertex, bool visited[]) {
        // Mark the current vertex as visited
        visited[vertex] = true;
        std::cout << vertex << " ";

        // Visit all adjacent vertices
        for (int i = 0; i < vertices; ++i) {
            if (adjacencyList[vertex][i] && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startVertex) {
        // Initialize an array to track visited vertices
        bool visited[MAX_VERTICES];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }

        std::cout << "DFS starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        std::cout << std::endl;
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

    // Perform DFS starting from vertex 0
    myGraph.DFS(0);

    return 0;
}
