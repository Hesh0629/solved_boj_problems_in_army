#include <bits/stdc++.h>
typedef long long int ll;
#define endl '\n'
using namespace std;
ll n,a,b;
vector<pair<ll,ll>>v;
// cmp 함수 잘못 작성하면 segfault가 발생한다.
// ref : https://codingdog.tistory.com/entry/c-sort-%EC%9D%98-%EB%B9%84%EA%B5%90%ED%95%A8%EC%88%98%EA%B0%80-true%EB%A7%8C-%EB%A6%AC%ED%84%B4%ED%95%A0-%EB%95%8C-%EC%96%B4%EB%96%A4-%EC%9D%BC%EC%9D%B4-%EC%9D%BC%EC%96%B4%EB%82%A0%EA%B9%8C%EC%9A%94
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
  if(a.second == b.second)
    return a.first<b.first;
  else
    return a.second<b.second;
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
  sort(v.begin(),v.end(),cmp);
  ll ans=0,fin=0;
  for(int i=0;i<n;i++){
    if(v[i].first>=fin){
      ans++;
      fin=v[i].second;
    }
  }
  cout<<ans<<endl;
  return 0;
}
