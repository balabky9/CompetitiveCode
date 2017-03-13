#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<int> adj[MAX];
int visited[MAX];
int level[MAX];
long int countr;

int bfs(int source, int x){ //returns count on x level
long int ctr=0;
queue<int> Q;
Q.push(source);
visited[source]=1;
level[source]=1;

while(!Q.empty()){

int p=Q.front();
Q.pop();

for(int i=0; i<adj[p].size(); i++){

 if(visited[adj[p][i]]!=1){
    visited[adj[p][i]]=1;
    Q.push(adj[p][i]);
    level[adj[p][i]]=level[p]+1;
    if(level[adj[p][i]]==x) ctr++;
    if(level[adj[p][i]]>x ) return ctr;
}}

}
return ctr;
}

int main(){

int N,X;
cin>>N;
for(int i=0; i<N-1; i++){
int a,b;
cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}
cin>>X;
cout<<bfs(1,X)<<endl;
return 0;
}








