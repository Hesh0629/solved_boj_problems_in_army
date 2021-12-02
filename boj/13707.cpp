#include<bits/stdc++.h>
#define div 1000000000
using namespace std;
long long int dp[5001][5001]; // dp[숫자개수][숫자]
// prefix sum으로 이전 숫자개수에서 해당 숫자까지 만드는데 걸리는 개수 저장
long long int pre[5001],cur[5001];
int n,k;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(pre,0,sizeof(pre));
  memset(cur,0,sizeof(cur));
  cin>>n>>k;
  for(int i=1;i<=5000;i++){
    for(int j=0;j<=5000;j++){
      if(i==1){
        dp[i][j]=1;
        cur[j]=(cur[j-1]+1)%div;
      }
      else{
        if(j==0) {
          dp[i][j]=1;
          cur[j]=1;
        }
        else{
          dp[i][j]=(pre[j])%div;
          cur[j]=(cur[j-1]+dp[i][j])%div;
        }
      }
    }
    memcpy(pre,cur,sizeof(pre));
  }
  cout<<dp[k][n]%div<<endl;
}
