#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s>>t;
  while(s!=t&&t.size()>0){
    if(t.back()=='A')
      t.pop_back();
    else{
      t.pop_back();
      string next;
      reverse(t.begin(),t.end());
    }
  }
  if(s==t)cout<<1<<endl;
  else cout<<0<<endl;
}
