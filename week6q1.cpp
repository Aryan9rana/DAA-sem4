#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adjL[],int visited[],vector<int>&ans){
    visited[node]=1;
    ans.push_back(node);
    for(auto it: adjL[node]){
        if(!visited[it]){
            dfs(it,adjL,visited,ans);
        }
    }    
}
void makeAdjList(vector<vector<int>>&adjM,vector<int> adjL[]){
int n=adjM.size();
int m=adjM[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(adjM[i][j]==1&&i!=j){
            adjL[i].push_back(j);
            // adjL[j].push_back(i);
        }
    }
}
}
vector<int> dfsDriver(int Vertices,vector<vector<int>>&adjM,int u){
    int visited[Vertices]={0};
    vector<int> ans;
    vector<int>adjL[Vertices];
    makeAdjList(adjM,adjL);
    dfs(u,adjL,visited,ans);
    return ans;
}

int main(){
int V,E;
cout<<"enter number of vertices: ";
cin>>V;
cout<<"enter number of edges: ";
cin>>E;
vector<vector<int>>adjM(V, vector<int>(V, 0));
cout<<"enter u and v for all edges: "<<endl;
int u,v;
for(int i=0;i<E;i++){
    cout<<"enter u: ";
    cin>>u;
    cout<<"enter v: ";
    cin>>v;
    adjM[u][v]=1;
    // adjM[v][u]=1;
}
int start,toWhere;
cout<<"enter starting node: ";
cin>>start;
cout<<"enter node to check if path exists: ";
cin>>toWhere;
vector<int>dfs=dfsDriver(V,adjM,start);
int f=0;
cout<<"dfs traversal of start node: "<<endl;
for(int i=0;i<dfs.size();i++){
    cout<<dfs[i]<<" ";
    if(dfs[i]==toWhere) f=1;
}
cout<<endl;
if(f==1) cout<<"path exists"<<endl;
else cout<<"path doesn't exists"<<endl;
}