//queue 관리를 잘하자! 그리고 논리식 틀리지 말기
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int r,c,sx,sy,tx,ty;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int main() {
	cin>>r>>c;
	char map[52][52];
	int vis[52][52];
	int w[52][52];
	queue<pair<int,int>>water,q,next,next_water;
	memset(map,-1,sizeof(map));
	memset(vis,0,sizeof(vis));
	memset(w,0,sizeof(w));
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>map[i][j];
			if(map[i][j]=='S'){
				sx=i;sy=j;
			}
			else if(map[i][j]=='D'){
				tx=i;ty=j;
			}
			else if(map[i][j]=='*') {
				water.push({i,j});
				w[i][j]=1;
			}
		}
	}
	int time=1;
	q.push({sx,sy});
	vis[sx][sy]=1;
	for(time=1;;time++){
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			while(!water.empty()){
				int wx=water.front().first,wy=water.front().second;
				water.pop();
				for(int i=0;i<4;i++){
					if(!(w[wx+dx[i]][wy+dy[i]])&&!(wx+dx[i]==tx&&wy+dy[i]==ty)&&map[wx+dx[i]][wy+dy[i]]!='X'&&map[wx+dx[i]][wy+dy[i]]!=-1) { //논리식 조심
						next_water.push({wx+dx[i],wy+dy[i]});
						map[wx+dx[i]][wy+dy[i]]='*';
						w[wx+dx[i]][wy+dy[i]]=1;
					}
				}
			}
			for(int i=0;i<4;i++){
				if(!vis[x+dx[i]][y+dy[i]]&&map[x+dx[i]][y+dy[i]]!=-1){
					if(map[x+dx[i]][y+dy[i]]=='D'){
						cout<<time<<endl;
						return 0;
					}
					else if(map[x+dx[i]][y+dy[i]]=='.'){
						vis[x+dx[i]][y+dy[i]]=1;
						next.push({x+dx[i],y+dy[i]});
					}
				}
			}
		}
		if(next.empty()){
			cout<<"KAKTUS"<<endl;
			return 0;
		}
		else{
			q=next;
			water=next_water;
			while(!next_water.empty())next_water.pop();
			while(!next.empty())next.pop();
		}
	}
}
