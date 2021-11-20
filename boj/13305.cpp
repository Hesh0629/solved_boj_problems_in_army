#include <bits/stdc++.h>
using namespace std;
long long int n, total=0,ans=0;
vector<long long int>dist,cost;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n-1;i++){
    int init;
    cin>>init;
    dist.push_back(init);
    total+=init;
  }
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    cost.push_back(init);
  }
  long long int cur=10000000001;
  for(int i=0;i<n-1;i++){
    cur=min(cur,cost[i]);
    ans+=dist[i]*cur;
  }
  cout<<ans<<endl;
}
