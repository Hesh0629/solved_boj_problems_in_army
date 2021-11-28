#include<bits/stdc++.h>
using namespace std;
map<char, string>mp;
int n,x,y;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    char c;
    cin>>s>>c;
    mp[c]=s;
  }
  string origin,zip;
  cin>>zip;
  for(auto i:zip){
    char cur=i;
    string back=mp[cur];
    origin.insert(origin.end(),back.begin(),back.end());
  }
  cin>>x>>y;
  for(int i=x;i<=y;i++)cout<<origin[i-1];
}
