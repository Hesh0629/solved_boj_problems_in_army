// 개인적으로 BFS와 DFS의 특성을 잘 나타낸 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1},idx;
int init[52][52],vis[52][52];
queue<pair<int,int>>q;
void dfs(int x,int y){
	if(vis[x][y]) return;
	vis[x][y]=1;
	for(int i=0;i<8;i++){
		if(init[x+dx[i]][y+dy[i]]==-1) continue;
		else if(init[x+dx[i]][y+dy[i]]==0){
			vis[x+dx[i]][y+dy[i]]=1;
      q.push({x+dx[i],y+dy[i]});
		}
		if(!vis[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		idx=0;
		cin>>m>>n;
		if(n==0&&m==0) return 0;
		memset(init,-1,sizeof(init));
		memset(vis,0,sizeof(init));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>init[i][j];
		}
		if(init[1][1]==0) {
			vis[1][1]=1;
			q.push({1,1});
		}
		else{
			idx++;
			dfs(1,1);
		}
		while(!q.empty()){
			int x=q.front().first, y=q.front().second;
			q.pop();
			for(int i=0;i<8;i++){
				if(init[x+dx[i]][y+dy[i]]==-1) continue;
				else if(!vis[x+dx[i]][y+dy[i]]){
					if(init[x+dx[i]][y+dy[i]]==1){
						idx++;
						dfs(x+dx[i],y+dy[i]);
					}
					else{
						vis[x+dx[i]][y+dy[i]]=1;
						q.push({x+dx[i],y+dy[i]});
					}
				}
			}
		}
		cout<<idx<<endl;
	}
}
