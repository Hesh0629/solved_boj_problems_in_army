// dp[n][m] = m번째 구간이 n으로 끝나는 경우의 합
// dp[n][m] = max(dp[i][m-1]+ j~n까지의 합) (i: N∈[1~n-2], j: N∈[i+2:n])
// or dp[n][m] = max(dp[n][m],dp[n-1][m]+현재 값)
#include<bits/stdc++.h>
using namespace std;
int n,m,dp[101][101],prefix[101];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++)dp[i][j]=-987654321;
  }
  prefix[0]=0;
  for(int i=1;i<=n;i++){
    int init;
    cin>>init;
    prefix[i]=prefix[i-1]+init;
    for(int j=1;j<=m;j++){
      if(j==1){
        for(int k=0;k<=i-1;k++)
          dp[i][j]=max(dp[i][j],prefix[i]-prefix[k]);
      }
      else{
        for(int k=1;k<=i-2;k++){
          //만족하는 연속된 구간을 일일이 다 구해야한다. (3중 for loop)
          for(int t=k;t<=i-2;t++)
            dp[i][j]=max(dp[i][j],dp[k][j-1]+prefix[i]-prefix[t+1]);
        }
        dp[i][j]=max(dp[i][j],dp[i-1][j]+init);
      }
    }
  }
  int ans=-987654321;
  for(int i=1;i<=n;i++){
    ans=max(ans,dp[i][m]);
  }
  cout<<ans<<endl;
}
