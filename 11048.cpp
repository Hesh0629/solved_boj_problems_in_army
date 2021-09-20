// DFS mem하기에는 경로가 너무 분기되어서 TLE가 났던 문제
// 항상 DFS를 이용했었어서 더 틀렸던 것 같다.
// BFS DP도 사용해보자.
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,init[1002][1002],dp[1002][1002];
int dx[2]={0,1}, dy[2]={1,0};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(init,-1,sizeof(init));
	memset(dp,-1,sizeof(dp));

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>init[i][j];
	}

	queue<pair<int,int>>q;
	q.push({1,1});
	dp[1][1]=init[1][1];
	
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();

		//각 경로에 대하여 새로 업데이트가 가능한 경우에 대하여서만 push
		for(int i=0;i<2;i++){
			if(init[x+dx[i]][y+dy[i]]!=-1){
				if(dp[x+dx[i]][y+dy[i]]!=-1) {
					if(dp[x][y]+init[x+dx[i]][y+dy[i]]>dp[x+dx[i]][y+dy[i]]){
						dp[x+dx[i]][y+dy[i]]=dp[x][y]+init[x+dx[i]][y+dy[i]];
						q.push({x+dx[i],y+dy[i]});
					}
				}
				else {
					dp[x+dx[i]][y+dy[i]]=dp[x][y]+init[x+dx[i]][y+dy[i]];
					q.push({x+dx[i],y+dy[i]});
				}
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
