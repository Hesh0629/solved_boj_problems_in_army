#include<bits/stdc++.h>
using namespace std;
int n,ret,ans=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  ret=1000-n;
  ans+=ret/500;
  ret%=500;
  ans+=ret/100;
  ret%=100;
  ans+=ret/50;
  ret%=50;
  ans+=ret/10;
  ret%=10;  
  ans+=ret/5;
  ret%=5;
  ans+=ret;
  cout<<ans;
}
