// 1. 제발 knapsack 할때는 이전 값좀 땡겨오자
// 2. 그리고 float double을 믿지말자
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,c,dp[10001];
long double m,p;
vector<pair<int,int>>v;
string s;
int trans(string a){
  for(int i=0;i<a.size();i++){
    if(a[i]=='.'){
      a.erase(i,1);
      return stoi(a);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(1){
    memset(dp,0,sizeof(dp));
    v.clear();
    v.shrink_to_fit();
    cin>>n>>s;
    m=trans(s);
    if(n==0&&m==0)break;
    for(int i=0;i<n;i++){
      cin>>c>>s;
      v.push_back({c,trans(s)});
    }
    int cur_ans=-1;
    for(int i=1;i<=n;i++){
      int curC=v[i-1].first,curP=v[i-1].second;
      for(int p=0;p<=m;p++){
        if(p-curP>=0)
          dp[p]=max(dp[p],dp[p-curP]+curC);
        cur_ans=max(cur_ans,dp[p]);
      }
    }
    cout<<cur_ans<<endl;
  }
}
