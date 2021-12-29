//각 시간대별로 가장 최대값을 배정해주고 팅긴애들은 lef에 저장해두고
//필요할 때마다 이후에 쓸 수 있다. (deadline 안쪽에 들어오니까)
#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>>pq[200001],lef;
int n;
long long int ans=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int deadLine,cupNoodle;
    cin>>deadLine>>cupNoodle;
    pq[deadLine].push(cupNoodle);
  }
  for(int i=n;i>0;i--){
    if(pq[i].empty()){
      if(lef.empty())continue;
      else {
        ans+=lef.top();
        lef.pop();
      }
    }
    else{
      if(lef.empty()){
        ans+=pq[i].top();
        pq[i].pop();
      }
      else if(pq[i].top()>lef.top()){
        ans+=pq[i].top();
        pq[i].pop();
      }
      else{
        ans+=lef.top();
        lef.pop();
      }
      while(!pq[i].empty()){
        lef.push(pq[i].top());
        pq[i].pop();
      }
    }
  }
  cout<<ans<<endl;
}
