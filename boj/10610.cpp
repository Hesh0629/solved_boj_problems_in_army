#include<bits/stdc++.h>
using namespace std;
int zero=0,sum=0;
vector<int>ans;
string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='0') zero++;
    sum+=s[i]-'0';
    ans.push_back(s[i]-'0');
  }
  sort(ans.begin(),ans.end(),greater<>());
  if(zero==0||sum%3!=0){
    cout<<-1;
    return 0;
  }
  else{
    for(auto i:ans)cout<<i;
    return 0;
  }
}
