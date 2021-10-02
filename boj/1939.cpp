#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 2000000000
#define endl '\n'
using namespace std;

int main(void) {
	int n, m; // n is vertex number , m is edege number
	cin >> n >> m;
	vector<pair<int, int>>adj[n+1];
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back({w,e});
		adj[e].push_back({w,s});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>pq;
	int a, b; // factory A, B
	cin >> a >> b;
	vector<int>ans(n+1,-1);
	for(auto i:adj[a])	pq.push({i.first,a});
	ans[a]=-1;
	while(!pq.empty()){
		int w=pq.top().first;
		int cur=pq.top().second;
		pq.pop();
		if(ans[cur]>w) continue;
		for(auto i:adj[cur]){
			if(ans[i.second]==-1){
				if(i.first>w) { //if current weight is bigger than edge's weight limit, next weight whill be current weight
					ans[i.second]=w;
					pq.push({w,i.second});
				}
				else { // else, we shoult make next weight = edge's weight limit.
					ans[i.second]=i.first;
					pq.push({i.first,i.second});
				}
			}
			else{
				if(i.first>=w&&ans[i.second]<w){
					ans[i.second]=w;
					pq.push({w,i.second});
				}
				else if(i.first<w&&ans[i.second]<i.first){
					ans[i.second]=i.first;
					pq.push({i.first,i.second});
				}
			}
		}
	}
	cout<<ans[b]<<endl;
	return 0;
}
