// 무게 무거운것부터 담을 수 있는 대로 담으면 끝
#include<bits/stdc++.h>
using namespace std;
int n,m;
multiset<int, greater<int>>box;
vector<int>crain;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  set<int,greater<int>>test;
  cin>>n;
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    crain.push_back(init);
  }
  sort(crain.begin(),crain.end());
  cin>>m;
  for(int i=0;i<m;i++){
    int init;
    cin>>init;
    box.insert(init);
  }
  int ans=0;
  while(!box.empty()){
    int cur_size=box.size();
    for(auto i:crain){
      auto it=box.lower_bound(i);
      if(it==box.end())continue;
      else box.erase(it);
    }
    if(cur_size==box.size()){
      ans=-1;
      break;
    }
    else ans++;
  }
  cout<<ans<<endl;
}
