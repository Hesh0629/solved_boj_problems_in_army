//왜 해멧는지 모르는 문제
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,a,b;
int dp[101][1000001];
vector<pair<int,int>>v;
vector<pair<int,int>>bag;
pair<long double,int>ans={-1,987654321};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    v.push_back({a,b});
  }
  for(int i=1;i<=m;i++){
    cin>>a;
    bag.push_back({a,i});
  }
  for(int j=0;j<n;j++){
    int weight=v[j].first,value=v[j].second;
    for(int w=0;w<=1000000;w++){
      if(w-weight>=0){
        if(j==0) dp[j][w]=value;
        else dp[j][w]=max(dp[j-1][w-weight]+value, dp[j-1][w]);
      }
      else{
        if(j==0) dp[j][w]=0;
        else dp[j][w]=dp[j-1][w];
      }
    }
  }
  for(auto i:bag){
    long double rate=dp[n-1][i.first]/(long double)i.first;
    if(ans.first<=rate){
      if(ans.first==rate && i.second<ans.second) ans={rate,i.second};
      else if(ans.first==rate &&i.second>ans.second) ans={rate,ans.second};
      else ans={rate,i.second};
      
    }
  }
  cout<<ans.second<<endl;
}
