#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k;
pair<int,int>par[100001];
set<int>child[100001];
int vis[100001];
int findLCA(int a,int b){
  if(a==b)return a;
  vector<int>chk;
  for(int i=0;i<1000;i++){
    vis[a]=1;
    chk.push_back(a);
    if(a==0)break;
    a=par[a].first;
  }
  for(int i=0;i<1000;i++){
    if(vis[b])break;
    else {
      chk.push_back(b);
      b=par[b].first;
    }
  }
  for(auto i:chk)
    vis[i]=0;
  return b;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i=1;i<n;i++){
    child[0].insert(i);
    par[i]={0,0};
  }
  for(int asdf=0;asdf<k;asdf++){
    int r,a,b,c;
    cin>>r;
    if(r==1){
      cin>>a>>b>>c;
      if(a==b)continue;
      int lca=findLCA(a,b);
      while(a!=lca){
        par[a].second=c;
        a=par[a].first;
      }
      while(b!=lca){
        par[b].second=c;
        b=par[b].first;
      }
    }
    else if(r==2){
      cin>>a>>b;
      child[par[a].first].erase(a);
      par[a].first=b;
      child[b].insert(a);
    }
    else{
      cin>>a>>b;
      if(a==b){
        cout<<0<<endl;
        continue;
      }
      int lca=findLCA(a,b);
      set<int>color;
      while(a!=lca){
        color.insert(par[a].second);
        a=par[a].first;
      }
      while(b!=lca){
        color.insert(par[b].second);
        b=par[b].first;
      }
      cout<<color.size()<<endl;
    }
  }
}
