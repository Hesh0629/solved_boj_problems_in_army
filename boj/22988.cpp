// 세상 허무했던 문제. 투 포인터를 lower_bound에 너무 의존했던 것 같다.
#include <bits/stdc++.h>
using namespace std;
long double x,input;
long long int n,ans,lef;
vector<long double>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans=0;
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>input;
    if(input==x) ans++;
    else v.push_back(input);
  }
  lef=v.size();
  sort(v.begin(),v.end());
  int l=0,r=v.size()-1;
  // 이렇게 하면 투포인터 O(N)
  while(l<r){
    if(v[l]+v[r]>=x/2){
      ans++;
      l++;
      r--;
      lef-=2;
    }
    else l++;
  }
  ans+=lef/3;
  cout<<ans;
}
