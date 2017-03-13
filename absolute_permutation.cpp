#include<bits/stdc++.h>

using namespace std;

bool checkAbsPerm(int n, int k, int *used){

    vector<int> ans;

    for(int pos=1; pos<=n; pos++){

       int minele=min((pos-k), (pos+k));
       int maxele=max((pos-k), (pos+k));

       if((0<minele && minele<=n) && (used[minele]==0)){
        used[minele]=1;
       // cout<<"minele : "<<minele<<"iter: "<<pos<<endl;
        ans.push_back(minele);
        continue;

       }
       else if((0<maxele && maxele<=n) && (used[maxele]==0)){
        used[maxele]=1;
       // cout<<"maxele : "<<maxele<<"iter: "<<pos<<endl;
        ans.push_back(maxele);
        continue;

       }
       else{
        cout<<-1<<endl;
        return false;
       }

    }
 for(int i=0; i<ans.size(); i++){
  cout<<ans[i]<<" ";
 }
 cout<<endl;
 return true;

}



int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
         int used[n+1]={0};
         checkAbsPerm(n,k,used);
    }

    return 0;
}
