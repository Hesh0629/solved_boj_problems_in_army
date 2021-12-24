// 그래프 풀다가 메모리초과나면 Queue가 터지는 것을 의심해보자
// 다익스트라와 반대로 도착 시간을 늘릴 수 있다면 queue에 넣는다.
// 역추적이 필요한데 이건 늘 하던대로,,,
#include<bits/stdc++.h>
using namespace std;
int n,m,s,e;
vector<pair<short int,int>>adj[10001];
set<short int>backTracking[10001];
queue<pair<short int,int>>q; // {현재 위치/이전 위치, 합} / {지난 위치들}}
queue<short int>q2;
int totalDist[10001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(totalDist,0,sizeof(totalDist));
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
  }
  cin>>s>>e;
  q.push({s,0});
  int ans=-1;
  while(!q.empty()){
    int cur=q.front().first;
    int dist=q.front().second;
    q.pop();
    if(totalDist[cur]>dist)continue;
    for(auto i:adj[cur]){
      if(totalDist[i.first]<=dist+i.second){
        if(totalDist[i.first]<dist+i.second){
          backTracking[i.first].clear();
          backTracking[i.first].insert(cur);
          totalDist[i.first]=dist+i.second;
          if(i.first!=e)
            q.push({i.first,dist+i.second});
        }
        else backTracking[i.first].insert(cur);
      }
      if(i.first==e)
        ans=max(ans,dist+i.second);
    }
  }
  cout<<ans<<endl;
  int road=0;
  q2.push(e);
  while(!q2.empty()){
    short int cur=q2.front();
    q2.pop();
    for(auto i:backTracking[cur]){
      road++;
      q2.push(i);
    }
    backTracking[cur].clear();
  }
  cout<<road<<endl;
}
