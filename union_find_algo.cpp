#include<bits/stdc++.h>
using namespace std;

int *parent;
int *_sz;


struct edge{
int e1;
int e2;
};
edge *Edg;
void initG(int NODES){

Edg=new edge[10];

}

void init(int N){

parent=(int *)malloc(N*sizeof(int));
_sz=(int *)malloc(N*sizeof(int));

for(int i=0; i<N; i++){
 parent[i]=i;
 _sz[i]=1;
}
}

int root(int a){

while(parent[a]!=a){

parent[a]=parent[parent[a]];
a=parent[a];
}
return a;

}

void dounion(int a, int b){

int rootA=root(a);

int rootB=root(b);

if(_sz[rootA]>_sz[rootB]){
 parent[rootB]=rootA;
 _sz[rootA]+=_sz[rootB];
}
else{
parent[rootA]=rootB;
 _sz[rootB]+=_sz[rootA];
}
}

bool ufind(int a, int b)
{

return root(a)==root(b);

}

bool detectCycles(int NODES, int E){

init(NODES);//unf init
for(int i=0; i<E; i++){


     if(ufind(Edg[i].e1, Edg[i].e2)) return true;

     dounion(Edg[i].e1, Edg[i].e2);

  }

return false;
}
int main(){
initG(2);
Edg[0].e1=0; Edg[0].e2=1;
Edg[1].e1=0; Edg[1].e2=2;
Edg[1].e1=1; Edg[1].e2=2;
cout<<detectCycles(3,3)<<endl;
//for(int i=0; i<3; i++) cout<<parent[i]<<" "<<endl;
return 0;

}
