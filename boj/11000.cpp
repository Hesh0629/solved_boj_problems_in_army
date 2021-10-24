#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<pair<int,int>>v;
bool comp(pair<int,int>a,pair<int,int>b){
  if(a.second==b.second) return a.first<b.first;
  else return a.second<b.second;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    v.push_back({a,b});
  }
  sort(v.begin(),v.end()); // 스케듈링 문제와 달리 시작 순서가 빠른대로 팍팍넣는다.
  multiset<int>ans;
  // 모든 v에 대하여 최대한 끝시간과 시작시간 갭을 줄이면서 넣는다.
  for(int i=0;i<n;i++){
    if(v.empty()) ans.insert(v[i].second);
    else{
      auto iter=ans.lower_bound(v[i].first);
      if(iter==ans.end()) ans.insert(v[i].second);
      else if(*iter==v[i].first){
        ans.insert(v[i].second);
        ans.erase(iter);
      }
      else if(*iter!=v[i].first){
        if(iter==ans.begin()) ans.insert(v[i].second);
        else{
          iter--;
          ans.erase(iter);
          ans.insert(v[i].second);
        }
      }
    }
  }
  cout<<ans.size();
}
