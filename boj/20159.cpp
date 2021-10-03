#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,x;
vector<int>v,pre[2];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++) {
    cin>>x;
    v.push_back(x);
  }
  pre[0].resize(n/2,0);
  pre[1].resize(n/2,0);
  for(int i=0;i<n;i+=2) {
    if(!i) pre[0][i/2]=v[i];
    else pre[0][i/2]=pre[0][i/2-1]+v[i];
  }
  for(int i=1;i<n;i+=2) {
    if(i==1) pre[1][i/2]=v[i];
    else pre[1][i/2]=pre[1][i/2-1]+v[i];
  }
  int ans=pre[0][n/2-1];
  for(int i=0;i<n;i++){
    int me;
    if(i%2==0){
      if(i==0) 
        me=pre[1][n/2-1];
      else 
        me=pre[0][i/2-1]+pre[1][n/2-1]-pre[1][i/2-1];
      ans=max(ans,me);
    }
    else{
      if(i==1) 
        me=v[0]+pre[1][n/2-1]-v[n-1];
      else if(i==n-1) me=0;
      else 
        me=pre[0][i/2]+pre[1][n/2-2]-pre[1][i/2-1];
      ans=max(ans,me);
    }
  }
  cout<<ans<<endl;
}
