#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[302][302],sea[302][302],vis[302][302];
void dfs(int x,int y){
	if(vis[x][y]) return;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		if(map[x+dx[i]][y+dy[i]]>0) 
			dfs(x+dx[i],y+dy[i]);
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>ice;
	memset(map,-1,sizeof(map));
	memset(sea,0,sizeof(sea));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			cin>>map[i][j];
			if(map[i][j]>0) ice.push_back({i,j});
		}
	}
	for(auto i:ice){
		int cnt=0;
		int x=i.first,y=i.second;
		for(int k=0;k<4;k++){
			if(map[x+dx[k]][y+dy[k]]==0) cnt++;
		}
		sea[x][y]=cnt;
	}
	int day;
	for(day=1;;day++){	
		vector<pair<int,int>>melt;
		vector<pair<int,int>>left;
		memset(vis,0,sizeof(vis));
		for(auto i:ice){
			int x=i.first,y=i.second;
			map[x][y]-=sea[x][y];
			if(map[x][y]<=0){
				map[x][y]=0;
				sea[x][y]=0;
				melt.push_back({x,y});
			}
			else left.push_back({x,y}); // 살아남은 빙하를 ice로 이관해주는걸 까먹었다.
		}
		if(melt.size()==0) continue;
		else if(left.size()==0){
			cout<<0<<endl;
			return 0;
		}
		else{
			dfs(left.front().first,left.front().second);
			for(auto i:left){
				if(vis[i.first][i.second]!=1){
					cout<<day<<endl;
					return 0;
				}
				else continue;
			}
		}
		for(auto i:melt){
			for(int j=0;j<4;j++){
				if(map[i.first+dx[j]][i.second+dy[j]]>0)
					sea[i.first+dx[j]][i.second+dy[j]]++;
			}
		}
		ice=left;
		melt.shrink_to_fit(); //벡터를 지우는 방법
		left.shrink_to_fit();
	}
	return 0;
}
