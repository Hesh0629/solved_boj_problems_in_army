#include<bits/stdc++.h>
#define endl '\n'
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
    if(init) pq.push(init);
    else{
      if(pq.empty())cout<<0<<endl;
      else {
        cout<<pq.top()<<endl;
        pq.pop();
      }
    }
  }
  return 0;
}
