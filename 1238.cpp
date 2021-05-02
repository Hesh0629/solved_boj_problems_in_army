// 도로가 단방향인지 양방향인지 문제를 잘 읽어보자
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
vector<pair<int,int>>adj[1001];
int n,m,x;
int dijk(int start,int target){
	vector<int>dist(n+1,INF);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,start});
	dist[start]=0;
	while(!pq.empty()){
		int pre_n=pq.top().second;
		int pre_d=pq.top().first;
		pq.pop();
		for(auto i:adj[pre_n]){
			if(dist[i.first]>i.second+pre_d){
				dist[i.first]=i.second+pre_d;
				pq.push({dist[i.first],i.first});
			}
		}
	}
	return dist[target];
}
int main() {
  cin>>n>>m>>x;
  for(int i=0;i<m;i++){
	  int a,b,d;
	  cin>>a>>b>>d;
	  adj[a].push_back({b,d});
  }
  int ans=-1;
  for(int i=1;i<=n;i++){
	  ans=max(ans,dijk(i,x)+dijk(x,i));
  }
  cout<<ans;
}
