// 여기서 투자가는 한 기업에 돈을 나누어 투자할 수는 없다.
// knapsack 문제를 여전히 해멘다..
#include<bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
ll n,m,invest[21][301],x; // [회사넘버][투자금] = 이익금
ll dp[21][301]; // i까지 조사하였을 때 cost로 벌 수 있는 최대 이익
ll path[21][301]; //i까지 조사하였을 때 cost를 넣었을 시 경로
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(invest,0,sizeof(invest));
  memset(path,0,sizeof(path));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>x;
    for(int j=1;j<=m;j++) cin>>invest[j][x];
  }
  for(int i=1;i<=m;i++){
    for(int cost=0;cost<=n;cost++){
      for(int inv=0;inv<=cost;inv++){
        if(dp[i-1][cost-inv]+invest[i][inv]>dp[i][cost]){
          dp[i][cost]=dp[i-1][cost-inv]+invest[i][inv];
          path[i][cost]=inv; // i번째 기업을 조사하고 있고 현재 cost만큼 썻을 때 현재 기업에 inv만큼 투자했다.
        }
      }
    }
  }
  ll ans=-1;
  int pay=-1;
  for(int i=1;i<=n;i++){
    ans=max(ans,dp[m][i]);
    pay=i;
  }
  cout<<ans<<endl;
  vector<int>input;
  int cur=ans;
  for(int i=m;i>=1;i--){
    input.push_back(path[i][pay]);
    pay-=path[i][pay];
  }
  reverse(input.begin(),input.end());
  for(auto i:input) cout<<i<<" ";
}
