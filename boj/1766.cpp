// 너무 위상정렬을 DFS로만 풀려하지말자
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> adj[32001];
vector<int> indegree(32001,0);
vector<int>ans;
vector<int> vis(32001,0);
int n,m;
int main(){
	cin>>n>>m;
	vector<int>start;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		indegree[b]++;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) start.push_back(i);
	}
	sort(start.begin(),start.end(),less<int>());
	priority_queue<int,vector<int>,greater<int>>pq;
	for(auto i:start){
		pq.push(i);
	}
	while(!pq.empty()){
		int cur=pq.top();
		pq.pop();
		ans.push_back(cur);
		for(auto i:adj[cur]){
			indegree[i]--;
			if(indegree[i]==0)pq.push(i);
		}
	}
	for(auto i:ans){
		cout<<i<<" ";
	}
}
