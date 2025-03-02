#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<int> dist;
vector<int> parent;

void dijstra(int src, int node)
{
    dist.resize(node + 1, INT_MAX);
    parent.resize(node + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap (distance, node)
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second; // Node with the smallest distance
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, weight] : graph[u])
        {
            int newDist = dist[u] + weight;
            if (newDist < dist[v])
            { // found a sortest path
                dist[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
            }
        }
    }
    cout << "Shortest distance from node: " << src << " to " << "\n";
    for (int i = 1; i <= node; i++)
    {
        cout << i << " is: " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }

    int target;
    cout << "Enter the target node" << "\n";
    cin >> target;

    if (dist[target] == INT_MAX)
    {
        cout << "No path to node " << target << "\n";
        return;
    }

    // Reconstruct shortest path
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    // Print shortest path
    cout << "Shortest path from " << src << " to " << target << " is: " << "\n";
    for (auto i : path)
        cout << i << " ";
    cout << "\n"
         << "And shortest distance between " << src << " to " << target << " is: " << dist[target];
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    graph.resize(edges + 1);

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijstra(source, nodes);
}