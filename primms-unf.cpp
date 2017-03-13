#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef pair<long long, int> NC;
vector<NC> G[MAX];
bool visited[MAX];
//priority_queue<npwt> PQ;


int doPrims(int x){

for(int i=0; i<MAX; i++) visited[i]=false;

priority_queue<NC, vector<NC>, greater<NC> > Q;
Q.push(make_pair(0,x));
NC p1;
int node=0; long long int cost=0,minCost=0;
while(!Q.empty()){

p1=Q.top();
Q.pop();
node=p1.second;
cost=p1.first;

if(visited[node]) continue;
else{

 minCost+=cost;
 visited[node]=true;
 for(int i=0; i<G[node].size(); i++){

  if(!visited[G[node][i].second]) Q.push(G[node][i]);

 }
}
}
return minCost;
}

int main(){
int M=0,N=0,b=0,a=0,w=0;
cin>>N>>M;
for(int i=1; i<=M; i++){
  cin>>a>>b>>w;
  G[a].push_back(make_pair(w,b));
  G[b].push_back(make_pair(w,a));
}
cout<<doPrims(1)<<endl;
return 0;
}


