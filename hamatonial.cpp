#include <iostream>
#include <vector>
using namespace std;

const int V = 5;

bool Safe(const vector<vector<int>>& adjMatrix, vector<int>& path, int vertex, int position) {
    if (adjMatrix[path[position - 1]][vertex] == 0)
        return false;

    for (int i = 0; i < position; ++i) {
        if (path[i] == vertex)
            return false;
    }

    return true;
}

bool hamiltonianCycleUtil(const vector<vector<int>>& adjMatrix, vector<int>& path, int position) {
    if (position == V) {
        if (adjMatrix[path[position - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int vertex = 0; vertex < V; vertex++) {
        if (Safe(adjMatrix, path, vertex, position)) {
            path[position] = vertex;

            if (hamiltonianCycleUtil(adjMatrix, path, position + 1))
                return true;

            path[position] = -1;
        }
    }

    return false;
}

void findHamiltonianCycle(const vector<vector<int>>& adjMatrix) {
    vector<int> path(V, -1);
    path[0] = 0;

    if (!hamiltonianCycleUtil(adjMatrix, path, 1)) {
        cout << "\nSolution does not exist";
        return;
    }

    cout << "Solution Exists: Following is one Hamiltonian Cycle\n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << " ";
    cout << endl;
}

int main() {
    vector<vector<int>> graph1 = {{0, 1, 0, 1, 0},
                                  {1, 0, 1, 1, 1},
                                  {0, 1, 0, 0, 1},
                                  {1, 1, 0, 0, 1},
                                  {0, 1, 1, 1, 0}};

    findHamiltonianCycle(graph1);

    vector<vector<int>> graph2 = {{0, 1, 0, 1, 0},
                                  {1, 0, 1, 1, 1},
                                  {0, 1, 0, 0, 1},
                                  {1, 1, 0, 0, 0},
                                  {0, 1, 1, 0, 0}};

    findHamiltonianCycle(graph2);

    return 0;
}
