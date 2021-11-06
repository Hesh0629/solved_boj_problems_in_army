// dp 배열로 dp[idx][마지막 숫자][합]이 총 몇번째 수열까지 들고 있는지 저장
// 그 이후에 다시 처음부터 돌리면서 k번째 수열을 찾는다.
#include <bits/stdc++.h>
using namespace std;
int n,m,k,cur,dp[11][221][221]; // idx / last / sum
int rec(int last, int sum,int idx){
  if(n<idx || m < sum) return 0;
  if(dp[idx][last][sum] != -1) return dp[idx][last][sum];
  dp[idx][last][sum]=0;
  for(int i=last;i<=m;i++){
    if(i+sum>m) break;
    dp[idx][last][sum]+=rec(i,sum+i,idx+1);
  }
  return dp[idx][last][sum];
}
void track(int last, int sum,int idx){
  if(idx<n){
    for(int i=last;i<=m;i++) {
      if(dp[idx+1][i][sum+i]==-1) continue;
      if(dp[idx+1][i][sum+i]<cur){
        cur-=dp[idx+1][i][sum+i];
        continue;
      }
      cout<<i<<" ";
      track(i,sum+i,idx+1);
      return;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m>>k;
  cur=k;
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=m;i++) dp[n][i][m]=1;
  rec(1,0,0);
  track(1,0,0);
}
