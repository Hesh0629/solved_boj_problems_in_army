#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int asdf=0;asdf<t;asdf++){
    cin>>n;
    vector<pair<int,int>>v;
    int cnt=0;
    for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;
      v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,less<int>>pq;
    for(int i=v.size()-1;i>=0;i--){
      if(i==v.size()-1){
        pq.push(v[i].second);
      }
      else{
        while(pq.top()>v[i].second&&!pq.empty())
          pq.pop();
        pq.push(v[i].second);
      }
    }
    cout<<pq.size()<<endl;
  }
}
