// 다익스트라를 쓰면서 최단경로를 지울때 BFS를 적용해야하는 문제.
// 다익스트라를 살짝 꼬고 경로 역추적 과정이 살짝 고역이었다.
#include<bits/stdc++.h>
#define endl '\n'
#define INF 987654321
using namespace std;
vector<int>pre[501];
vector<pair<int,int>>adj[501];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int ban[501][501],dist[501],vis[501],n,m,s,d;
queue<int>q;
void init(){
  for(int i=0;i<501;i++){
    pre[i].clear();
    pre[i].shrink_to_fit();
    adj[i].clear();
    adj[i].shrink_to_fit();
    dist[i]=INF;
  }
  memset(ban,0,sizeof(ban));
  memset(vis,0,sizeof(vis));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(1){
    init();
    cin>>n>>m;
    if(n==0 && m==0)break;
    cin>>s>>d;
    for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      adj[a].push_back({b,c});
    }
    pq.push({s,0});
    while(!pq.empty()){
      int cur=pq.top().first,cur_dist=pq.top().second;
      pq.pop();
      for(auto i:adj[cur]){
        // 기존 다익스트라와 크게 달라지는 점 : 거리가 같은 상황을 봐야한다;;
        if(dist[i.first]>=cur_dist+i.second){
          if(dist[i.first]==cur_dist+i.second)pre[i.first].push_back(cur);
          else {
              // 거리가 줄어드는 상황에 대해서만 다익스트라 진행
            pre[i.first].clear();
            pre[i.first].shrink_to_fit();
            pre[i.first].push_back(cur);
            pq.push({i.first,cur_dist+i.second});
          }
          dist[i.first]=cur_dist+i.second;
        }
      }
    }
    if(dist[d]==INF){
      cout<<-1<<endl;
      continue;
    }
     // BFS로 역추적해가면서 간선을 지워줘야함. 정점을 지우는게 아님
    int cur=d;
    q.push(d);
    vis[d]=1;
    while(!q.empty()){
      int front_queue=q.front();
      q.pop();
      if(front_queue==s)continue;
      for(auto k:pre[front_queue]){
        ban[k][front_queue]=1;
        // 방문체크 안할 시 메모리초과
        if(vis[k]==0){
          vis[k]=1;
          q.push(k);
        }
      }
    }
    memset(pre,0,sizeof(pre));
    for(int i=0;i<501;i++)dist[i]=INF;
    pq.push({s,0});
    while(!pq.empty()){
      int cur=pq.top().first,cur_dist=pq.top().second;
      pq.pop();
      for(auto i:adj[cur]){
        if(ban[cur][i.first]==1)continue;
        if(dist[i.first]>cur_dist+i.second){
          dist[i.first]=cur_dist+i.second;
          pq.push({i.first,cur_dist+i.second});
        }
      }
    }
    if(dist[d]==INF)
      cout<<-1<<endl;
    else 
      cout<<dist[d]<<endl;
  }
}
