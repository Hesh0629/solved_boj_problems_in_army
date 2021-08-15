#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char vis[1502][1502];
char vis2[1502][1502];
char map[1502][1502];
pair<int,int>a={0,0},b;
int n,m;
queue<pair<short int,short int>>beach;
void dfs(int x,int y){
	if(vis[x][y]) return;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		if(map[x+dx[i]][y+dy[i]]==-1)continue;
		else if(map[x+dx[i]][y+dy[i]]=='X')
			dfs(x+dx[i],y+dy[i]);
		else if((map[x+dx[i]][y+dy[i]]=='.'||map[x+dx[i]][y+dy[i]]=='L')&&map[x][y]!='K'){
			beach.push({x,y});
			map[x][y]='K';
		}
	}
}
void bfs(){
	queue<pair<short int,short int>>q;
	queue<pair<short int,short int>>q2;
	vis[a.first][a.second]=1;
	int day=0;
	q.push(a);
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(map[x+dx[i]][y+dy[i]]==-1||map[x+dx[i]][y+dy[i]]=='X') continue;
			else if(x+dx[i]==b.first&&y+dy[i]==b.second) {
				cout<<day<<endl;
				return;
			}
			else if(map[x+dx[i]][y+dy[i]]=='.'&& !vis[x+dx[i]][y+dy[i]]){
				q.push({x+dx[i],y+dy[i]});
				vis[x+dx[i]][y+dy[i]]=1;
			}
		}
	}
	while(!q.empty())q.pop();
	day++;
	//---------------초기 단계에서 이동할 수 있는 경우를 계산-----------------
	//그 이후로 녹일 때마다 이동할 수 있는 경우를 최신화
	while(1){
		if(beach.empty()) { // == 녹일 얼음이 없다
			cout<<day-1<<endl;
			return;
		}
		while(!beach.empty()){
			int x=beach.front().first;
			int y=beach.front().second;
			beach.pop();
			map[x][y]='.';
			for(int i=0;i<4;i++){
				if(map[x+dx[i]][y+dy[i]]=='X'){
					q.push({x+dx[i],y+dy[i]});
					map[x+dx[i]][y+dy[i]]='K';
				}
				if(vis[x+dx[i]][y+dy[i]]&&!vis2[x][y]){
					q2.push({x+dx[i],y+dy[i]}); // q2에는 새가 새롭게 이동할 수 있는 위치의 직전 위치 저장
					vis2[x][y]=1;
				}
			}
		}
		beach=q;
		while(!q.empty())q.pop();
		while(!q2.empty()){
			int x=q2.front().first;
			int y=q2.front().second;
			q2.pop();
			for(int i=0;i<4;i++){
				if(map[x+dx[i]][y+dy[i]]==-1||map[x+dx[i]][y+dy[i]]=='X') continue;
				else if(x+dx[i]==b.first&&y+dy[i]==b.second) {
					cout<<day<<endl;
					return;
				}
				else if(map[x+dx[i]][y+dy[i]]=='.'&& !vis[x+dx[i]][y+dy[i]]){
					q2.push({x+dx[i],y+dy[i]});
					vis[x+dx[i]][y+dy[i]]=1;
				}
			}
		}
		day++;
	}
}
int main() {
	cin>>n>>m;
	vector<pair<int,int>>ice;
	memset(map,-1,sizeof(map));
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			cin>>map[i][j];
			if(map[i][j]=='X') ice.push_back({i,j});
			else if(map[i][j]=='L'){
				if(a.first==0){
					a.first=i;a.second=j;
				}
				else b.first=i;b.second=j;
			}
		}
	}
	for(auto i:ice) {
		if(vis[i.first][i.second]) continue;
		dfs(i.first,i.second);
	}
	memset(vis,0,sizeof(vis));
	bfs();
}
