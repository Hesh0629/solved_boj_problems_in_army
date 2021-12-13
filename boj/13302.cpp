// 받은 쿠폰의 개수가 같다면 가격이 낮을수록 좋다.
// 너무 어렵게 생각했던 문제
#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int dp[101][41]; // dp[날짜][들고있는 쿠폰 개수]=누적 가격
int n,m,ans=INF;
deque<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<101;i++){
    for(int j=0;j<41;j++)dp[i][j]=INF;
  }
  dp[0][0]=0;
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int init;
    cin>>init;
    v.push_back(init);
  }
  for(int day=1;day<=n;day++){
    if(day<3){
      dp[day][0]=dp[day-1][0]+10000;
      if(v.front()==day)dp[day][0]=min(dp[day][0],dp[day-1][0]);
    }
    else{
      for(int c=0;c<=40;c++){
        if(c==0)dp[day][c]=dp[day-1][c]+10000;
        else{
          dp[day][c]=min(dp[day-1][c]+10000,dp[day-3][c-1]+25000);
          if(day>=5 &&c>=2)dp[day][c]=min(dp[day][c],dp[day-5][c-2]+37000);
          if(c>=3)dp[day][c-3]=min(dp[day][c-3],dp[day-1][c]);
        }
        if(v.front()==day)dp[day][c]=min(dp[day][c],dp[day-1][c]);
      }
    }
    if(v.front()==day)v.pop_front();
  }
  for(int i=0;i<=40;i++)ans=min(ans,dp[n][i]);
  cout<<ans<<endl;
}
