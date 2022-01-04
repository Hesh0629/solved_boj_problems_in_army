#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
map<string,int>mp;
set<string>st;
string s;
int total=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(4);
  cout<<fixed;
  while(getline(cin,s)){
    if(st.find(s)==st.end())
      st.insert(s);
    mp[s]++;
    total++;
  }
  for(auto i:st){
    long double percent=mp[i]/(long double)total*100;
    cout<<i<<" "<<percent<<endl;
  }
}
