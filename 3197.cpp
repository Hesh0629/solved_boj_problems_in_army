#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
//  간척사업 (우리집)을 이용하는 방식
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[102][102];
int map[102][102];
queue<pair<int,int>>beach[10000];
void dfs(int x,int y,int comp){ //DFS로 각 섬에 번호를 부여한다.
	if(vis[x][y]) return;
	vis[x][y]=comp;
	map[x][y]=comp;
	for(int i=0;i<4;i++){
		if(map[x+dx[i]][y+dy[i]]!=-1&&map[x+dx[i]][y+dy[i]]!=0)
			dfs(x+dx[i],y+dy[i],comp);
		if(map[x+dx[i]][y+dy[i]]==0) beach[comp].push({x,y});
	}
}
int bfs(int comp,int len){ //bfs인지 애매하지만 육지와 맞붙어 있는 바다를 매꾼다. 이를 다른 육지와 만날때까지 반복. 만나면 return
	queue<pair<int,int>>q;
	if(beach[comp].empty()) return 987654321;
	while(!beach[comp].empty()){
		auto cur=beach[comp].front();
		beach[comp].pop();
		for(int i=0;i<4;i++){
			if(vis[cur.first+dx[i]][cur.second+dy[i]]) continue;
			else if(map[cur.first+dx[i]][cur.second+dy[i]]==0) {
				q.push({cur.first+dx[i],cur.second+dy[i]});
				vis[cur.first+dx[i]][cur.second+dy[i]]=comp;
			}
			else if(map[cur.first+dx[i]][cur.second+dy[i]]!=comp&&map[cur.first+dx[i]][cur.second+dy[i]]!=-1)
				return len;
		}
	}
	beach[comp]=q;
	return bfs(comp,len+1);
}
int main() {
	int n,comp=2;
	cin>>n;
	vector<pair<int,int>>land;
	memset(map,-1,sizeof(map));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			cin>>map[i][j];
			if(map[i][j]) land.push_back({i,j});
		}
	}
	for(auto i:land) dfs(i.first,i.second, comp++);
	int ans=987654321;
	for(int i=2;i<comp;i++) {
		memset(vis,0,sizeof(vis));
		ans=min(ans,bfs(i,0));
	}
	cout<<ans<<endl;
}
