// 실행 날짜기준으로 제일 큰 점수만 남기고 나머진 앞 날짜로 넘긴다
// 이제 각 날짜별로 가장 큰것만 정답값에 더해주면 끝
#include<bits/stdc++.h>
using namespace std;
int n;
multiset<int,greater<int>>v[1001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int d,w;
    cin>>d>>w;
    v[d].insert(w);
  }
  for(int d=1000;d>=1;d--){
    if(v[d].empty())continue;
    for(auto it=v[d].begin();it!=v[d].end();it++){
      if(it==v[d].begin())continue;
      v[d-1].insert(*it);
    }
  }
  int ans=0;
  for(int i=1;i<=1000;i++){
    if(v[i].empty())continue;
    ans+=*(v[i].begin());
  }
  cout<<ans<<endl;
}
