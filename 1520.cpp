// dfs의 성질과 메모제이션을 활용하면 쉽게 풀리는 문제. 근데 다른곳에서 삽질을 했다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[502][502];
int dp[502][502]; //삽질 포인트) 여기다가 ={-1} 이런것 좀 하지말자
int n,m;
vector<pair<int,int>>adj[502][502];
int dfs(int x,int y){
	if(x==n&&y==m){
		return 1;
	}
	int cur=0;
	for(auto i:adj[x][y]){
		if(dp[i.first][i.second]==-1)
			cur+=dfs(i.first,i.second);
		else
			cur+=dp[i.first][i.second];
	}
	dp[x][y]=cur;
	return cur;
}
int main() {
  cin>>n>>m;
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++)
	  	cin>>arr[i][j];
  }
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
		if(j+1<=m&&arr[i][j+1]<arr[i][j])
			adj[i][j].push_back({i,j+1});
		if(j-1>=1&&arr[i][j-1]<arr[i][j])
		  	adj[i][j].push_back({i,j-1});
		if(i+1<=n&&arr[i+1][j]<arr[i][j])
			adj[i][j].push_back({i+1,j});
		if(i-1>=1&&arr[i-1][j]<arr[i][j])
		  	adj[i][j].push_back({i-1,j});
		dp[i][j]=-1;
	  }
  }
  cout<<dfs(1,1);
}
