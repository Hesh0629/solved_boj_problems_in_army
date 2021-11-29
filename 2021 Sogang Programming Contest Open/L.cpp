#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int n,x,y;
pair<int,int>dp[50][201][201];
vector<pair<int,int>>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<50;i++){
    for(int j=0;j<201;j++){
      for(int k=0;k<201;k++)dp[i][j][k]={INF,INF};
    }
  }
  cin>>n>>x>>y;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
  }
  for(int i=0;i<n;i++){
    int curX=v[i].first, curY=v[i].second;
    if(i==0){
      dp[i][curX][curY]={1,i+1};
      // 기저조건;;
      dp[i][0][0]={0,0};
    }
    else{
      for(int j=0;j<=200;j++){
        for(int k=0;k<=200;k++){
          pair<int,int>asdf;
          if(j-curX>=0 &&k-curY>=0) 
            asdf={dp[i-1][j-curX][k-curY].first+1,i+1};
          else
            asdf=dp[i-1][j][k];
          dp[i][j][k]= min(asdf,dp[i-1][j][k]);
        }
      }
    }
  }
  pair<int,int> ans={INF,INF};
  for(int i=x;i<=200;i++){
    for(int j=y;j<=200;j++)
      ans=min(ans,dp[n-1][i][j]);
  }
  if(ans.first==INF) cout<<-1<<endl;
  else cout<<ans.first<<endl<<ans.second<<endl;
  return 0;
}
