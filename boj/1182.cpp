#include<bits/stdc++.h>
using namespace std;
int n,s,init,ans=0;
vector<int>v;
void asdf(int idx,int val,int cnt){
  if(val==s&&cnt!=0) ans++;
  if(idx==n)return;
  else{
    asdf(idx+1,val,0);
    asdf(idx+1,val+v[idx],cnt+1);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>s;
  for(int i=0;i<n;i++){
    cin>>init;
    v.push_back(init);
  }
  asdf(0,0,0);
  cout<<ans<<endl;
}
