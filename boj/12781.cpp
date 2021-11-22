#include <bits/stdc++.h>
using namespace std;
int x,y,x2,y2,x3,y3,x4,y4;
int ccw(pair<int,int>a,pair<int,int>b,pair<int,int>c){
  pair<int,int>v1={b.first-a.first,b.second-a.second};
  pair<int,int>v2={c.first-a.first,c.second-a.second};
  int ret=v1.first*v2.second-v1.second*v2.first;
  if(ret>0) return 1;
  else if(ret==0) return 0;
  else return -1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin>>x>>y>>x2>>y2>>x3>>y3>>x4>>y4;

  pair<int,int>a={x,y},b={x2,y2},c={x3,y3},d={x4,y4};

  int ret1=ccw(a,b,c)*ccw(a,b,d);
  int ret2=ccw(c,d,a)*ccw(c,d,b);
  
  // 완벽하게 교차할 때만 4조각으로 나눠진다.
  cout<<(ret1<0&&ret2<0)<<endl;
}
