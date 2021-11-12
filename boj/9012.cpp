#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int asdf=0;asdf<n;asdf++){
    int cut=0;
    stack<char>st;
    string s;
    cin>>s;
    for(auto i:s){
      if(i=='(') st.push(i);
      else{
        if(st.empty()){
          cut=1;
          break;
        }
        else st.pop();
      }
    }
    if(cut ||!st.empty()) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
}
