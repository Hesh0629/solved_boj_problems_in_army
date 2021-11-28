#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,s,e,c;
vector<pair<pair<int,int>,int>>v,ans;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s>>e>>c;
    v.push_back({{s,e},c});
  }
  sort(v.begin(),v.end());
  int curx=-1,cury=-1,curCost=-1;
  for(auto i:v){
    int x=i.first.first,y=i.first.second,cost=i.second;
    if(cury<x){
      if(cury!=-1)
        ans.push_back({{curx,cury},curCost});
      curx=x;
      cury=y;
      curCost=cost;
    }
    else{
      cury=max(cury,y);
      curCost=min(cost,curCost);
    }
  }
  ans.push_back({{curx,cury},curCost});
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  for(auto i:ans) cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
}
