#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes + 1);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    vector<bool> visited(nodes + 1, false);

    int startNode;
    cin >> startNode;
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS traversal:\n";
    while (!q.empty())
    {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (auto &neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}