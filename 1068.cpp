#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
vector<int>ans;
vector<int>adj[51];
int vis[51]={0};
int cut=0;
int leaf=0;
void dfs(int cur){
	if(adj[cur].empty()) leaf++;
	else{
		for(auto i:adj[cur]) dfs(i);
	}
}
void dfs2(int cur){
	if(adj[cur].empty()) cut++;
	else{
		for(auto i:adj[cur]) dfs2(i);
	}
}
int main() {
	int n,m,root;
	cin>>n;
	int par[51]={0};
	for(int i=0;i<n;i++) {
		cin>>par[i];
		if(par[i]!=-1) adj[par[i]].push_back(i);
		else root=i; // 문제에서는 한번도 0이 루트라고한적이 없다.
	}
	dfs(root);
	cin>>m;
	dfs2(m);
	if(adj[par[m]].size()==1)
		cout<<leaf-cut+1<<endl;
	else
		cout<<leaf-cut<<endl;
}
