#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<long double>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    long double asdf;
    cin>>asdf;
    v.push_back(asdf);
  }
  sort(v.begin(),v.end());
  long double e=-1;
  int ans=0;
  for(auto i:v){
    if(e==-1){
      e=i-0.5+m;
      ans++;
    }
    else{
      if(e>=i+0.5) continue;
      else {
        e=i-0.5+m;
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
