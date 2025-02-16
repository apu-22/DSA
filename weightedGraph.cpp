#include<bits/stdc++.h>
using namespace std;

void weightedGraphMtrix(int nodes,int egdes){
    vector<vector<int>>graph(nodes+1,vector<int>(nodes+1,0));
    for(int i=0;i<nodes;i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u][v]=w;
        // graph[v][u]=w;
    }

    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void weightedGraphList(int nodes,int edges){
    vector<vector<pair<int,int>>> graph(nodes+1);
    for(int i=0;i<nodes;i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        // graph[v].push_back({u,w});
    }

    for(int i=1;i<=nodes;i++){
        cout<<i<<" - >";
        for(auto &neighbor : graph[i]){
            cout<<"("<< neighbor.first<<","<<neighbor.second<<")";
        }
        cout<<"\n";
    }
}
int main(){
    int nodes,edges; cin>>nodes>>edges;
    cout<<"Undirected weighted graph represented using adjacency matrix:\n";
    weightedGraphMtrix(nodes,edges);
    cout<<"\n\nUndirected weighted graph represented using adjacency list:\n";
    weightedGraphList(nodes,edges);
}