#include<bits/stdc++.h>

using namespace std;

vector<int>G[100];
int D[100];
bool V[100];

void bfs(int s){
  queue<int>Q;
  V[s]=1;
  D[s]=0;
  Q.push(s);
  while(!Q.empty()){
    int node = Q.front();
    Q.pop();
    for(int i=0;i<G[node].size();i++){
        int next=G[node][i] ;
        if(V[next]==0){
            V[next]=1;
            D[next]=D[node]+1;
            Q.push(next);
        }
    }
  }
}

int main(){
  int n,e,u,v,s;
  cin>>n>>e;

  for(int i=0;i<e;i++){
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cout<<"Enter starting node : ";
  cin>>s;
  bfs(s);
  cout<<"From node "<<s<<endl;
  for(int i=1;i<=n;i++)
    cout<<"Distance of "<<i<<"is : "<<D[i]<<endl;
}
