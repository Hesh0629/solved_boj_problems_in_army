#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<pair<pair<int,int>,int>>dp[101][10001];
// dp[idx][가장 위 넓이 넓이]={{총 높이,맨 위 무게}{맨 위 벽돌 번호}}
//
vector<pair<pair<int,int>,pair<int,int>>>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int s,h,w;
    cin>>s>>h>>w;
    v.push_back({{s,h},{w,i+1}});
  }
  sort(v.begin(),v.end(),greater<>());
  for(int i=0;i<n;i++){
    if(i==0)
      dp[i][v[i].first.first].push_back({{v[i].first.second,v[i].second.first},v[i].second.second});
    else{
      vector<pair<pair<int,int>,int>>temp;
      for(int j=v[0].first.first;j>v[i].first.first;j--){
        dp[i][j]=dp[i-1][j];
        if(dp[i-1][j].empty())continue;
        else if(dp[i-1][j].back().first.second>=v[i].second.first){
          if(temp.empty())temp=dp[i-1][j];
          else if(temp.back().first.first<dp[i-1][j].back().first.first)temp=dp[i-1][j];
          else if(temp.back().first.first==dp[i-1][j].back().first.first){
            if(temp.back().first.second<dp[i-1][j].back().first.second) temp=dp[i-1][j];
          }
        }
      }
      if(temp.empty()) dp[i][v[i].first.first].push_back({{v[i].first.second,v[i].second.first},v[i].second.second});
      else{
        dp[i][v[i].first.first]=temp;
        dp[i][v[i].first.first].push_back({{temp.back().first.first+v[i].first.second,v[i].second.first},v[i].second.second});
      }
    }
  }
  vector<pair<pair<int,int>,int>>ans;
  for(int i=1;i<=10000;i++){
    if(dp[n-1][i].empty())continue;
    else if(ans.empty())ans=dp[n-1][i];
    else if(ans.back().first.first<dp[n-1][i].back().first.first)
      ans=dp[n-1][i];
  }
  cout<<ans.size()<<endl;
  reverse(ans.begin(),ans.end());
  for(auto i:ans)cout<<i.second<<endl;
}
