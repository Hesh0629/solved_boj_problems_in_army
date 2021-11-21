#include <bits/stdc++.h>
using namespace std;
int n,dist,ans=0;
deque<pair<int,int>>v;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
bool cmp(pair<int,int>a,pair<int,int>b){
  if(a.second==b.second) return a.first<b.first;
  else return a.second<b.second;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(a>b) v.push_back({b,a});
    else v.push_back({a,b});
  }
  sort(v.begin(),v.end(),cmp);
  //for(auto i:v) cout<<i.first<<" "<<i.second<<endl;
  cin>>dist;
  while(!v.empty()){
    int curx=v.front().first,cury=v.front().second;
    v.pop_front();
    if(cury-curx>dist) continue;
    if(pq.empty()) pq.push({curx,cury});
    else{
      if(cury<=pq.top().second) pq.push({curx,cury});
      else{
        while(!pq.empty()&&cury-pq.top().first>dist)pq.pop();
        pq.push({curx,cury});
      }
    }
    ans=max((int)pq.size(),ans);
  }
  cout<<ans<<endl;
}
