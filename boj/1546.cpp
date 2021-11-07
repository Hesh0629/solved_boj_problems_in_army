#include<bits/stdc++.h>
using namespace std;
int n;
long double ans,init,max_v;
vector<long double>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  max_v=-1;
  for(int i=0;i<n;i++){
    cin>>init;
    max_v=max(max_v,init);
    v.push_back(init);
  }
  for(auto i:v)ans+=i/max_v*100;
  cout<<ans/n<<endl;
}
