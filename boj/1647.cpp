// 단순하게 생각하면 전체 마을의 최소 스패닝 트리만들고 가장 비싼 길 끊으면 두 마을로 분리된다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,m,ex=-1;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	vector<int>vis(n+1,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	pq.push({0,1}); // first=가중치, second=num
	int ans=0;
	while(!pq.empty()){
		int house=pq.top().second;
		int cost=pq.top().first;
		pq.pop();
		if(vis[house])continue;
		vis[house]=1;
		ans+=cost;
		ex=max(ex,cost);
		for(auto i:adj[house]){
			if(!vis[i.first]) pq.push({i.second,i.first});
		}
	}
	cout<<ans-ex<<endl;
}
