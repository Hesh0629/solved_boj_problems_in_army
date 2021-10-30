#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int n,c,m,a,b,w,cargo[2001];
vector<pair<pair<int,int>,int>>v;
//끝나는 지점을 기준으로 정렬하고 최대한 빨리 내려주면 되는 일이다.
bool cmp(pair<pair<int,int>,int>a, pair<pair<int,int>,int>b){
  if(a.first.second == b.first.second)
    return a.first.first < b.first.first;
  else
  return a.first.second < b.first.second;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(cargo,0,sizeof(cargo));
  cin>>n>>c;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    v.push_back({{a,b},w});
  }
  sort(v.begin(),v.end(),cmp);
  long long int ans=0;
  for(auto i:v){
    long long int cur_max=-1;
    for(int j=i.first.first;j<i.first.second;j++) cur_max=max(cur_max,cargo[j]);
    if(cur_max+i.second<=c){
      for(int j=i.first.first;j<i.first.second;j++) cargo[j]+=i.second;
      ans+=i.second;
    }
    else{
      int init=c-cur_max;
      for(int j=i.first.first;j<i.first.second;j++) cargo[j]+=init;
      ans+=init;
    }
    //cout<<"("<<i.first.first<<" "<<i.first.second<<" / "<<i.second<<") "<<ans<<endl;
  }
  cout<<ans<<endl;
}
