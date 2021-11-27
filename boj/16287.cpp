// 이게 dp였다니
#include<bits/stdc++.h>
using namespace std;
int n,w,init,dp[800000];
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  cin>>w>>n;
  for(int i=0;i<n;i++){
    cin>>init;
    v.push_back(init);
  }
  sort(v.begin(),v.end());
  //i번째 앞을 기준으로 값 2개를 잡고
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(v[i]+v[j]>w)continue;
      // dp배열에는 i번째 이전에 값이 등장했는지를 저장해두었다.
      else if(dp[w-(v[i]+v[j])]){
        cout<<"YES"<<endl;
        return 0;
      }
    }
    // 이러면 i번째 이전에 v[i]+v[j]가 등장한것만 카운트 가능
    for(int j=0;j<i;j++){
      if(v[i]+v[j]<w)dp[v[i]+v[j]]=1;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
