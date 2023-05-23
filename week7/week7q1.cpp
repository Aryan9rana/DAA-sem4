#include<iostream> 
#include <vector> 
#include <queue> 
#include <climits>

using namespace std;


typedef pair<int,int>pii;
void dijkstra(vector<vector<pii> >&graph,int startNode,vector<int>&distances){ int V = graph.size();
distances.assign(V, INT_MAX); priority_queue<pii,vector<pii>,greater<pii>>pq; distances[startNode] = 0;
pq.push({0, startNode});


while(!pq.empty()){
int currNode=pq.top().second; int currDist = pq.top().first; pq.pop();

if(currDist>distances[currNode]){ continue;
 
}
for(auto neighbor:graph[currNode]){ int nextNode = neighbor.first;
int edgeWeight = neighbor.second;int totalDist=currDist+edgeWeight; if (totalDist < distances[nextNode]) {
distances[nextNode]=totalDist; pq.push({totalDist, nextNode});
}
}
}
}


int main() {
int V, E;
cout<<"Enter the number of nodes:"; cin >> V;
cout<<"Enter the number of edges:"; cin >> E;

vector<vector<pii>>graph(V);


cout<<"Enter the edges and their weights:\n"; 
int u, v, w;
for (int i = 0; i < E; i++) {
cout<<"enter u: ";
cin >> u;
cout<<"enter v:";
cin>> v;
cout <<"enter weight of the egde: ";
cin>> w;
graph[u].push_back({v,w});
graph[v].push_back({u,w});
}
 
int startNode;
cout<<"Enter the starting node:"; 
cin >> startNode;

vector<int> distances; 
dijkstra(graph,startNode,distances);

cout<<"Shortest distances from starting node "<<startNode<<"= \n"; 
for (int i = 0; i < V; i++) {
cout<<"Node"<< i <<": ";
if(distances[i]==INT_MAX){ cout <<"Not reachable\n";
}else {
cout<<distances[i]<<"\n";
}
}


return 0;
} 
#include<iostream> 
#include <vector> 
#include <queue> 
#include <climits>

using namespace std;


typedef pair<int,int>pii;
void dijkstra(vector<vector<pii> >&graph,int startNode,vector<int>&distances){ int V = graph.size();
distances.assign(V, INT_MAX); priority_queue<pii,vector<pii>,greater<pii>>pq; distances[startNode] = 0;
pq.push({0, startNode});


while(!pq.empty()){
int currNode=pq.top().second; int currDist = pq.top().first; pq.pop();

if(currDist>distances[currNode]){ continue;
 
}
for(auto neighbor:graph[currNode]){ int nextNode = neighbor.first;
int edgeWeight = neighbor.second;int totalDist=currDist+edgeWeight; if (totalDist < distances[nextNode]) {
distances[nextNode]=totalDist; pq.push({totalDist, nextNode});
}
}
}
}


int main() {
int V, E;
cout<<"Enter the number of nodes:"; cin >> V;
cout<<"Enter the number of edges:"; cin >> E;

vector<vector<pii>>graph(V);


cout<<"Enter the edges and their weights:\n"; 
int u, v, w;
for (int i = 0; i < E; i++) {
cout<<"enter u: ";
cin >> u;
cout<<"enter v:";
cin>> v;
cout <<"enter weight of the egde: ";
cin>> w;
graph[u].push_back({v,w});
graph[v].push_back({u,w});
}
 
int startNode;
cout<<"Enter the starting node:"; 
cin >> startNode;

vector<int> distances; 
dijkstra(graph,startNode,distances);

cout<<"Shortest distances from starting node "<<startNode<<"= \n"; 
for (int i = 0; i < V; i++) {
cout<<"Node"<< i <<": ";
if(distances[i]==INT_MAX){ cout <<"Not reachable\n";
}else {
cout<<distances[i]<<"\n";
}
}


return 0;
} 
