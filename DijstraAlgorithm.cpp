#include <bits\stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii>> graph;
vector<int> dist;

void dijstra(int src, int node)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist.resize(node + 1, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;
        for (auto [v, weight] : graph[u])
        {
            int newDist = dist[u] + weight;
            if (newDist < dist[v])
            {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    cout << "Shortest distance from node: " << src << " to " << "\n";
    for (int i = 1; i <= node; i++)
    {
        cout << i << " is: " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    graph.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << "Inter the source node: ";
    int sourch;
    cin >> sourch;

    dijstra(sourch, nodes);
}