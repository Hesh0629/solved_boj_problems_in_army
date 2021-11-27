#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,eratosthenes[1121],dp[1121][1121][15];
vector<int>prime;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(eratosthenes,0,sizeof(eratosthenes));
  memset(dp,0,sizeof(dp));
  for(int i=0;i<1121;i++)eratosthenes[i]=1;
  eratosthenes[0]=0;
  eratosthenes[1]=0;
  for(int i=2;i<=1120;i++){
    if(eratosthenes[i]==0)continue;
    for(int j=i*2;j<=1120;j+=i)
      eratosthenes[j]=0;
  }
  for(int i=2;i<=1120;i++){
    if(eratosthenes[i]) {
      prime.push_back(i);
    }
  }
  for(int idx=0;idx<prime.size();idx++){
    for(int k=1;k<=14;k++){
      if(idx!=0){
        //왜 이전 상황을 안땡겨 왔을까,,,
        for(int i=0;i<=1120;i++)
        dp[idx][i][k]=dp[idx-1][i][k];
      }
      if(k==1) {
        dp[idx][prime[idx]][k]=1;
      }
      else{
        if(idx==0) continue;
        for(int i=0;i+prime[idx]<=1120;i++){
          dp[idx][i+prime[idx]][k]+=dp[idx-1][i][k-1];
        }
      }
    }
  }
  cin>>t;
  for(int i=0;i<t;i++){
    long long int n,k;
    cin>>n>>k;
    cout<<dp[prime.size()-1][n][k]<<endl;
  }
}
