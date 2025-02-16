#include<bits\stdc++.h>
using namespace std;
void adjacencyMatrix(int nodes,int edges){
    vector<vector<int>>graph(nodes+1,vector<int>(nodes+1,0));
    for(int i=0;i<edges;i++){
        int u,v; cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    cout<<"Adjacency matrix of graph\n";
    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void adjacencyList(int nodes,int edges){
    vector<vector<int>>graph(nodes+1);
    for(int i=0;i<edges;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<"Adjacency List of graph\n";
    for(int i=1;i<=nodes;i++){
        cout<<i<<"->";
        for(int neighbor:graph[i]){
            cout<<neighbor<<" ";
        }
        cout<<"\n";
    }
}
int main(){ 
    int nodes,edges; cin>>nodes>>edges;
    adjacencyMatrix(nodes,edges);
    cout<<"\n\n";
    adjacencyList(nodes,edges);
    
}