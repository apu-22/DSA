#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void DfsHelper(int node) {
    visited[node] = true;
    cout << node << " ";

    for (auto &neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DfsHelper(neighbor);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    graph.assign(nodes + 1, vector<int>());  // Resize adjacency list
    visited.assign(nodes + 1, false);        // Resize visited array

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Remove for directed graph
    }

    int startNode;
    cin >> startNode;

    cout << "DFS traversal:\n";
    DfsHelper(startNode);
    cout << "\n";

    return 0;
}
