#include<bits/stdc++.h>
using namespace std;
int n,dp[61][61][61],a,b,c,cur1,cur2,cur3,ans=INT_MAX;
int d1[6]={9,9,3,3,1,1},d2[6]={3,1,9,1,9,3},d3[6]={1,3,1,9,3,9};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  if(n==3) cin>>a>>b>>c;
  else if(n==2){
    cin>>a>>b;
    c=0;
  }
  else{
    cin>>a;
    b=0;
    c=0;
  }
  for(int i=0;i<61;i++){
    for(int j=0;j<61;j++){
      for(int k=0;k<61;k++)
        dp[i][j][k]=987654321;
    } 
  }
  dp[a][b][c]=0;
  for(int t=1;t<=60;t++){
    for(int i=0;i<=a;i++){
      for(int j=0;j<=b;j++){
        for(int k=0;k<=c;k++){
          for(int idx=0;idx<6;idx++){
            if(i-d1[idx]<=0)cur1=0;
            else cur1=i-d1[idx];
            if(j-d2[idx]<=0)cur2=0;
            else cur2=j-d2[idx];
            if(k-d3[idx]<=0)cur3=0;
            else cur3=k-d3[idx];
            dp[cur1][cur2][cur3]=min(dp[cur1][cur2][cur3],dp[i][j][k]+1);
          }            
        }
      }
    }
    ans=min(ans,dp[0][0][0]);
  }
  cout<<ans<<endl;
}
