#include <bits/stdc++.h>
#define INF 987654321
#define endl '\n'
using namespace std;
vector<int>adj[501];
vector<int>t(501,0);
vector<int>start(501,1);
int n,input,dp[501];
void init(){
	for(int i=1;i<=n;i++){
		cin>>t[i];
		while(1){
			cin>>input;
			if(input==-1) break;
			adj[i].push_back(input);
			start[input]=0;
		}
	}
}
int dfs(int i){
	if(dp[i]!=INF) return dp[i];
	int ans=0;
	for(auto k:adj[i])
		ans=max(dfs(k),ans); 
		// 역설적이게도 선행 건물을 모두 지은 경로를 택하려면 최장 경로를 찍어야한다.
	ans+=t[i];
	dp[i]=ans;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<501;i++) dp[i]=INF;
	cin>>n;
	init();
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(start[i]) q.push(i);
	}
	start.shrink_to_fit();
	while(!q.empty()){
		int s=q.front();
		q.pop();
		dfs(s);
	}
	for(int i=1;i<=n;i++) cout<<dp[i]<<endl;
}
