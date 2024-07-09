#include <iostream>
#include <algorithm>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

class Graph {
private:
    int vertices, edges, edgeCount;
    Edge* edgeList;

public:
    Graph(int v, int e) : vertices(v), edges(e), edgeCount(0) {
        edgeList = new Edge[edges];
    }

    // Add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        edgeList[edgeCount].src = src;
        edgeList[edgeCount].dest = dest;
        edgeList[edgeCount].weight = weight;
        ++edgeCount;
    }

    // Find set of an element (uses path compression technique)
    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    // Perform union of two sets (uses union by rank)
    void unionSets(Subset subsets[], int x, int y) {
        int rootX = find(subsets, x);
        int rootY = find(subsets, y);

        // Attach the smaller rank tree under the root of the higher rank tree
        if (subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else if (subsets[rootX].rank > subsets[rootY].rank) {
            subsets[rootY].parent = rootX;
        } else {
            // If ranks are the same, make one as the root and increment its rank
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }

    // Kruskal's algorithm to find MST
    void kruskalMST() {
        // Sort the edges based on their weights
        for (int i = 0; i < edges - 1; ++i) {
            for (int j = 0; j < edges - i - 1; ++j) {
                if (edgeList[j].weight > edgeList[j + 1].weight) {
                    std::swap(edgeList[j], edgeList[j + 1]);
                }
            }
        }

        // Allocate memory for subsets
        Subset* subsets = new Subset[vertices];

        // Initialize each subset with its one element
        for (int i = 0; i < vertices; ++i) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        std::cout << "Minimum Spanning Tree (Kruskal's Algorithm):\n";

        for (int i = 0; i < edges; ++i) {
            int rootSrc = find(subsets, edgeList[i].src);
            int rootDest = find(subsets, edgeList[i].dest);

            // If including this edge doesn't cause a cycle, add it to the result
            if (rootSrc != rootDest) {
                std::cout << edgeList[i].src << " -- " << edgeList[i].dest << " : " << edgeList[i].weight << "\n";
                unionSets(subsets, rootSrc, rootDest);
            }
        }

        delete[] subsets;
    }

    ~Graph() {
        delete[] edgeList;
    }
};

int main() {
    Graph g(4, 5);

    // Add edges to the graph
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    // Find and print the MST using Kruskal's algorithm
    g.kruskalMST();

    return 0;
}
