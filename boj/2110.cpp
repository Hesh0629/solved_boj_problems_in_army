// 이분탐색으로 가장 근접한 공유기 거리의 최대값을 찾아간다.
// 이분탐색이라고 무지성으로 lower_bound만 쓰지말자
#include<bits/stdc++.h>
using namespace std;
int n,c;
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>c;
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    v.push_back(init);
  }
  sort(v.begin(),v.end());
  int ans=0;
  int l=1,r=v[n-1]-v[0];
  while(l<=r){
    int cnt=1,cur=0,dist=(l+r)/2;
    while(1){
      auto it=lower_bound(v.begin()+cur,v.end(),v[cur]+dist);
      if(it==v.end()||cnt==c)break;
      cur=it-v.begin();
      cnt++;
    }
    if(l==r){
      if(cnt==c) ans=max(ans,dist);
      break;
    }
    else if(cnt==c){
      ans=max(ans,dist);
      l=dist+1;
    }
    else r=dist-1;
  }
  cout<<ans<<endl;
}
