
#include<iostream> 
#include <vector> 
#include <climits>

using namespace std;


struct Edge{ int source;
int destination; int weight;
};
void bellmanFord(vector<Edge>&edges,int V,int source){ 
    vector<int> distances(V, INT_MAX);
vector<int>parent(V,-1);


distances[source]=0;
for(int i=1;i<V;i++){ for (const auto& edge : edges) {
int u =edge.source;
int v = edge.destination; int weight=edge.weight;

if(distances[u]!=INT_MAX&&distances[u]+weight<distances[v]){ 
    distances[v] = distances[u] + weight;
parent[v]=u;
}
 
}
}


for(const auto&edge:edges){ int u = edge.source;
int v = edge.destination; int weight=edge.weight;

if(distances[u]!=INT_MAX&&distances[u]+weight<distances[v]){ cout <<"Negative-weight cycle detected!\n";
return;
}
}
for(int i=0;i<V;i++){ if (i == source) {
continue;
}


vector<int>path; int currNode = i;

while (currNode != -1) { path.push_back(currNode); currNode=parent[currNode];
}


cout<<"Path from node "<<i<<" to node "<<source<<": "; 
for (int j = path.size() - 1; j >= 0; j--) {
cout<<path[j]; if (j != 0) {
 
cout <<" ->";
}
}


cout<<"(Weight: "<<distances[i]<<")\n";
}
}


int main() {
int V, E;
cout<<"Enter the number of vertices: "; cin >> V;
cout<<"Enter the number of edges: "; cin >> E;

vector<Edge>edges(E);


cout<<"Enter the edges u to v and their weights: \n";
int u, v, w;
for (int i = 0; i < E; i++) {
cout<<"enter u: ";
cin >> u;
cout<<"enter v:";
cin>> v;
cout <<"enter weight of the egde: ";
cin>> w;
edges[i].source = u; 
edges[i].destination=v; edges[i].weight = w;
}


int source;
cout<<"Enter the source vertex:"; cin >> source;
 
bellmanFord(edges,V, source);


return 0;
}
