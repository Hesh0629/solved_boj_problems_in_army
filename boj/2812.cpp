#include<bits/stdc++.h>
using namespace std;
int n,k,lef;
string s;
vector<char>ans;
multiset<char>ms;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  cin>>s;
  lef=k;
  int x=1,y=x+lef-1;
  for(int i=x;i<=y;i++) ms.insert(s[i]);
  for(int i=0;i<n;i++){
    if(lef==0) ans.push_back(s[i]);
    else if(s[i]<*ms.rbegin()||i+lef>=n){
      auto iter=ms.find(s[y--]);
      ms.erase(iter);
      lef--;
    }
    else
      ans.push_back(s[i]);
    if(lef==1){
      auto iter=ms.find(s[x]);
      ms.erase(iter);
      x++;
      y++;
      ms.insert(s[x]);
    }
    else if(lef>1){
      auto iter=ms.find(s[x]);
      ms.erase(iter);
      x++;
      y++;
      ms.insert(s[y]);
    }
  }
  for(auto i:ans)cout<<i;
}
