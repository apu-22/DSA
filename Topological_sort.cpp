#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void topological(int nodes)
{
    vector<int> deg(nodes, 0);
    for (int i = 0; i < nodes; i++)
    {
        for (auto &neighbor : graph[i])
        {
            deg[neighbor]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < nodes; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }

    vector<int> topo_sort;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        topo_sort.push_back(current);

        for (auto &neighbor : graph[current])
        {
            deg[neighbor]--;
            if (deg[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (topo_sort.size() != nodes)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << "Topological order: ";
    for (int i : topo_sort)
    {
        cout << i << " ";
    }
    cout << "\n";
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    graph.resize(nodes);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // its work for only directed graph
    }

    topological(nodes);
}