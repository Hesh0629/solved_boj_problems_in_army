#include<bits/stdc++.h>
using namespace std;
int t,k;
long long int dp[101][10001];
vector<pair<int,int>>coin;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>t;
  cin>>k;
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    coin.push_back({a,b});
  }
  sort(coin.begin(),coin.end(),greater<>());
  for(int i=0;i<coin.size();i++){
    int cur=coin[i].first;
    if(i==0){
      for(int j=1;j<=coin[i].second;j++)dp[i][cur*j]=1;
      dp[i][0]=1;
    }
    else{
      for(int price=0;price<=10000;price++){
        dp[i][price]=dp[i-1][price];
        for(int j=1;j<=coin[i].second&&price-cur*j>=0;j++)
          dp[i][price]+=dp[i-1][price-cur*j];
      }
    }
  }
  cout<<dp[k-1][t]<<endl;
}
