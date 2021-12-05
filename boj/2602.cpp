#include<bits/stdc++.h>
using namespace std;
string input,angel,devil;
long long int dp[101][21][2]; // dp[다리길이][문자열][angel:0, devil:1]
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>input>>angel>>devil;
  for(int i=0;i<angel.size();i++){
    for(int j=0;j<input.size();j++){
      if(angel[i]==input[j]){
        if(j==0)dp[i][j][0]=1;
        else {
          for(int k=0;k<i;k++)
            dp[i][j][0]+=dp[k][j-1][1];
        }
      }
      if(devil[i]==input[j]){
        if(j==0)dp[i][j][1]=1;
        else{
          for(int k=0;k<i;k++)
            dp[i][j][1]+=dp[k][j-1][0];
        }
      }
    }
  }
  long long int ans=0;
  for(int i=0;i<angel.size();i++){
    ans+=dp[i][input.size()-1][0];
    ans+=dp[i][input.size()-1][1];
  }
  cout<<ans<<endl;
}
