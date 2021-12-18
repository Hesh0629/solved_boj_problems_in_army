#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,ans=-1;
char dp[101][1001][1001];
vector<pair<int,int>>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(a<b) v.push_back({b,a});
    else v.push_back({a,b});
  }
  sort(v.begin(),v.end(),greater<>());
  for(int i=0;i<v.size();i++){
    if(i==0){
      dp[i][v[i].first][v[i].second]=1;
      dp[i][v[i].second][v[i].first]=1;      
    }
    else{
      for(int j=1;j<=1000;j++){
        for(int k=1;k<=1000;k++){
          dp[i][j][k]=dp[i-1][j][k];
          dp[i][k][j]=dp[i-1][k][j];
          if(j>=v[i].first && k>=v[i].second){
            dp[i][v[i].first][v[i].second]=max((int)dp[i][v[i].first][v[i].second],dp[i-1][j][k]+1);
            dp[i][v[i].second][v[i].first]=max((int)dp[i][v[i].second][v[i].first],dp[i-1][k][j]+1);
          }
        }
      }
    }
    ans=max(ans,(int)dp[i][v[i].first][v[i].second]);
    ans=max(ans,(int)dp[i][v[i].second][v[i].first]);
  }
  cout<<ans<<endl;
}
