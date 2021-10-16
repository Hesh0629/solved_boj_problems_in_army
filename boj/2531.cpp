#include <bits/stdc++.h>
using namespace std;
int n,d,k,c,x;
vector<int>v;
map<int,int>mp;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int ans=0;
  cin>>n>>d>>k>>c;
  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }
  for(int i=0;i<n;i++)
    v.push_back(v[i]);
  mp[c]++;
  for(int i=0;i<k;i++)mp[v[i]]++;
  for(int i=1;i<n;i++){
    mp[v[i-1]]--;
    if(mp[v[i-1]]==0) mp.erase(v[i-1]);
    mp[v[i+k-1]]++;
    ans=max(ans,(int)mp.size());
  }
  cout<<ans<<endl;
}
