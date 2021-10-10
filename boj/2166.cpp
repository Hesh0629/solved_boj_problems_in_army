// n개의 점으로 이루어진 다각형의 넒이 구하기
// 한 개의 점을 기준으로 나머지 2개의 점을 잡아가면서 ccw로 평행사변형 넓이/2를 해주면 된다.
// 중간에 겹치는 부분이 생겨서 겹치거나 더 구한 부분을 빼주는데 순서에 따라 음수가 나올 수 있으니 절대값 변환

#include <bits/stdc++.h>
using namespace std;
long long int n,x,y;
vector<pair<long long int,long long int>>loc;
long double ccw(pair<long long int,long long int>a,pair<long long int,long long int>b,pair<long long int,long long int>c){
  pair<long long int,long long int>v1={b.first-a.first,b.second-a.second};
  pair<long long int,long long int>v2={c.first-a.first,c.second-a.second};
  long double ans=(v1.first*v2.second)-(v2.first*v1.second);
  return ans/2;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    loc.push_back({x,y});
  }
  long double ans=0;
  for(int i=1;i<n-1;i++)
    ans+=ccw(loc[0],loc[i],loc[i+1]);
  
  cout.precision(1);
  cout<<fixed;
  cout<<((ans>0) ? ans:-ans)<<endl;
}
