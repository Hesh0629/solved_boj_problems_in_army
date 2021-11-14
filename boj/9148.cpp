// 메모제이션!
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int dp[51][51][51];
int rec(int a,int b,int c){
  if(a==0||b==0||c==0) return 1;
  else if(dp[a][b][c]!=-1) return dp[a][b][c];
  else if(a<b&&b<c)
    dp[a][b][c]=rec(a,b,c-1)+rec(a,b-1,c-1)-rec(a,b-1,c);
  else
    dp[a][b][c]=rec(a-1,b,c) + rec(a-1,b-1,c)+rec(a-1,b,c-1)-rec(a-1,b-1,c-1);
  return dp[a][b][c];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<=20;i++){
    for(int j=0;j<=20;j++){
      for(int k=0;k<=20;k++)
        rec(i,j,k);
    }
  }
  while(1){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==-1&&b==-1&&c==-1) break;
    cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
    if(a<=0||b<=0||c<=0) cout<<1<<endl;
    else if(a>20||b>20||c>20) cout<<rec(20,20,20)<<endl;
    else cout<<rec(a,b,c)<<endl;
  }
  return 0;
}
