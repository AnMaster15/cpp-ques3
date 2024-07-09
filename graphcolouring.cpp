#include <iostream>
#include <vector>
using namespace std;

#define V 4

void printColors(int color[])
{
    cout << "Valid coloring exists. Assigned colors are:" << endl;
    for (int i = 0; i < V; i++)
        cout << " " << color[i];
    cout << endl;
}

bool isColorSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool colorGraphUtil(bool graph[V][V], int numColors, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= numColors; c++) {
        if (isColorSafe(v, graph, color, c)) {
            color[v] = c;
            if (colorGraphUtil(graph, numColors, color, v + 1) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool colorGraph(bool graph[V][V], int numColors)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (colorGraphUtil(graph, numColors, color, 0) == false) {
        cout << "No valid coloring exists.";
        return false;
    }

    printColors(color);
    return true;
}

int main()
{
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    int numColors = 3;
    colorGraph(graph, numColors);
    return 0;
}
