//어렵진 않았고 자괴감만 잔뜩 든 문제. 제발 dist[start], price[start]좀 0으로 초기화 합시다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const long long int INF=100000000000;
vector<pair<long long int,long long int>>adj[1001];
vector<long long int>price(1001,INF);
vector<long long int>history[1001];
vector<long long int>cnt(1001,0);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		long long int s,e,w;
		cin>>s>>e>>w;
		adj[s].push_back({e,w});
	}
	int start,end;
	cin>>start>>end;
	priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
	price[start]=0; //언제쯤 초기화 할거야 대체 이 나래기야....ㅠㅠ
	pq.push({0,start}); //first = price, second = node_number
	history[start].push_back(start);
	while(!pq.empty()){
		long long int pre_cost=pq.top().first;
		int pre=pq.top().second;
		pq.pop();
		for(auto i:adj[pre]){
			if(price[i.first]>i.second+pre_cost){
				price[i.first]=i.second+pre_cost;
				history[i.first]=history[pre];
				history[i.first].push_back(i.first);
				pq.push({price[i.first],i.first});
			}
		}
	}
	cout<<price[end]<<'\n'<<history[end].size()<<'\n';
	for(auto i:history[end]){
		cout<<i<<" ";
	}
}
