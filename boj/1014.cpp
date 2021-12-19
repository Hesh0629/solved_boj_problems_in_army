// 다 뒤집는건 훼이크. 연속된 구간만 뒤집어야한다.
#include <bits/stdc++.h>
using namespace std;
string s;
char cur;
int res0=0,res1=0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]!=cur && i!=0){
      if(s[i]=='0')res1++;
      else res0++;
    }
    cur=s[i];
  }
  if(s.back()=='1')res1++;
  else res0++;
  cout<<min(res0,res1)<<endl;
} 
