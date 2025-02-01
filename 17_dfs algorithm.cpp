#include<bits/stdc++.h>
using namespace std;
class graph{
public:
vector<int>G[100];
void addEdge(int u, int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
int vis[100]={0};

void dfs(int source){

   cout<<source<<" ";
         vis[source]=1;
   for(int child:G[source]){
   if (vis[child]==0)
    dfs(child);

   }
}


};
int main (){
   cout<< "Enter the num of Edge "<<endl;
   int e;
   cin>>e;
   graph G;
   for(int i=0;i<e;i++){
       int u,v;
   cin>>u>>v;
        G.addEdge(u,v);
   }
   G.dfs(1);

}

