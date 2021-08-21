#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n,m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	char map[1002][1002]; //틀린부분1 : 처음에 크기를 1001로 뒀다가 망했다.
	memset(map,-1,sizeof(map));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
		}
	}
	short int vis[1001][1001][2]={0};
	queue<pair<pair<short int,short int>,pair<int,char>>>list;
	list.push({{1,1},{1,0}});
	vis[1][1][0]=1;
	if(n==1&&m==1) { //생각치 못했던 케이스. 예외로 빼줬다.
		cout<<1<<endl;
		return 0;
	}
	while(!list.empty()){
		short int x=list.front().first.first,y=list.front().first.second;
		int dist=list.front().second.first;
		char state=list.front().second.second;
		list.pop();
		for(int i=0;i<4;i++){
			if(map[x+dx[i]][y+dy[i]]==-1) continue;
			if(x+dx[i]==n&&y+dy[i]==m){
				cout<<dist+1<<endl;
				return 0;
			}
			if(state==1&&map[x+dx[i]][y+dy[i]]=='1') continue;
			else if(state==0&&map[x+dx[i]][y+dy[i]]=='1'){
				if(vis[x+dx[i]][y+dy[i]][1]) continue;
				else {
					list.push({{x+dx[i],y+dy[i]},{dist+1,1}});
					vis[x+dx[i]][y+dy[i]][1]=1;
				}
			}
			else if(!vis[x+dx[i]][y+dy[i]][state]) {
				list.push({{x+dx[i],y+dy[i]},{dist+1,state}});
				vis[x+dx[i]][y+dy[i]][state]=1;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
