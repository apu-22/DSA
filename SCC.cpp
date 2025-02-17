#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define vamus()                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

vector<vector<int>> graph, transpose;
vector<bool> visited;
stack<int> st;

void dfs1(int node)
{
    visited[node] = true;
    for (auto &neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfs1(neighbor);
    }
    st.push(node);
}

void dfs2(int node, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);
    for (auto &neighbor : transpose[node])
    {
        if (!visited[neighbor])
            dfs2(neighbor, component);
    }
}
void findSSC(int nodes)
{
    // Step 1: Perform DFS and store finish order
    visited.resize(nodes + 1, false);
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
            dfs1(i);
    }

    // Step 2: Transpose the graph
    for (int i = 1; i <= nodes; i++)
    {
        for (int neighbor : graph[i])
        {
            transpose[neighbor].push_back(i);
        }
    }

    // Step 3: Process nodes in decreasing order of finish time
    visited.assign(nodes + 1, false);
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        if (!visited[current])
        {
            vector<int> component;
            dfs2(current, component);

            // Printing the SCC
            cout << "SSC: ";
            for (int i : component)
                cout << i << " ";
            cout << "\n";
        }
    }
}

int main()
{
    vamus();
    int nodes, edges;
    cin >> nodes >> edges;
    graph.resize(nodes + 1);
    transpose.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    findSSC(nodes);
    return 0;
}