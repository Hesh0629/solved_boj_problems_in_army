#include<bits/stdc++.h>
using namespace std;
int n,dp[2][1000001]; //dp[a로 만들기:0, b로 만들기:1][idx]=최소횟수
string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
      if(i==0){
        dp[0][i]=0;
        dp[1][i]=1;
      }
      else{
        //현재블록이 A일때 A로 싹다 바꾸기
        dp[0][i]=min(dp[0][i-1],dp[1][i-1]+1);
        //현재블록이 A일때 B로 싹다 바꾸기
        dp[1][i]=min(dp[1][i-1]+1,dp[0][i-1]+1);
      }
    }
    else{
      if(i==0){
        dp[0][i]=1;
        dp[1][i]=0;
      }
      else{
        //현재블록이 B일때 A로 싹다 바꾸기
        dp[0][i]=min(dp[0][i-1]+1,dp[1][i-1]+1);
        //현재블록이 B일때 B로 싹다 바꾸기
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+1);
      }
    }
  }
  cout<<(dp[0][n-1])<<endl;
}
