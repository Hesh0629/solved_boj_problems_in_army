#include <bits/stdc++.h>
using namespace std;
int n,m,x,ans;
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans=2000000001;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  int l=0,r=1;
  while(l<n&&r<n){
    int cur_gap=v[r]-v[l];
    if(cur_gap>=m) {
      ans=min(ans,cur_gap);
      l++;
      if(l==r) r++;
    }
    else r++;
  }
  cout<<ans<<endl;
}
