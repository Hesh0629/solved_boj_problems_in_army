#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
char init[52][52];
int vis[52][52];
int dp[52][52];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dfs(int i,int j, int vis[52][52]){
	int num=init[i][j]-'0';
	int ret=0;
	int cnt=0;
	for(int k=0;k<4;k++){
		int x=i+num*dx[k], y=j+num*dy[k];
		if(x<=0||x>n||y<=0||y>m) continue;
		else if(init[x][y]=='H') continue;
		else{
			cnt++;
			if(vis[x][y]){
				cout<<-1<<endl;
				exit(0);
			}
			else if(dp[x][y])
				ret=max(ret,dp[x][y]+1);
			else{
				vis[x][y]=1;

				dp[i][j]=max(dp[i][j],dfs(x,y,vis)+1);
				ret=max(ret,dp[i][j]);
				
				vis[x][y]=0;
			}
		}
	}
	if(!cnt)
		return 1;
	else
		return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(init,-1,sizeof(init));
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>init[i][j];
	}
	vis[1][1]=0;
	cout<<dfs(1,1,vis)<<endl;
}
