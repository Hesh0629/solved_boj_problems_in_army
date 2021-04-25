//2021.04.25 다익스트라 문제의 변형, 특정한 정점을 무조건 지나야 하는 경우
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int n,e;
vector<pair<int,int>>adj[801];
int dij(int start,int target){
	priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
	vector<long long int>dist(801,2000000000000);
	dist[start]=0;
	pq.push({0,start}); //pq.first = cost, pq.second=node number
	while(!pq.empty()){
		int cur_node=pq.top().second;
		long long int pre_cost=pq.top().first;
		pq.pop();
		for(auto i:adj[cur_node]){
			if(dist[i.first]>i.second+pre_cost){
				dist[i.first]=i.second+pre_cost;
				pq.push({dist[i.first],i.first}); //실수한 부분, 다익스트라에서 우선순위 큐에는 도달하는데 걸리는 거리가 저장되어야 한다.
			}
		}
	}
	if(dist[target]==2000000000000)
		return -1;
	else
		return dist[target];
}
int main() {
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int s,t,w;
		cin>>s>>t>>w;
		adj[s].push_back({t,w});
		adj[t].push_back({s,w});
	}
	int v1,v2;
	cin>>v1>>v2;
	int a1=dij(1,v1), a2=dij(v1,v2), a3=dij(v2,n);
	int b1=dij(1,v2), b2=dij(v2,v1), b3=dij(v1,n); //사실 v1->n을 구할때 v1->v2를 구할 수 있지만 dist를 개별 저장해서 시간이 추가로 걸리긴 했다
	if((a1==-1||a2==-1||a3==-1)&&(b1==-1||b2==-1||b3==-1))
		cout<<-1;
	else if(a1==-1||a2==-1||a3==-1)
		cout<<b1+b2+b3;
	else
		cout<<min(a1+a2+a3,b1+b2+b3);
}
