#include<iostream> 
#include <vector>
 #include <climits>

using namespace std;


const int INF=INT_MAX;


int shortestPathWithKEdges(vector<vector<int>>&adjM,int source,int destination,int k){ int V = adjM.size();

vector<vector<vector<int>>>dp(V,vector<vector<int>>(V, vector<int>(k + 1, INF)));


if(k==0&&source==destination){ return 0;
}
for (int i = 0; i < V; i++) { for(int j=0;j<V;j++){
dp[i][j][0]= adjM[i][j];
}
}
for(int e=1;e<=k; e++) {
for (int u = 0; u < V; u++) { 
for(int v=0;v<V;v++){
dp[u][v][e]=dp[u][v][e-1];//Theshortestpathwitheedges isthesameasthe shortest path with e-1 edges
for(int w =0;w <V; w++){
if(dp[u][w][e-1]!=INF&&adjM[w][v]!= INF){
dp[u][v][e]=min(dp[u][v][e],dp[u][w][e -1] + adjM[w][v]);
}}}}}
return dp[source][destination][k];
}


int main() {
int V,E;
cout<<"Enter the number of vertices:"; cin >> V;

vector<vector<int>>adjM(V, vector<int>(V, 0));
for (int i = 0; i < V; i++) {
for(int j=0;j<V;j++){
cin >> adjM[i][j];
if(adjM[i][j]==-1){
adjM[i][j]=INF;
}
}
}
int source,destination,k;
 
cout<<"Enter the source vertex:"; cin >> source;
cout<<"Enter the destination vertex:"; cin >> destination;
cout<<"Enter the number of edges(k):"; cin >> k;

int shortestPathWeight=shortestPathWithKEdges(adjM,source,destination,k);


if(shortestPathWeight ==INF){
cout<<"There is no path from source to destination with exactly "<<k <<"edges.\n";
}else {
cout<<"The weight of the shortest path from source to destination with exactly "<<k
<<" edge(s) is:"<<shortestPathWeight<<endl;
}


return 0;
}
