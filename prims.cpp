#include<bits/stdc++.h>
#define max 50
using namespace std;

class edge{
   public:
       int dest,weight;
};
vector<edge>V[max];

int costs[max];
int visited[max];
int parent[max];

typedef pair<int, int> iPair;

void prims(int a,int v){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    for(int i=0;i<v;i++){
        costs[i]=INT_MAX;
        visited[i]=0;
        parent[i]=-1;
    }
    pq.push(make_pair(0,a));
    int ans=0;
    while(!pq.empty()){
        int current = pq.top().second;
        int c_weight = pq.top().first;
        pq.pop();
        visited[current]=1;
        ans+=c_weight;

        for(int i=0;i<V[current].size();i++){
                int ver = V[current][i].dest;
                int weit = V[current][i].weight;
             if(!visited[ver] && weit < costs[ver]){
                  costs[ver]=weit;
                  pq.push(make_pair(costs[ver],ver));
                  parent[ver]=current;
             }
        }
    }
    cout<<"Total MST weight : "<<ans<<endl;;
}

int main(){
    edge ed;
    int s,n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
    cin>>s>>ed.dest>>ed.weight;
    V[s].push_back(ed);
    int s2=ed.dest;
    ed.dest=s;
    V[s2].push_back(ed);
    }
   prims(0,n);
   for(int i=0;i<n;i++)
    if(parent[i]>=0)
      cout<<parent[i]<<" - "<<i<<endl;
}
