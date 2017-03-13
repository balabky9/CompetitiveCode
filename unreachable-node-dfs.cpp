#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> adj[MAX];
int visited[MAX];
//int level[MAX];
long int countr;

int dfs(int source){ //returns count on x level
long int ctr=1;
stack<int> S ;
S.push(source);
visited[source]=1;


while(!S.empty()){

int p=S.top();
S.pop();

for(int i=0; i<adj[p].size(); i++){

 if(visited[adj[p][i]]!=1){
    visited[adj[p][i]]=1;
    S.push(adj[p][i]);
    ctr++;
}}

}
return ctr;
}

int main(){

int N,M,X;
cin>>N>>M;
for(int i=0; i<M; i++){
int a,b;
cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}
cin>>X;
cout<<(N-dfs(X))<<endl;
return 0;
}









