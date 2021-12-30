// 이미 사용되고 있는 멀티탭중에 앞으로 안쓰이거나 가장 나중에 쓰일 멀티탭을 뽑으면 됨
#include <bits/stdc++.h>
using namespace std;
int n,k,init,ans=0;
set<int>cur;
vector<pair<int,int>>input;
set<pair<int,int>>st;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i=0;i<k;i++){
    cin>>init;
    input.push_back({init,i});
    st.insert({init,i});
  }
  for(auto i:input){
    if(cur.size()<n){
      st.erase(i);
      cur.insert(i.first);
    }
    else if(cur.find(i.first)!=cur.end())
      st.erase(i);
    else{
      pair<int,int>cut={-1,-1};
      for(auto k:cur){
        auto it=st.lower_bound(make_pair(k,-1));
        if(it==st.end()||it->first!=k) cut={k,987654321};
        else if(cut.second<it->second) cut=*it;
      }
      st.erase(i);
      cur.insert(i.first);
      cur.erase(cut.first);
      ans++;
    }
  }
  cout<<ans<<endl;
}
