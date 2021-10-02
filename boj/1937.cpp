// 이것도 dfs하고 메모제이션 적절히 사용하면 금방 푸는문제. 거의 노드 개수만큼만 조사하면 된다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[505][505]={0};
int dp[505][505];
vector<pair<int,int>>adj[505][505];
int n;
int dfs(int curx,int cury){ //현재 상태에서 얼마나 들어갔는지를 리턴
	if(dp[curx][cury]!=-1)
		return dp[curx][cury];
	else{
		int res=0;
		for(auto i: adj[curx][cury])
			res=max(res,dfs(i.first,i.second));
		dp[curx][cury]=res+1;
		return res+1;
	}
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>arr[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i-1][j]>arr[i][j])
				adj[i][j].push_back({i-1,j});
			if(arr[i+1][j]>arr[i][j])
				adj[i][j].push_back({i+1,j});
			if(arr[i][j-1]>arr[i][j])
				adj[i][j].push_back({i,j-1});
			if(arr[i][j+1]>arr[i][j])
				adj[i][j].push_back({i,j+1});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dp[i][j]=-1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	init();
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			k=max(k,dfs(i,j));
	}
	cout<<k;
}
