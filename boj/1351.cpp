// 가끔은 이렇게 무식하게 들이대도 풀릴때가 있다.
#include <bits/stdc++.h>
using namespace std;
long long int n,p,q;
map<long long int,long long int>mp;
long long int rec(long long int n ){
  if(mp.find(n)!=mp.end()) return mp[n];
  else if(n==0) return 1;
  mp[n/p]=rec(n/p);
  mp[n/q]=rec(n/q);
  return mp[n/p]+mp[n/q];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>p>>q;
  cout<<rec(n);
}
