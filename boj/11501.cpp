// 처음 내가 주식을 파는 시점: 최고점일 때
// 이후에 주식을 파는 시점 : 팔고 난 뒤 구간에서 그 다음으로 고점일 때
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int t,n,init,high=-1;
vector<long long int>v;
vector<pair<long long int,long long int>>point;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int asdf=0;asdf<t;asdf++){
    v.clear();
    point.clear();
    v.shrink_to_fit();
    point.shrink_to_fit();
    long long int ans=0;
    vector<long long int>stock;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>init;
      v.push_back(init);
    }
    for(int i=0;i<n;i++){
      if(i==0){
        if(v[i]>v[i+1])point.push_back({v[i],i});
      }
      else if(i==n-1){
        if(v[i]>v[i-1])point.push_back({v[i],i});
      }
      else{
        if(v[i]>v[i-1]&&v[i]>v[i+1])point.push_back({v[i],i});
      }
    }
    sort(point.begin(),point.end(),greater<>());
    int last=-1;
    for(auto i:point){
      if(i.second<=last)continue;
      for(int j=last+1;j<i.second;j++){
        if(v[j]<i.first)
          ans+=i.first-v[j];
      }
      last=i.second;
    }
    cout<<ans<<endl;
  }
}
