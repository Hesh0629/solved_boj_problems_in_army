// 문제 조건좀 잘 읽자 (거리가 같은경우 위쪽(x가 적은순), 같을경우 y가 적은 순서) -> priority_queue에서 greater쓰면 한번에 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
//#define endl '\n'
using namespace std;
int map[22][22]={0};
int vis[22][22]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1}; 
int main() {
	int n,sx,sy;
	cin>>n;
	memset(map,-1,sizeof(map));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			cin>>map[i][j];
			if(map[i][j]==9){
				sx=i;sy=j;
				map[i][j]=0;
			}
		}
	}
	int time=0,last=0;
	priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>>q,next,done;
	q.push({{sx,sy},{2,0}}); // x y size 먹은수
	vis[sx][sy]=1;
	while(1){
		while(!q.empty()){
			auto i=q.top();
			q.pop();
			int x=i.first.first, y=i.first.second, size=i.second.first, eat=i.second.second;
			for(int i=0;i<4;i++){
				if(map[x+dx[i]][y+dy[i]]!=-1 && !vis[x+dx[i]][y+dy[i]]){
					if(map[x+dx[i]][y+dy[i]]==0) {
						next.push({{x+dx[i],y+dy[i]},{size,eat}});
						vis[x+dx[i]][y+dy[i]]=1;
					}
					else if(map[x+dx[i]][y+dy[i]]<size){
						last=time+1;
						vis[x+dx[i]][y+dy[i]]=1;
						if(eat+1==size) {
							done.push({{x+dx[i],y+dy[i]},{size+1,0}});
						}
						else
							done.push({{x+dx[i],y+dy[i]},{size,eat+1}});
					}
					else if(map[x+dx[i]][y+dy[i]]==size) {
						next.push({{x+dx[i],y+dy[i]},{size,eat}});
						vis[x+dx[i]][y+dy[i]]=1;
					}
				}
			}
		}
		if(done.empty()) q=next;
		else {
			q.push(done.top());
			memset(vis,0,sizeof(vis));
			map[done.top().first.first][done.top().first.second]=0;
		}
		if(q.empty()) break;
		while(!done.empty()) done.pop();
		while(!next.empty()) next.pop();
		time++;
	}
	cout<<last<<endl;
}
