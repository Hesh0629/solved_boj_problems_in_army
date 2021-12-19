// 수를 내림차순으로 정렬
// 가장 큰 수를 기준으로 왼쪽 오른쪽에 다음으로 큰 수를 배치
// 이 때 차이가 큰쪽으로 놔줘야 다음번에 놓을 때 차이가 적어짐
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
deque<int>cur,v;
int t,n,init;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int asdf=0;asdf<t;asdf++){
    cur.clear();
    cur.shrink_to_fit();
    v.clear();
    v.shrink_to_fit();
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>init;
      v.push_back(init);
    }
    sort(v.begin(),v.end(),greater<>());
    int ans=0;
    for(auto i:v){
      if(cur.empty())cur.push_back(i);
      else if(cur.front()-i>cur.back()-i){
        ans=max(ans,cur.front()-i);
        cur.push_front(i);
      }
      else {
        ans=max(ans,cur.back()-i);
        cur.push_back(i);
      }
    }
    cout<<ans<<endl;
  }
}
