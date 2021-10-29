#include<bits/stdc++.h>
using namespace std;
map<char,long long int>mp;
int n;
string s;
vector<long long int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<s.size();j++)
      mp[s[j]]+=(long long int)pow(10,s.size()-j-1);
  }
  for(auto i=mp.begin();i!=mp.end();i++)
    v.push_back(i->second);
  sort(v.begin(),v.end(),greater<long long int>());
  long long int ans=0;
  int cnt=9;
  for(auto i:v)
    ans+=i*cnt--;
  cout<<ans;
}
