#include<bits/stdc++.h>
#define mx 50
using namespace std;

class Edge{
    public:
int dest,weight;
};
vector<Edge>V[mx];
vector<int>parent(mx,-1);
vector<int>visited(mx,0);
vector<int>cost(mx,INT_MAX);

typedef pair<int ,int>iPair;

void Dijkstra(int a,int v){
    priority_queue<iPair,vector<iPair>,greater<iPair> >pq;

    pq.push(make_pair(0,a));

    while(!pq.empty()){
        int current = pq.top().second;
        pq.pop();
        visited[current]=1;

        for(int i=0;i<V[current].size();i++){
            int ver=V[current][i].dest;
            int weit=V[current][i].weight;
            if(!visited[ver] && weit+cost[current]<cost[ver]){
                cost[ver]= weit+cost[current];
                pq.push(make_pair(cost[ver],ver));
                parent[ver]=current;
            }
        }
    }
}

int main(){
    Edge ed;
int n,e;
cin>>n>>e;
while(e--){
    int s;
    cin>>s>>ed.dest>>ed.weight;
    V[s].push_back(ed);
    /*int sourcs=ed.dest;
    ed.dest=s;
    V[sourcs].push_back(ed);*/
  }
  Dijkstra(0,n);
  cout<<"The MST is :
  for(int i=0;i<n;i++)
    if(parent[i]>=0)
      cout<<parent[i]<<" - "<<i<<endl;
}
