// 틀린 점 1. 방문체크는 현재 지점이 아닌 다음 지점으로 진행. 안그러면 queue에서 중복 가능
// 틀린 점 2. 열쇠를 주울때 테스트 케이스 체크
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
#define INF 987654321
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
	int n,m;
	cin>>n>>m;
	char map[52][52]={0};
	char vis[128][52][52]={0};
	memset(map,'#',sizeof(map));
	int sx,sy;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
			if(map[i][j]=='0'){
				sx=i; sy=j;
			}
		}
	}
	queue<pair<pair<char,char>,pair<int,int>>>q; // x, y, time, key(bitmask)
	q.push({{sx,sy},{0,0}});
	vis[0][sx][sy]=1;
	while(!q.empty()){
		auto i=q.front(); 
		q.pop();
		int x=i.first.first,y=i.first.second,time=i.second.first,key=i.second.second;
		if(map[x][y]=='1') {
			cout<<time<<endl;
			return 0;
		}
		for(int i=0;i<4;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if(!vis[key][tx][ty]){
				if(map[tx][ty]>='a'&&map[tx][ty]<='f'){
					int next_key=key;
					if((next_key&(1<<(map[tx][ty]-'a')))==0){
						int next_key=(key|1<<(map[tx][ty]-'a'));
						if(!vis[next_key][tx][ty]&&!vis[key][tx][ty]){
							q.push({{tx,ty},{time+1,next_key}});
							vis[key][tx][ty]=1;
							vis[next_key][tx][ty]=1;
						}
					}
					else q.push({{tx,ty},{time+1,key}});
				}
				else if(map[tx][ty]>='A'&&map[tx][ty]<='F'){
					if((key&(1<<(map[tx][ty]-'A')))!=0){
						q.push({{tx,ty},{time+1,key}});
						vis[key][tx][ty]=1;
					}
				}
				else if(map[tx][ty]=='.'||map[tx][ty]=='0'){
					q.push({{tx,ty},{time+1,key}});
					vis[key][tx][ty]=1;
				}
				else if(map[tx][ty]=='1'){
					cout<<time+1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
