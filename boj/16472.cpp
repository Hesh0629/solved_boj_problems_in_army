#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
map<char,int>mp;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  cin>>s;
  ans=0;
  int l=0,r=0;
  while(l<s.size()&&r<s.size()){
    mp[s[r]]++;
    if(mp.size()<=n) ans=max(ans,r-l+1);
    else{
      while(mp.size()>n){
        if(--mp[s[l]]==0) mp.erase(s[l]);
        l++;
      }
    }
    r++;
  }
  cout<<ans<<endl;
}
