// 서강 그라운드. 기본적인 다익스트라 문제
// TMI) 서강 그라운드는 본인이 입학할 때 OT가 진행되는 동안 SGBS가 제작한 영상 이름이기도 하다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100000
using namespace std;
vector<pair<int,int>>adj[101];
vector<int>item(101,0);
int n,m,r;
int dijk(int start){
	vector<int>dist(101, MAX);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,start});
	dist[start]=0;
	while(!pq.empty()){
		int pre_d=pq.top().first;
		int pre_n=pq.top().second;
		pq.pop();
		for(auto i:adj[pre_n]){
			if(dist[i.first]>pre_d+i.second){
				dist[i.first]=pre_d+i.second;
				pq.push({dist[i.first],i.first});	
			}
		}
	}
	int able=0;
	for(int i=1;i<=n;i++){
		if(dist[i]<=m)
			able+=item[i];
	}
	return able;
}
int main() {
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++)
		cin>>item[i];
	for(int i=0;i<r;i++){
		int a,b,d;
		cin>>a>>b>>d;
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dijk(i));
	cout<<ans;
}
