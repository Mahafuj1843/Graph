#include<bits/stdc++.h>
#define mx 50
using namespace std;

int n,e;
class Edge{
    public:
int sourcs, dest,weight;
};
vector<Edge>V;

void Bellmen_Ford(int src){
    int dist[n];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
         int u = V[j].sourcs;
         int v = V[j].dest;
         int w = V[j].weight;
         if(dist[u]!=INT_MAX && (dist[u]+w)<dist[v]){
            dist[v]=dist[u]+w;
         }
        }
    }
        for(int j=0;j<e;j++){
         int u = V[j].sourcs;
         int v = V[j].dest;
         int w = V[j].weight;
         if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            cout<<"Graph contains negative weight cycle.";
         }
        }
        for(int i=0;i<n;i++)
      cout<<i<<" - "<<dist[i]<<endl;
 }

int main(){
    Edge ed;
cin>>n>>e;
for(int i=0;i<e;i++){
    cin>>ed.sourcs>>ed.dest>>ed.weight;
    V.push_back(ed);
  }
  cout<<"Vertex   Distance from Source :"<<endl;
  Bellmen_Ford(0);
}
