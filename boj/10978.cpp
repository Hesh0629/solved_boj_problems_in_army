// 전체 경우의 수에 대하여 "몇 명이 재배정이 받는가"를 구하고 저장
// 그러면 n에 대하여 n! - (nCn*dp[0]+nCn-1*dp[1] ....+nC1*dp[n-1])
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int n,t,dp[21],factorial[21];
long long int c (long long int n,long long int m){
  return factorial[n]/(factorial[n-m]*factorial[m]);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  factorial[0]=1;
  factorial[1]=1;
  dp[0]=0;
  dp[1]=0;
  dp[2]=1;
  for(int i=2;i<=20;i++)
    factorial[i]=factorial[i-1]*i;
  for(int i=3;i<=20;i++){
    dp[i]=factorial[i]-1;
    for(int j=1;j<i;j++)
      dp[i]-=c(i,j)*dp[i-j];
  }
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n;
    cout<<dp[n]<<endl;
  }
}
