#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
vector<pair<int,int>>adj[1001];
int dij(int start,int target){
	priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
	vector<long long int>dist(1001,2000000000000);
	dist[start]=0;
	pq.push({0,start}); //pq.first = cost, pq.second=node number
	while(!pq.empty()){
		int cur_node=pq.top().second;
		long long int pre_cost=pq.top().first;
		pq.pop();
		if(dist[cur_node]<pre_cost) continue; //만약 현재 큐를 처리하기전에 거리ㅈ가 줄어들었다면 중복사례이므로 pass
		for(auto i:adj[cur_node]){
			if(dist[i.first]>i.second+pre_cost){
				dist[i.first]=i.second+pre_cost;
				pq.push({dist[i.first],i.first});
			}
		}
	}
	return dist[target];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int s,t,w;
		cin>>s>>t>>w;
		adj[s].push_back({t,w});
	}
	int v1,v2;
	cin>>v1>>v2;
	cout<<dij(v1,v2);
}
