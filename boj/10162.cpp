#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<int>ans;
  ans.push_back(n/300);
  n%=300;
  ans.push_back(n/60);
  n%=60;  
  ans.push_back(n/10);
  n%=10;
  if(n) cout<<-1<<endl;
  else{
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
