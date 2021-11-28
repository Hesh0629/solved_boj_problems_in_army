#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    v.push_back(init);
  }
  int cur=30;
  for(int i=0;i<n;i++){
    if(v[i]<=cur){
      cnt++;
      cur-=v[i];
      if(cur==0)cur=30;
    }
    else{
      if((long double)v[i]/2<=(long double)cur)cnt++;
      cur=30;
    }
  }
  cout<<cnt<<endl;
}
