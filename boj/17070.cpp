#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define endl '\n'
using namespace std;
int n;
int dp[17][17][3];
int zip[17][17]={0};
vector<pair<pair<int,int>,int>>adj[17][17][3];
int dfs(int x,int y, int pose){
	//cout<<x<<" "<<y<<endl;
	if(dp[x][y][pose]!=-1) return dp[x][y][pose];
	else if(x==n-1&&y==n-1) return 1;
	else{
		int res=0;
		for(auto i:adj[x][y][pose])
			res+=dfs(i.first.first,i.first.second,i.second);
		dp[x][y][pose]=res;
		return res;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>zip[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){ //포즈 가로=0 , 세로=2, 대각선 =1
				if(zip[i][j]==1) continue;
				else{
					if(i+1<n&&!zip[i+1][j]&&k!=0) adj[i][j][k].push_back({{i+1,j},2});
					if(j+1<n&&!zip[i][j+1]&&k!=2) adj[i][j][k].push_back({{i,j+1},0});
					if(i+1<n && j+1<n&&!zip[i+1][j+1]&&!zip[i+1][j]&&!zip[i][j+1]) adj[i][j][k].push_back({{i+1,j+1},1});
				}	
			}
		}
	}
	cout<<dfs(0,1,0)<<endl; //머리를 기준으로 위치를 잡음
}
