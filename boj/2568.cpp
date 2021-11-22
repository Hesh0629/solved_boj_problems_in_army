// Longest Increasing Sequence 복습. 사실 구현 난이도가 막 높진 않았는데 오랜만이였나....//
// LIS배열을 구해주고 Map에서 해당 값들을 지워주면 우리가 지워야 하는 전깃줄 번호만 남게된다!
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
map<int,int>mp;
vector<pair<int,int>>v,order;
vector<int>input,temp;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
    mp[b]=a; //key:들어간 숫자 value: 전봇대 A에 대한 위치
  }
  sort(v.begin(),v.end());
  for(auto i:v) 
    input.push_back(i.second);
  for(auto i:input){
    auto iter=lower_bound(temp.begin(),temp.end(),i);
    if(iter==temp.end()){
      temp.push_back(i);
      order.push_back({temp.size()-1,i});
    }
    else{
      order.push_back({iter-temp.begin(),i});
      temp[iter-temp.begin()]=i;
    }
  }
  int last=temp.size()-1;
  for(int i=order.size()-1;i>=0;i--){
    if(order[i].first==last){
      mp.erase(order[i].second);
      last--;
    }
  }
  cout<<mp.size()<<endl;
  vector<int>ans;
  for(auto it=mp.begin();it!=mp.end();it++)
    ans.push_back(it->second);
  sort(ans.begin(),ans.end());
  for(auto i:ans)cout<<i<<endl;
}
