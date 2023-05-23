#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
int indegree[V] = {0};
for (int i = 0; i < V; i++) {
for (auto it : adj[i]) {
indegree[it]++;
}
}

queue<int> q;
for (int i = 0; i < V; i++) {
if (indegree[i] == 0) {
q.push(i);
}
}

int cnt = 0;
// o(v + e)
while (!q.empty()) {
int node = q.front();
q.pop();
cnt++;
// node is in your topo sort
// so please remove it from the indegree

for (auto it : adj[node]) {
indegree[it]--;
if (indegree[it] == 0) q.push(it);
}
}

if (cnt == V) return false;
return true;
}
};


int main() {

int V,E;
cout<<"enter number of vertices: ";
cin>>V;
cout<<"enter number of edges: ";
cin>>E;
cout<<"enter edge u to v: "<<endl;
int u,v;
vector<int> adj[V];
for(int i=0;i<E;i++){
    cout<<"enter u: ";
    cin>>u;
    cout<<"enter v: ";
    cin>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    
}
Solution obj;
bool ans = obj.isCyclic(V, adj);
if (ans) cout << "Yes Cycle Exists'";
else cout << "No, Cycle does not Exist'";
cout << endl;
return 0;
}
