#include<bits/stdc++.h>
using namespace std;
int n,init;
vector<int>v;
set<int>res;
void asdf(int idx,int val){
  res.insert(val);
  if(idx==n)return;
  else{
    asdf(idx+1,val);
    asdf(idx+1,val+v[idx]);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>init;
    v.push_back(init);
  }
  asdf(0,0);
  int pre=0,cur;
  res.erase(0);
  for(auto it=res.begin();it!=res.end();it++){
    cur=*it;
    if(cur-pre!=1)break;
    pre=cur;
  }
  cout<<pre+1<<endl;
  return 0;
}
