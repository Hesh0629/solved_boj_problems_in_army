//자료구조 시험에서 최소 스패닝 트리는 크루스칼로 풀었는데 요 문제는 프림으로 풀렸다.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	int v,e;
	cin>>v>>e;
	vector<int>vis(v+1,0);
	vector<pair<int,int>>adj[v+1];
	priority_queue<pair<long long int,int>,vector<pair<long long int, int>>,greater<pair<long long int,int>>>pq;
	for(int i=0;i<e;i++){
		long long int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	pq.push({0,1});
	long long int ans=0;
	while(!pq.empty()){
		long long int w=pq.top().first;
		int now=pq.top().second;
		pq.pop();
		if(vis[now])
			continue;
		vis[now]=1;
		ans+=w;
		for(auto i:adj[now]){
			if(vis[i.first])
				continue;
			pq.push({i.second,i.first});
		}
	}
	cout<<ans;
}
