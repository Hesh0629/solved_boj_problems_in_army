#include<bits/stdc++.h>
using namespace std;
int n,m,l,ans=0;
vector<int>v,v2;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m>>l;
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    v.push_back(init);
    v2.push_back(init);
  }
  sort(v.begin(),v.end());
  sort(v2.begin(),v2.end(),greater<>());
  for(int animal=0;animal<m;animal++){
    int x,y;
    cin>>x>>y;
    if(y>l) continue;
    auto it1=lower_bound(v.begin(),v.end(),x);
    auto it2=lower_bound(v2.begin(),v2.end(),x,greater<>());
    if((it1==v.end()||*it1-x+y>l)&&(it2==v2.end()||x-*it2+y>l))continue;
    else 
      ans++;
  }
  cout<<ans<<endl;
}
