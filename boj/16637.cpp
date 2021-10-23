#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int n,ans;
string s;
vector<long long int>v;
vector<char>c;
void rec(int idx,long long int val){
  if(idx>=n)
    ans=max(ans,val);
  else if(idx==0){
    val=v[idx];
    rec(idx+1,val);
  }
  else if(idx==n/2) {
    if(c[idx-1]=='+') val+=v[idx];
    else if(c[idx-1]=='-') val-=v[idx];
    else if(c[idx-1]=='*') val*=v[idx];
    ans=max(ans,val);
  }
  else{
    long long int temp=val;
    if(c[idx-1]=='+') temp+=v[idx];
    else if(c[idx-1]=='-') temp-=v[idx];
    else if(c[idx-1]=='*') temp*=v[idx];
    rec(idx+1,temp);
    if(c[idx-1]=='+') {
      if(c[idx]=='+')
        val+=(v[idx]+v[idx+1]);
      else if(c[idx]=='-')
        val+=(v[idx]-v[idx+1]);
      else if(c[idx]=='*')
        val+=(v[idx]*v[idx+1]);
    }
    else if(c[idx-1]=='-') {
      if(c[idx]=='+')
        val-=(v[idx]+v[idx+1]);
      else if(c[idx]=='-')
        val-=(v[idx]-v[idx+1]);
      else if(c[idx]=='*')
        val-=(v[idx]*v[idx+1]);
    }
    else if(c[idx-1]=='*') {
      if(c[idx]=='+')
        val*=(v[idx]+v[idx+1]);
      else if(c[idx]=='-')
        val*=(v[idx]-v[idx+1]);
      else if(c[idx]=='*')
        val*=(v[idx]*v[idx+1]);
    }
    rec(idx+2,val);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans=-9876543210;
  cin>>n;
  cin>>s;
  for(int i=0;i<n;i++){
    if(i%2==0) v.push_back(s[i]-'0');
    else c.push_back(s[i]);
  }
  if(n==1){
    cout<<v[0]<<endl;
    return 0;
  }
  else if(n==3){
    if(c[0]=='+') cout<<v[0]+v[1]<<endl;
    else if(c[0]=='-') cout<<v[0]-v[1]<<endl;
    else if(c[0]=='*') cout<<v[0]*v[1]<<endl;
  }
  else{
    rec(0,0);
    cout<<ans<<endl;
  }
  return 0;
}
