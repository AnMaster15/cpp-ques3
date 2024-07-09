#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addEdge(vector<vector<int>> &adj, int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void util(vector<vector<int>> &adj, int v, vector<bool> &visited)
{
    visited[v] = true;
    for (size_t i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];
        if (!visited[u])
            util(adj, u, visited);
    }
}

bool isConnected(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    int i;
    for (i = 0; i < V; ++i)
    {
        if (!adj[i].empty())
            break;
    }
    util(adj, i, visited);
    for (i = 0; i < V; ++i)
    {
        if (!visited[i] && !adj[i].empty())
            return false;
    }
    return true;
}

int countodd(vector<vector<int>> &adj, int V)
{
    int odd = 0;
    for (int i = 0; i < V; ++i)
    {
        if (adj[i].size() % 2 != 0)
            odd++;
    }
    return odd;
}

int isEulerian(vector<vector<int>> &adj, int V)
{
    if (!isConnected(adj, V))
        return 0;
    int odd = countodd(adj, V);
    return odd == 0 ? 2 : (odd == 2 ? 1 : 0);
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    int res = isEulerian(adj, V);
    cout << "Graph 1: ";
    if (res == 0)
        cout << "not Eulerian\n";
    else if (res == 1)
        cout << "has a Euler path\n";
    else
        cout << "has a Euler cycle\n";

    adj.clear();
    adj.resize(V);

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    res = isEulerian(adj, V);
    cout << "Graph 2: ";
    if (res == 0)
        cout << "not Eulerian\n";
    else if (res == 1)
        cout << "has a Euler path\n";
    else
        cout << "has a Euler cycle\n";

    adj.clear();
    adj.resize(V);

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 1, 3);
    res = isEulerian(adj, V);
    cout << "Graph 3: ";
    if (res == 0)
        cout << "not Eulerian\n";
    else if (res == 1)
        cout << "has a Euler path\n";
    else
        cout << "has a Euler cycle\n";

    adj.clear();
    adj.resize(3);

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    res = isEulerian(adj, 3);
    cout << "Graph 4: ";
    if (res == 0)
        cout << "not Eulerian\n";
    else if (res == 1)
        cout << "has a Euler path\n";
    else
        cout << "has a Euler cycle\n";

    adj.clear();
    adj.resize(3);

    res = isEulerian(adj, 3);
    cout << "Graph 5: ";
    if (res == 0)
        cout << "not Eulerian\n";
    else if (res == 1)
        cout << "has a Euler path\n";
    else
        cout << "has a Euler cycle\n";

    return 0;
}
