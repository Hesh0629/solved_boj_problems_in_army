#include<bits/stdc++.h>
using namespace std;
string s;
long long int dp[5001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(i==0){
      if(s[i]=='0'){
        cout<<0<<endl;
        return 0;
      }
      else dp[i]=1;
    }
    else if(i==1){
      if((s[i-1]=='1'&&s[i]>='0'&&s[i]<='9')||(s[i-1]=='2'&&s[i]>='0'&&s[i]<='6'))
        dp[i]+=1;
      if(s[i]>'0') dp[i]+=1;
      if(dp[i]==0){
        cout<<0<<endl;
        return 0;
      }
    }
    else{
      if(s[i]>'0') dp[i]+=dp[i-1];
      if((s[i-1]=='1'&&s[i]>='0'&&s[i]<='9')||(s[i-1]=='2'&&s[i]>='0'&&s[i]<='6'))
      dp[i]+=dp[i-2];
      if(dp[i]==0){
        cout<<0<<endl;
        return 0;
      }
    }
    dp[i]%=1000000;
  }
  cout<<dp[s.size()-1]<<endl;
}
