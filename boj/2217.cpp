#include<bits/stdc++.h>
using namespace std;
int n,init;
priority_queue<int,vector<int>,greater<int>>pq;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>init;
    pq.push(init);
  }
  int ans=-1;
  while(!pq.empty()){
    int weight=pq.size()*pq.top();
    pq.pop();
    ans=max(ans,weight);
  }
  cout<<ans<<endl;
}
