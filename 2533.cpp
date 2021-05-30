// 점화식만 세우면 시간제한은 안걸리고 풀 수 있는 문제. 지금보니 O(N)으로 접근이 된다.
// 별도 memozation은 없고 DFS문제에 가까웠다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define endl '\n'
#define MAX 1000001 
using namespace std;
vector<int>adj[MAX];
int dp[MAX][2];
int dfs0(int pre, int cur);
int dfs1(int pre, int cur);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int>root(n+1,1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp,-1,sizeof(dp));
	cout<<min(dfs0(1,1),dfs1(1,1))<<endl;
	return 0;
}
int dfs0(int pre, int cur){ //cur이 얼리가 아닌경우 자식은 반드시 얼리어답터
	if(dp[cur][0]!=-1) return dp[cur][0];
	else if(adj[cur].size()==0)
		return 0;
	else{
		dp[cur][0]=0;
		for(auto i:adj[cur]){
			if(i==pre) continue;
			dp[cur][0]+=dfs1(cur,i);
		}
		return dp[cur][0];
	}
}
int dfs1(int pre, int cur){ //cur이 얼리인 경우 자식은 둘중하나 (작은걸로 결정)
	if(dp[cur][1]!=-1) return dp[cur][1];
	else if(adj[cur].size()==0)
		return 1;
	else{
		dp[cur][1]=1; //자신은 얼리니까
		for(auto i:adj[cur]){
			if(i==pre) continue;
			dp[cur][1]+=min(dfs0(cur,i),dfs1(cur,i));
		}
		return dp[cur][1];
	}
}
