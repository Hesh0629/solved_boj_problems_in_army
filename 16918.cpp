// 하나의 방은 2개의 스위치로 연결. 그리고 스위치는 True or False로 이루어짐
// 초기값에 따라서 진리값이 변경
// 스위치를 기준으로 dfs돌림
// 2-SAT의 함의 그래프를 문제 조건에 따라 새로운 방식으로 그려줄 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>
#define base 100000
using namespace std;
vector<int>dfs_order;
vector<int>adj[200002];
vector<int>adj2[200002];
vector<int>comp(200002,-1);
vector<int>vis(200002,0);
int index=0;
void dfs(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj[cur])
		dfs(i);
	dfs_order.push_back(cur);
}
void dfs2(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj2[cur])
		dfs2(i);
	comp[cur]=index;
}
int main() {
  	int n,m;
  	cin>>n>>m;
  	vector<int>init(n+1,0);
	vector<int>connect[n+1];
  	for(int i=1;i<=n;i++)
		cin>>init[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int input;
			cin>>input;
			connect[input].push_back(i); //입력받은 방이 i번째 스위치와 연결되어 있음
		}
	}
	for(int i=1;i<=n;i++){
		int x=connect[i][0], y=connect[i][1];
		if(init[i]==1){ //초기상태가 불이 켜진 상태라면 TT or FF가능
			adj[x].push_back(y);
			adj[x+base].push_back(y+base);
			adj[y].push_back(x);
			adj[y+base].push_back(x+base);
		}
		else{ //초기상태가 불이 꺼진 상태라면 TF or FT 가능
			adj[x].push_back(y+base);
			adj[y+base].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i);
		dfs(i+base);
	}
	for(int i=1;i<=m;i++){
		for(auto j:adj[i])
			adj2[j].push_back(i);
		for(auto j:adj[i+base])
			adj2[j].push_back(i+base);
	}
	reverse(dfs_order.begin(),dfs_order.end());
	vis.assign(200002,0);
	for(auto i:dfs_order){
		dfs2(i);
		index++;
	}
	for(int i=1;i<=m;i++){
		if(comp[i]==comp[i+base]){
			cout<<0<<'\n';
			return 0;
		}
	}
	cout<<1<<'\n';
	return 0;
}
