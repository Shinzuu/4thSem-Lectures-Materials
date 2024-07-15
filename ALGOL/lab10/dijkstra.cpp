#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int V;

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V, int parent[])
{
    cout << "Vertex \t Distance from Source \t\t Path" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t" << dist[i] << " \t\t\t";
        vector<int> path;
        int j = i;
        while (j != -1)
        {
            path.push_back(j);
            j = parent[j];
        }
        for (int k = path.size() - 1; k >= 0; k--)
        {
            cout << path[k];
            if (k != 0)
                cout << " -> ";
        }
        cout << endl;
    }
}

void dijkstra(int **graph, int src, int V)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1; // Initialize parent array to -1 (no parent)
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, V, parent);
}

int main()
{
    int vertex, edge, source;

    cin >> vertex >> edge >> source;
    V = vertex;

    int **graph = new int *[vertex];
    for (int i = 0; i < vertex; i++)
    {
        graph[i] = new int[vertex];
        for (int j = 0; j < vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    dijkstra(graph, source, V);

    for (int i = 0; i < vertex; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
