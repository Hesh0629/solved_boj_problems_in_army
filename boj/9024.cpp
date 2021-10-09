// 모든 V[0:N)에 대하여 가능한 경우의 수 O(N) 를 이분탐색으로 O(logN) 으로 푸는 문제
// 따라서 케이스당 O(NlogN)으로 푸는게 가능 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n,k;
int translation(int a){
  return (a>0) ? a:-a;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int test=0;test<t;test++){
    cin>>n>>k;
    vector<int>v(n);
    pair<int,int>ans={0,987654321}; // 개수 / gap
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
      auto iter=lower_bound(v.begin()+i+1,v.end(),k-v[i]);
      if(iter==v.end()){
        if(translation(k-(v[i]+v.back()))<ans.second)
          ans={1,translation(k-(v[i]+v.back()))};
        else if(translation(k-(v[i]+v.back()))==ans.second)
          ans.first+=1;
      }
      else{
        if(*iter==k-v[i]){
          if(translation(k-(v[i]+*iter))<ans.second)
            ans={1,translation(k-(v[i]+*iter))};
          else if(translation(k-(v[i]+*iter))==ans.second)
            ans.first+=1;
        }
        else{
          int cur;
          if(iter==v.begin()+i+1) cur=*iter;
          else if(translation(k-(*(iter-1)+v[i]))<translation(k-(*iter+v[i])))
            cur=*(iter-1);
          else cur=*iter;
          if(translation(k-(v[i]+cur))<ans.second)
            ans={1,translation(k-(v[i]+cur))};
          else if(translation(k-(v[i]+cur))==ans.second)
            ans.first+=1;
        }
      }
    }
    cout<<ans.first<<endl;
  }
}
