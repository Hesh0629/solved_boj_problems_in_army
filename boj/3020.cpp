// 정렬하고 처음 부딪히는 위치를 이진탐색하면 될 것을 너무 어렵게 생각하고 있었다.
// O(h*log n)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,h,x;
vector<int>low,up;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>h;
  for(int i=1;i<=n;i++){
    cin>>x;
    if(i%2==1) 
      up.push_back(x); // 위로 솟은 장애물
    else 
      low.push_back(h-x);//아래로 꽂는 장애물
  }

  //일단 틀린 부분
  sort(up.begin(),up.end());
  sort(low.begin(),low.end());

  pair<int,int> ans={987654321,0}; // 개수, 구간 개수
  for(int i=1;i<=h;i++){
    auto up_crash=lower_bound(up.begin(),up.end(),i);
    auto low_crash=lower_bound(low.begin(),low.end(),i);

    int cur=(up.size()-(up_crash-up.begin()))+(low_crash-low.begin());

    if(cur<ans.first) ans={cur,1};
    else if(cur==ans.first) ans.second++;
  }
  cout<<ans.first<<" "<<ans.second<<endl;
}
