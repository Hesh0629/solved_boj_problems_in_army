#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<pair<int,int>>v;
int n;
long double total_x,total_y;
long double ans=9999999999999999;
void rec(int cnt,int s,long double x_sum,long double y_sum){
  //벡터의 개수 == n/2, 최대 10!(3628800) 연산
  if(cnt>n/2){
    long double ret=(long double)sqrt(((x_sum)*2-total_x)*((x_sum)*2-total_x)+((y_sum)*2-total_y)*((y_sum)*2-total_y));
    ans=min(ans,ret);
  }
  else{
    for(int i=s;i<n;i++)
      rec(cnt+1,i+1,x_sum+v[i].first,y_sum+v[i].second);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  int T;
  cin>>T;
  for(int asdf=0;asdf<T;asdf++){
    v.clear();
    v.shrink_to_fit();
    total_x=0;
    total_y=0;
    ans=9999999999999999;
    cin>>n;
    for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      total_x+=x;
      total_y+=y;
      v.push_back({x,y});
    }
    rec(1,0,0,0);
    cout<<ans<<endl;
  }
}
