#include<bits/stdc++.h>

using namespace std;

class Edge{
    public:
   int sourcs,dest,weight;
};

bool comp(Edge a1,Edge a2){
   return a1.weight<a2.weight;
}

int findparent(int v,int parent[]){
    if(parent[v]==v)
        return v;
    else
        return findparent(parent[v],parent);
}

void kruskals(Edge input[],int n,int e){
    sort(input,input+e,comp);

    Edge output[n-1];
    int parent[n];
    for(int j=0;j<n;j++)
        parent[j]=j;

    int count=0,i=0;
    while(count!=(n-1)){
        Edge currentEdge = input[i];
        int sourceparent = findparent(currentEdge.sourcs,parent);
        int destparent = findparent(currentEdge.dest,parent);

        if(sourceparent != destparent){
            output[count]=currentEdge;
            count++;
            parent[sourceparent]=destparent;
        }
        i++;
    }
    cout<<endl<<"The MST is : "<<endl;
    for(int i=0;i<n-1;i++){
        if(output[i].sourcs<output[i].dest)
            cout<<output[i].sourcs<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        else
            cout<<output[i].dest<<" "<<output[i].sourcs<<" "<<output[i].weight<<endl;
    }
}

int main(){
   int n,e;
   cin>>n>>e;
   Edge input[e];
   for(int i=0;i<e;i++){
    int s,d,w;
    cin>>s>>d>>w;
    input[i].sourcs=s;
    input[i].dest=d;
    input[i].weight=w;
   }
   kruskals(input,n,e);
}
