// 이게 수학문제지 DP문제인가
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[2001][10001],n,m,ans=0;
vector<pair<int,int>>stuff;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>n>>m;
  for(int asdf=0;asdf<n;asdf++){
    int v,c,k;
    cin>>v>>c>>k;
    // 2진법마냥 조합하면 K가 나오도록 쪼갠다.
    // k개의 물건이 아닌 value*idx의 가치,무게를 가진 하나의 물건으로 취급
    for(int newK=k;newK>0;newK>>=1){
      int idx=newK-(newK>>1);
      stuff.push_back({v*idx,c*idx});
    }
  }
  for(int i=1;i<=stuff.size();i++){
    int curW=stuff[i-1].first;
    int curHappy=stuff[i-1].second;
    for(int w=0;w<=m;w++){
      if(w-curW>=0)
        dp[i][w]=max(dp[i-1][w],dp[i-1][w-curW]+curHappy);
      else
        dp[i][w]=dp[i-1][w];
      if(w<=m)
        ans=max(ans,dp[i][w]);
    }
  }
  cout<<ans<<endl;
}
