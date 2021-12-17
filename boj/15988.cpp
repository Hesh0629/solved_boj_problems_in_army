#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[1000001],t,init;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  dp[0]=1;
  for(int i=1;i<=1000000;i++){
    if(i-3>=0){
      dp[i]+=dp[i-3];
      dp[i]%=1000000009;
    }
    if(i-2>=0){
      dp[i]+=dp[i-2];
      dp[i]%=1000000009;
    }
    if(i-1>=0){
      dp[i]+=dp[i-1];
      dp[i]%=1000000009;
    }
  }
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>init;
    cout<<dp[init]%1000000009<<endl;
  }
}
