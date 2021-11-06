#include <bits/stdc++.h>
using namespace std;
long long int lim,input,dp[102],t[102],pre[102];
int mem[102],n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<102;i++) {
    pre[i]=0;
    t[i]=0;
    dp[i]=2147483648; // 최대값 설정이 문제였다.
  }
  cin>>lim;
  cin>>n;
  if(n>0){
    for(int i=0;i<n+1;i++){
      cin>>input;
      if(i==0) pre[i]=input;
      else pre[i]=pre[i-1]+input;    
    }
  }
  for(int i=0;i<n;i++){
    cin>>input;
    t[i]=input;
  }
  t[n]=0;
  for(int i=-1;i<n;i++){
    if(i==-1){
      for(int j=0;j<=n;j++){
        if(pre[j]<=lim) {
          if(t[j]<dp[j]){
            dp[j]=t[j];
            mem[j]=-1;
          }
        }
      }
    }
    else{
      for(int j=i+1;j<=n;j++){
        if(pre[j]-pre[i]<=lim){
          if(dp[i]+t[j]<dp[j]){
            dp[j]=dp[i]+t[j];
            mem[j]=i;
          }
        }
      }
    }
  }
  cout<<dp[n]<<endl;
  if(dp[n]!=0){
    vector<int>v;
    for(int i=n;mem[i]>=0;){
      v.push_back(mem[i]);
      i=mem[i];
    }
    reverse(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(auto i:v) cout<<i+1<<" ";
  }
  else cout<<0<<endl;
}
