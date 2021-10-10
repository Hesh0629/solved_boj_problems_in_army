#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int x;
pair<int,int>dp[1000001]; //횟수, 현재 번호로 올 때 이용한 방법
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<1000001;i++) dp[i]={987654321,0};
  cin>>x;
  queue<int>q;
  q.push(x);
  dp[x]={0,0};
  while(!q.empty()){
    int cur=q.front();
    int time=dp[cur].first;
    q.pop();
    if(cur<=1) continue;
    if(cur%3==0 && dp[cur/3].first>time+1) {
      dp[cur/3]={time+1,1};
      q.push(cur/3);
    }
    if(cur%2==0 && dp[cur/2].first>time+1) {
      dp[cur/2]={time+1,2};
      q.push(cur/2);
    }
    if(cur>1&&dp[cur-1].first>time+1) {
      dp[cur-1]={time+1,3};
      q.push(cur-1);
    }
  }
  cout<<dp[1].first<<endl;
  vector<int>ans;
  for(int cur=1;cur<=x;){
    ans.push_back(cur);
    if(cur==x) break;
    if(dp[cur].second==1) cur*=3;
    else if (dp[cur].second==2) cur*=2;
    else cur+=1;
  }
  reverse(ans.begin(),ans.end());
  for(auto i:ans) cout<<i<<" ";
}
