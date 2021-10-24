#include <bits/stdc++.h>
#define div 1000000
using namespace std;
typedef unsigned long long ll;
typedef struct {
  ll value[2][2];
}mat;
ll n;
mat orig;
mat mul(mat a,mat b){
  mat ret;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++)
      ret.value[i][j]=(a.value[i][0]*b.value[0][j]+a.value[i][1]*b.value[1][j])%div;
  }
  return ret;
}
mat cal(ll n){
  mat res;
  if(n==1){
    return orig;
  }
  else if(n%2==0){
    res=cal(n/2);
    res=mul(res,res);
  }
  else{
    res=cal(n/2);
    res=mul(res,res);
    res=mul(res,orig);
  }
  return res;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  orig.value[0][0]=1;
  orig.value[0][1]=1;
  orig.value[1][0]=1;
  orig.value[1][1]=0;
  cin>>n;
  mat ans=cal(n);
  cout<<ans.value[0][1]%div<<endl;
}
