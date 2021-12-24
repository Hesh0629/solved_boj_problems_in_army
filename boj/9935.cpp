// O(N)으로 통과시켜야 했던 문제였는데 STL쓰다가 해멘 문제
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s,bomb;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  cin>>bomb;
  string cur;
  int idx=0;
  for(int i=0;i<s.size();i++){
    cur.push_back(s[i]);
    if(cur.size()>bomb.size())idx++;
    if(cur.substr(idx,bomb.size())==bomb){
      cur.erase(idx,bomb.size());
      if(idx>=bomb.size())  idx-=bomb.size();
      else idx=0;
    }
  }
  if(cur.empty())cout<<"FRULA"<<endl;
  else cout<<cur<<endl;
}
