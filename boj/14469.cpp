// 현재 시간에 대하여 입장 가능한 소들 중 가장 빨리 끝나는 소를 기준으로 정렬
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n;
priority_queue<pr,vector<pr>,greater<pr>>pq;
priority_queue<int,vector<int>>cow;
vector<pr>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    pq.push({a,b});
  }
  int t=0;
  while(1){
    while(pq.top().first<=t&&!pq.empty()){
      cow.push(pq.top().second);
      pq.pop();
    }
    if(pq.size()!=0&&cow.size()==0) t++;
    if(!cow.empty()){
      t+=cow.top();
      cow.pop();
    }
    if(pq.size()==0&&cow.size()==0){
      cout<<t<<endl;
      return 0;
    }
  }
}
