#include<bits/stdc++.h>

using namespace std;


void print(vector<int>graph[],int n){
      for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;
      }
}

int main(){
     int e,n,u,v;
     cin>>n>>e;
     vector<int>graph[n];

     for(int i=0;i<e;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
     }
     print(graph,n);
}
