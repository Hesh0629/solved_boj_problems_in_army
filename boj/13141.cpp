#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long double ans=987654321;
int n,m,vis[201];
vector<pair<int,long double>>adj[201];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  for(int i=1;i<=n;i++){
    for(int k=0;k<201;k++)vis[k]=987654321;
    long double cur_ans=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,i});
    vis[i]=0;
    while(!pq.empty()){
      int cur=pq.top().second, dist=pq.top().first;
      pq.pop();
      for(auto k:adj[cur]){
        if(vis[k.first]>dist+k.second){
          vis[k.first]=dist+k.second;
          pq.push({dist+k.second,k.first});
        }
      }
    }
    //O(nm)시간복잡도가 먹힌다.
    for(int j=1;j<=n;j++){
      for(auto k:adj[j]){
        long double temp;
        if(vis[j]>vis[k.first]){
          if(vis[j]-vis[k.first]>=k.second) temp=vis[k.first]+k.second;
          else temp=(long double)((k.second-(vis[j]-vis[k.first]))/2+vis[j]);
        }
        else{
          if(vis[k.first]-vis[j]>=k.second) temp=vis[j]+k.second;
          else temp=(long double)((k.second-(vis[k.first]-vis[j]))/2+vis[k.first]);
        }
        cur_ans=max(cur_ans,temp);
      }
    }
    ans=min(ans,cur_ans);
  }
  cout.precision(1);
  cout<<fixed;
  cout<<ans<<endl;
}
