#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>>adj[10][10];
int map[10][10];
int temp[10][10];
int n,m;
vector<pair<int,int>>v;
void dfs(pair<int,int>cur){
	temp[cur.first][cur.second]=2;
	for(auto i:adj[cur.first][cur.second]){
		if(temp[i.first][i.second]==0) dfs(i);
	}
}
int cal(pair<int,int> a,pair<int,int> b, pair<int,int> c){
	if(a==b||a==c||b==c) return 0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++) temp[i][j]=map[i][j];
	}
	temp[a.first][a.second]=1;
	temp[b.first][b.second]=1;
	temp[c.first][c.second]=1;
	for(auto i:v) dfs({i.first,i.second});
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(temp[i][j]==0) ans++;
		}
	}
	return ans;
}
int main() {
	cin>>n>>m;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++) map[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			cin>>map[i][j];
			if(map[i][j]==2) v.push_back({i,j});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==1) continue;
			if(!map[i-1][j]) adj[i][j].push_back({i-1,j});
			if(!map[i+1][j]) adj[i][j].push_back({i+1,j});
			if(!map[i][j-1]) adj[i][j].push_back({i,j-1});
			if(!map[i][j+1]) adj[i][j].push_back({i,j+1});
		}
	}
	vector<pair<int,int>>ap,bp,cp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			if(map[i][j]==0){
				ap.push_back({i,j});
				bp.push_back({i,j});
				cp.push_back({i,j});
			}
		}
	}
	int ans=0;
	for(auto i:ap){
		for(auto j:bp){
			for(auto k:cp) ans=max(ans,cal(i,j,k));
		}
	}
	cout<<ans<<endl;
}
