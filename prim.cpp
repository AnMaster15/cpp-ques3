#include <iostream>
#include <climits>

// Number of vertices in the graph
#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the MST using parent array
void printMST(int parent[], int graph[V][V]) {
    std::cout << "Minimum Spanning Tree (Prim's Algorithm):\n";
    for (int i = 1; i < V; ++i) {
        std::cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
    }
}

// Function to implement Prim's algorithm for a given graph
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values to pick the minimum weight edge

    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    // Make the key 0 so that this vertex is picked as the first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V-1 vertices
    for (int count = 0; count < V - 1; ++count) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices
        // of the picked vertex. Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Find and print the MST using Prim's algorithm
    primMST(graph);

    return 0;
}
