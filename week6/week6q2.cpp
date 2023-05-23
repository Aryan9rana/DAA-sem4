

#include <iostream>
#include <queue>
 
using namespace std;
 


bool isBipartite(int V,vector<vector<int> >&G, int src)
{
    
    
    
    
    
    
    
    
    
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
 
    
    colorArr[src] = 1;
 
    
    
    
    queue <int> q;
    q.push(src);
 
    
    
    while (!q.empty())
    {
        
        int u = q.front();
        q.pop();
 
        
        if (G[u][u] == 1)
        return false;
 
        
        for (int v = 0; v < V; ++v)
        {
            
            
            if (G[u][v] && colorArr[v] == -1)
            {
                
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
 
            
            
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    
    
    return true;
}
 

int main()
{
    int V,E;
cout<<"enter number of vertices: ";
cin>>V;
cout<<"enter number of edges: ";
cin>>E;
vector<vector<int> >adjM(V, vector<int>(V, 0));
cout<<"enter edge u to v: "<<endl;
int u,v;
for(int i=0;i<E;i++){
    cout<<"enter u: ";
    cin>>u;
    cout<<"enter v: ";
    cin>>v;
    adjM[u][v]=1;
    adjM[v][u]=1;
}
 
    isBipartite(V,adjM, 0) ? cout << "Yes, it is a Bipartite graph" : cout << "No, not a bipartite graph";
    return 0;
}