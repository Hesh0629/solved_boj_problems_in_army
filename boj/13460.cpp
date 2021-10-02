#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int ddx[3]={-1,0,1},ddy[3]={-1,0,1};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n,rx,bx,ry,by,tx,ty,prex=0,prey=0;
	cin>>m>>n;
	char map[10][10]={0};
	int blue_cnt[10][10]={0};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]=='R'){
				rx=i;
				ry=j;
			}
			else if(map[i][j]=='B'){
				bx=i;
				by=j;
			}
			else if(map[i][j]=='O'){
				tx=i;
				ty=j;
			}
		}
	}
	queue<pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,int>>>q;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(ddx[i]*ddy[j]==0&&ddx[i]!=ddy[j]&&(map[rx+ddx[i]][ry+ddy[j]]!='#'||map[bx+ddx[i]][by+ddy[j]]!='#')) q.push({{{rx,ry},{bx,by}},{{ddx[i],ddy[j]},1}});
		}
	}
	int vis[10][10][3][3]={0};
	while(!q.empty()){
		int curx=q.front().first.first.first;
		int cury=q.front().first.first.second;
		int dx=q.front().second.first.first;
		int dy=q.front().second.first.second;
		int bx=q.front().first.second.first;
		int by=q.front().first.second.second;
		int time=q.front().second.second;
		q.pop();
		int red=0,blue=0;
		//cout<<curx<<" "<<cury<<" "<<bx<<" "<<by<<endl;
		while(1){
			blue_cnt[bx][by]=time;
			if(bx==tx&&by==ty) break;
			if(map[bx+dx][by+dy]!='#'){
				bx+=dx;
				by+=dy;
				blue++;
			}
			else break;
		}
		if(bx==tx&&by==ty) continue;
		while(1){
			vis[curx][cury][(dx<0)?2:dx][(dy<0)?2:dy]=time;
			if(curx==tx&&cury==ty) break;
			if(map[curx+dx][cury+dy]!='#'){
				curx+=dx;
				cury+=dy;
				red++;
			}
			else break;
		}
		if(curx==tx&&cury==ty) break;
		if(curx==bx&&cury==by){
			if(red<blue){
				blue_cnt[bx][by]=0;
				bx-=dx;
				by-=dy;
			}
			else{
				vis[curx][cury][(dx<0)?2:dx][(dy<0)?2:dy]=0;
				curx-=dx;
				cury-=dy;
			}
		}
		if(time==10) continue;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(ddx[i]*ddy[j]==0&&ddx[i]!=ddy[j]&&(map[curx+ddx[i]][cury+ddy[j]]!='#'||map[bx+ddx[i]][by+ddy[j]]!='#')&&(dx*ddx[i]!=-1&&dy*ddy[j]!=-1)&&dx!=ddx[i]&&dy!=ddy[j]){ //논리식 주의
					 q.push({{{curx,cury},{bx,by}},{{ddx[i],ddy[j]},time+1}});
				}
			}
		}
	}
	int no_ans=1;
	int ans=987654321;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(vis[tx][ty][i][j]!=0) {
				no_ans=0;
				ans=min(ans,vis[tx][ty][i][j]);
			}
		}
	}
	if(no_ans||ans>10)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
