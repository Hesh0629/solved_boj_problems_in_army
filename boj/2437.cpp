// 만약 i번째 인덱스까지 검사했을때 앞의 나온 값들은 매끄럽게 이어진 수열이다.
// 만약 v[i]보다 최대값+1 이 작다면 v가 정렬된 상황에서 최대값+1은 영원히 나올 수 없다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,x;
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  int max_v=0;
  for(int i=0;i<n;i++){
    if(v[i]>max_v+1)
      break;
    else
     max_v=max(max_v,max_v+v[i]);
  }
  cout<<max_v+1<<endl;
  return 0;
}
