#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int map[102][102]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j]=1;
		}
	}
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		map[x][y]=2;
	}
	int l;
	cin>>l;
	deque<pair<int,char>>dq;
	deque<pair<int,int>>tail;
	int time;
	char dir;
	for(int i=0;i<l;i++){
		cin>>time>>dir;
		dq.push_back({time,dir});
	}
	int cur=0,x=1,y=1,dir_x=0,dir_y=1;
	map[x][y]=3;
	tail.push_back({1,1});
	while(1){ // 0=wall, 1=empty, 2=apple, 3=self
		cur++;
		if(map[x+dir_x][y+dir_y]==1){
			map[tail.front().first][tail.front().second]=1;
			tail.pop_front();
		}
		if(map[x+dir_x][y+dir_y]!=0&&map[x+dir_x][y+dir_y]!=3){
			map[x+dir_x][y+dir_y]=3;
			tail.push_back({x+dir_x,y+dir_y});
		}
		else break;
		x=x+dir_x;
		y=y+dir_y;
		if(!dq.empty()&&dq.front().first==cur){
			if(dq.front().second=='L'){
				if(dir_x!=0) {
					if(dir_x==1) dir_y=1;
					else dir_y=-1;
					dir_x=0;
				}
				else{
					if(dir_y==1) dir_x=-1;
					else dir_x=1;
					dir_y=0;
				}
			}
			else{
				if(dir_x!=0) {
					if(dir_x==1) dir_y=-1;
					else dir_y=1;
					dir_x=0;
				}
				else{
					if(dir_y==1) dir_x=1;
					else dir_x=-1;
					dir_y=0;
				}
			}
			dq.pop_front();
		}
	}
	cout<<cur;
}
