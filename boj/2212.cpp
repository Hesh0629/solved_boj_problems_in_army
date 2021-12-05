#include<bits/stdc++.h>
using namespace std;
deque<int>v,gap;
int n,k,init;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>init;
    v.push_back(init);
  }
  sort(v.begin(),v.end());
  int x=0,y=1,ans=0;
  while(y!=v.size()){
    gap.push_back(v[y]-v[x]);
    ans+=v[y]-v[x];
    x++;
    y++;
  }
  sort(gap.begin(),gap.end(),greater<>());
  for(int i=0;i<k-1;i++){
    ans-=gap.front();
    gap.pop_front();
  }
  cout<<ans<<endl;
}
