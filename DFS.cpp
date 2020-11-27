#include<bits/stdc++.h>

using namespace std;

vector<int>G[100];
bool V[100];

void dfs(int s){
 V[s]=1;
 for(int i=0;i<G[s].size();i++){
    int next=G[s][i];
    if(!V[next])
        dfs(next);
 }

}

int main(){
    int n,e,u,v;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0);

    for(int i=0;i<n;i++){
       if(V[i])
         cout<<"Node "<< i <<" is visited."<<endl;
       else
         cout<<"Node "<< i <<" is not visited."<<endl;
    }
}
