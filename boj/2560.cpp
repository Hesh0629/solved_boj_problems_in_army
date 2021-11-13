// mod연산에서 -될 수 있으니 mod값을 더하는 것을 잊지말자
#include<bits/stdc++.h>
#define endl '\n'
#define child 1
#define adult 2
#define old 3
using namespace std;
int a,b,d,n;
int dp[1000001][4]; // dp[day][type]= 생존 인구
int diff[1000002][4]; //변화 기록 (저날 해당 type된 인구)
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(diff,0,sizeof(diff));
  cin>>a>>b>>d>>n;
  //--------------------내 풀이---------------------//
  /*dp[0][1]=1;
  diff[0][1]=1;
  for(int day=1;day<=n;day++){
    int db=day-(d-b),ba=day-(b-a),a0=day-a;
    if(db<0) db=0;
    if(ba<0) ba=0;
    if(a0<0) a0=1000001;
    dp[day][old]=(dp[day-1][old]-diff[db][old]+diff[ba][adult]+10000)%1000;
    diff[day][old]=diff[ba][adult]%1000;
    dp[day][adult]=(dp[day-1][adult]-diff[ba][adult]+diff[a0][child]+10000)%1000;
    diff[day][adult]=diff[a0][child]%1000;
    dp[day][child]=(dp[day-1][child]-diff[a0][child]+dp[day][adult]+10000)%1000;
    diff[day][child]=dp[day][adult]%1000;
  }
  cout<<(dp[n][old]+dp[n][adult]+dp[n][child])%1000<<endl;*/

  //-----------------정해-----------------//
  int asdf[1000001];
  memset(asdf,0,sizeof(asdf));
  asdf[0]=1;
  for(int i=1;i<=n;i++){
    if(i>=b) asdf[i]=(asdf[i-1]+asdf[i-a]-asdf[i-b]+1000)%1000;
    else if(i>=a) asdf[i]=(asdf[i-1]+asdf[i-a])%1000;
    else asdf[i]=asdf[i-1]%1000;
  }
  cout<<(asdf[n]-asdf[n-d]+1000)%1000<<endl;
}
