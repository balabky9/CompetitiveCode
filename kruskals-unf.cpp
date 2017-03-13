#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int parent[MAX];
int _sz[MAX];

int root(int a){

while(parent[a]!=a){

parent[a]=parent[parent[a]];
a=parent[a];
}
return a;
}

void doUnion(int a, int b){

int rootA=root(a);
int rootB=root(b);
if(_sz[rootA]>_sz[rootB]){
parent[rootB]=rootA;
_sz[rootA]+=_sz[rootB];}
else{
parent[rootA]=rootB;
_sz[rootB]+=_sz[rootA];
}
}

bool ufind(int a, int b){
return root(a)==root(b);
}

