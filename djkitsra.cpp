#include<bits/stdc++.h>
#define MAX 100005
#define IMAX 1000000000
using namespace std;

typedef pair<long long, int> WN;
vector<WN> adj[MAX];
bool visited[MAX];
long long dist[MAX];

void Djikitsra(int start){


memset(visited, false, sizeof(visited));
for(int i=0; i<MAX; i++) dist[i]=IMAX;
WN node,node2;
priority_queue<WN, vector<WN>, greater<WN> > PQ;
PQ.push(make_pair(0,start));
dist[start]=0;
while(!PQ.empty()){

node=PQ.top();
PQ.pop();
int x=node.second; int w=node.first;
if(visited[x]) continue;
else{

visited[x]=true;
for(int i=0; i<adj[x].size(); i++){

 node2=adj[x][i];



   if(dist[node2.second]>(dist[x]+node2.first)){
    dist[node2.second]=dist[x]+node2.first;
   // cout<<"DIST:- "<<dist[node2.second]<<" ";
    PQ.push(make_pair(dist[node2.second],node2.second)); //update distances;
   }

 }


}

}

}


int main(){
int N=0,M=0;
cin>>N>>M;
int a=0,b=0,w=0;
for(int k=0; k<M; k++){
cin>>a>>b>>w;
adj[a].push_back(make_pair(w,b));
//adj[b].push_back(make_pair(w,a));

}
Djikitsra(1);
for(int k=2; k<=N; k++){
 cout<<dist[k]<<" ";
}
return 0;

}
