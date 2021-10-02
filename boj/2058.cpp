// 예전 G3 2533 사회망 서비스 문제와 같은 문제
#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000001
using namespace std;
long long int n,m,x,vis[INF],vis2[INF];
vector<long long int>v,e,p,adj[INF];
long long int dfs(int pre, int cur);
long long int dfs2(int pre, int cur);
long long int dfs(int pre, int cur){
	if(vis[cur]) return vis[cur];
	long long int ret=0;
	for(auto i:adj[cur]){
		if(i==pre) continue;
		ret+=dfs2(cur,i);
	}
	vis[cur]=ret+cur;
	return vis[cur];
}
long long int dfs2(int pre, int cur){
	if(vis2[cur]) return vis2[cur];
	long long int ret=0;
	for(auto i:adj[cur]){
		if(i==pre) continue;
		ret+=max(dfs(cur,i),dfs2(cur,i));
	}
	vis2[cur]=ret;
	return vis2[cur];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	cin>>n>>m;
	e.resize(INF,0);
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		e[x]=1;
	}
	for(int i=0;i<m;i++){
		cin>>x;
		p.push_back(x);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i]+p[j]<INF){
				if(e[v[i]+p[j]]){
					adj[v[i]].push_back(v[i]+p[j]);
					adj[v[i]+p[j]].push_back(v[i]);
				}
			}
		}
	}
	long long int ans=0;
	for(auto i:v){
		if(vis[i]==0&&vis2[i]==0) ans+=max(dfs(0,i),dfs2(0,i));
	}
	cout<<ans<<endl;
}
