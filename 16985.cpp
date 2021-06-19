// 킹론상 전수 조사가 가능하다.
// 층을 배열하는 가짓수 = 5! = 120, 모든 층에서 회전할 수 있는 경우의 수의 합 = 4^5
// BFS의 시간복잡도 O(V^2), V=5^3, 따라서 다 곱하면 120 * 2^10 * 5^6 = 1.92 * 10^9
// 따라서 2초 이내에 간당간당하게 통과가능
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 10000000
using namespace std;
int able[5][4][5][5]={0}; //level,rot,x,y
int input[5][4][5][5]={0}; //level,rot,x,y
int bfs(int l1,int l2,int l3,int l4,int l5){
	int rot[5]={l1,l2,l3,l4,l5};
	if(input[0][l1][0][0]==0)
		return INF;
	int vis [5][5][5];
	int ans [5][5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				 ans[i][j][k]=INF;
				 vis[i][j][k]=0;
			}
		}
	}
	ans[0][0][0]=0;
	queue<pair<int,pair<int,int>>>q;
	q.push({0,{0,0}});
	int cur_x,cur_y,cur_z;
	while(!q.empty()){
		cur_x=q.front().second.first;
		cur_y=q.front().second.second;
		cur_z=q.front().first;
		q.pop();
		if(vis[cur_z][cur_x][cur_y]) continue;
		// x방향으로 줄일 수 있는지 검사
		if(cur_x+1<5){
			if(input[cur_z][rot[cur_z]][cur_x+1][cur_y] && ans[cur_z][cur_x+1][cur_y]>ans[cur_z][cur_x][cur_y]+1){
				ans[cur_z][cur_x+1][cur_y]=ans[cur_z][cur_x][cur_y]+1;
				q.push({cur_z,{cur_x+1,cur_y}});
			}
		}
		if(cur_x-1>=0){
			if(input[cur_z][rot[cur_z]][cur_x-1][cur_y] && ans[cur_z][cur_x-1][cur_y]>ans[cur_z][cur_x][cur_y]+1){
				ans[cur_z][cur_x-1][cur_y]=ans[cur_z][cur_x][cur_y]+1;
				q.push({cur_z,{cur_x-1,cur_y}});
			}
		}
		// y방향으로 줄일 수 있는지 검사
		if(cur_y+1<5){
			if(input[cur_z][rot[cur_z]][cur_x][cur_y+1] && ans[cur_z][cur_x][cur_y+1]>ans[cur_z][cur_x][cur_y]+1){
				ans[cur_z][cur_x][cur_y+1]=ans[cur_z][cur_x][cur_y]+1;
				q.push({cur_z,{cur_x,cur_y+1}});
			}
		}
		if(cur_y-1>=0){
			if(input[cur_z][rot[cur_z]][cur_x][cur_y-1] && ans[cur_z][cur_x][cur_y-1]>ans[cur_z][cur_x][cur_y]+1){
				ans[cur_z][cur_x][cur_y-1]=ans[cur_z][cur_x][cur_y]+1;
				q.push({cur_z,{cur_x,cur_y-1}});
			}
		}
		// z방향으로 줄일 수 있는지 검사
		if(cur_z+1<5){
			if(input[cur_z+1][rot[cur_z+1]][cur_x][cur_y] && ans[cur_z+1][cur_x][cur_y]>ans[cur_z][cur_x][cur_y]+1){
				ans[cur_z+1][cur_x][cur_y]=ans[cur_z][cur_x][cur_y]+1;
				q.push({cur_z+1,{cur_x,cur_y}});
			}
		}
		if(cur_z-1>=0){
			if(input[cur_z-1][rot[cur_z-1]][cur_x][cur_y] && ans[cur_z-1][cur_x][cur_y]>ans[cur_z][cur_x][cur_y]+1){
				ans[cur_z-1][cur_x][cur_y]=ans[cur_z][cur_x][cur_y]+1;
				q.push({cur_z-1,{cur_x,cur_y}});
			}
		}
	}
	//cout<<ans[4][4][4]<<endl;
	return ans[4][4][4];
}
int main() {
	for(int level=0;level<5;level++){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++) cin>>able[level][0][i][j];
		}
	}
	for(int level=0;level<5;level++){
		for(int rot=1;rot<4;rot++){
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++)
					able[level][rot][i][j]=able[level][rot-1][j][4-i];
			}
		}
	}
	int ans=INF;
	vector<int>per(5);
	for(int i=0;i<5;i++) per[i]=i;
	do{
		//cout<<per[0]<<per[1]<<per[2]<<per[3]<<per[4]<<endl;
		for(int level=0;level<5;level++){
			for(int rot=0;rot<4;rot++){
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++)
						input[level][rot][i][j]=able[per[level]][rot][i][j];
				}
			}
		}
		for(int l1=0;l1<4;l1++){
			for(int l2=0;l2<4;l2++){
				for(int l3=0;l3<4;l3++){
					for(int l4=0;l4<4;l4++){
						for(int l5=0;l5<4;l5++)
							ans=min(ans,bfs(l1,l2,l3,l4,l5));
				}
			}	
		}	
	}
	}while(next_permutation(per.begin(),per.end()));
	if(ans==INF) ans=-1;
	cout<<ans<<endl;
}
