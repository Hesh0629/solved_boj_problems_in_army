#include <bits/stdc++.h>
#define INF 987654321
#define endl '\n'
using namespace std;
int n,m,ret,a,b;
multiset<pair<int,int>>bus,q; // 인원, 시간 순서임
multiset<pair<int,int>>ans;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  ret=0;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    q.insert({a,b});
  }
  for(int i=0;i<m;i++){
    cin>>a>>b;
    bus.insert({a,b}); // 인원 시간
  }
  int idx=0;
  // ans[idx]에는 한 버스에 대하여 정원만 따졌을 때 들어갈 수 있는 요청들을 넣는다.
   // 모든 요청들에 대하여 들어갈 수 있는 버스 배차를 검사
  auto cur=bus.begin(),i=q.begin(),pre=cur;
  while(cur!=bus.end()){
    if(cur->first>=i->first&&i!=q.end()){
      ans.insert({i->second,i->first});
      i++;
    }
    else{
      auto iter=ans.lower_bound({cur->second,-INF});
      if(iter!=ans.end()){
        ret++;
        ans.erase(iter);
      }
      cur++;
    }
  }
  // 현재 배차그룹에는 정원에 대해서만 만족하는 요청들만 들어있으므로 시간에 대하여 큰것부터 들어갈 수 있는 것부터 처리해주면 OK
  cout<<ret<<endl;
}
