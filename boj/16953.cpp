#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>a>>b;
  int cur=b,cnt=0;
  while(cur!=0&&cur!=a){
    if(cur%2==0){
      cur/=2;
      cnt++;
    }
    else if(cur%10==1){
      cur/=10;
      cnt++;
    }
    else{
      cout<<-1<<endl;
      return 0;
    }
  }
  if(cur==a)cout<<cnt+1<<endl;
  else cout<<-1<<endl;
  return 0;
}
