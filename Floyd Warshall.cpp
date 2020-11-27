#include<bits/stdc++.h>

using namespace std;
int n,e,A[50][50];
void floyd_warshall(){

     for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
            {
                if (A[i][k]+A[k][j]<A[i][j])
                    A[i][j]=A[i][k]+A[k][j];
            }
          }
       }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (A[i][j]>=1111)
                cout<<"INF"<<" ";
            else
                cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
   cin>>n>>e;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j)
            A[i][j]=0;
        else
            A[i][j]=1111;
        }
      }
      for(int i=0;i<e;i++){
          int s,d,w;
          cin>>s>>d>>w;
          A[s][d]=w;
      }
      /*for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
           cout<<A[i][j]<<" ";
        }
        cout<<endl;
      }
      cout<<endl;*/
      floyd_warshall();
}
