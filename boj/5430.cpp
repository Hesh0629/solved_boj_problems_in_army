#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int asdf=0;asdf<t;asdf++){
    int flag=0,dir=0;
	  string func;
    deque<int>v;
	  cin>>func;
	  cin>>n;
    for(int i=0;i<=n*2;i++){
      if(n==0){
        string s;
        cin>>s;
        break;
      }
      char discard;
      int init;
      if(i%2==0) cin>>discard;
      else {
        cin>>init;
        v.push_back(init);
      }
    }
    for(auto i:func){
      if(i=='R'){
        if(dir==0)dir=1;
        else dir=0;
      }
      else {
        if(v.empty()){
          flag=1;
          break;
        }
        else if(dir==1)v.pop_back();
        else v.pop_front();
      }
    }
    if(flag){
      cout<<"error"<<endl;
      continue;
    }
    if(dir)reverse(v.begin(),v.end());
    cout<<"[";
    for(int i=0;i<v.size();i++){
      cout<<v[i];
      if(i!=v.size()-1)cout<<",";
    }
    cout<<"]"<<endl;
  }
}
