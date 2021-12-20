// 그리디와 DP
// 1. 이전 그림 높이가 현재 그림이 들어와도 살아있다면 그냥 넣는다.
// 2. 만약 아니라면 현재 그림이 들어왔을 때 살 수 있는 그림을 찾아서(이분탐색) 그 앞으로 넣거나 
//    OR 안넣는게 더 값이 크다면 안넣는다.
#include<bits/stdc++.h>
using namespace std;
int n,s,pre,cur;
int maxCost[20000001],ans=0; // maxCost[높이가 h일 때] = {그림의 최대 가격}
int height[20000001];        // dp[i번째 인덱스까지 검사시 최대값에 대하여] = { 맨 앞에 있는 그림의 높이 }
int dp[20000001];            // dp[i번째 인덱스까지 검사시] = { 최대값 }
vector<pair<int,int>>v,v2;   //v는 내림차순, v2는 오름차순
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(maxCost,0,sizeof(maxCost));
  cin>>n>>s;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
    v2.push_back({a,b});
    maxCost[a]=max(maxCost[a],b);
  }
  sort(v.begin(),v.end(),greater<>());
  sort(v2.begin(),v2.end());
  for(int i=0;i<n;i++){
    if(i==0){
      height[i]=v[i].first;
      dp[i]=maxCost[v[i].first];
    }
    else{
      if(height[i-1]>=v[i].first+s){
        dp[i]=dp[i-1]+maxCost[v[i].first];
        height[i]=v[i].first;
      }
      else{
        auto it =lower_bound(v2.begin(),v2.end(),make_pair(v[i].first+s,-1)); // 현재 그림 높이 + s를 만족하는 이전 그림중 제일 작은 높이 찾기
        int idx=(v2.size()-1)-(it-v2.begin()); // 내림차순 일 때 (v의 인덱스)로 변경)
        if(it==v2.end()){
          if(dp[i-1]>=v[i].second){
            dp[i]=dp[i-1];
            height[i]=height[i-1];
          }
          else{
            dp[i]=v[i].second;
            height[i]=v[i].first;
          }
          continue;
        }
        if(dp[idx]+v[i].second>dp[i-1]){
          dp[i]=dp[idx]+maxCost[v[i].first];
          height[i]=v[i].first;
        }
        else{
          dp[i]=dp[i-1];
          height[i]=height[i-1];
        }
      }
    }
    ans=max(ans,dp[i]);
  }
  cout<<ans<<endl;
}
