// 2206 벽 부수고 지나가기와 유사하지만 jump의 경우 visit 배열을 따로 파줘야 한다는 것을 떠올려야한다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int k,w,h, init[210][210],vis[210][210][31];
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int jx[8]={-1,-2,-2,-1,1,2,2,1}, jy[8]={-2,-1,1,2,2,1,-1,-2};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(init,-1,sizeof(init));
  memset(vis,-1,sizeof(vis));
  cin>>k;
  cin>>w>>h;
  for(int i=2;i<=h+1;i++){
    for(int j=2;j<=w+1;j++) cin>>init[i][j];
  }
  queue<pair<pair<int,int>,int>>q;
  q.push({{2,2},0});
  vis[2][2][0]=0;
	if(w==1&&h==1){ //BFS문제만 유난히 시작지점에서 끝나는 상황을 놓친다.
		cout<<0<<endl;
		return 0;
	}
  while(!q.empty()){
    int x=q.front().first.first,y=q.front().first.second,jump=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      if(init[x+dx[i]][y+dy[i]]==-1||vis[x+dx[i]][y+dy[i]][jump]!=-1||init[x+dx[i]][y+dy[i]]==1) continue;
      vis[x+dx[i]][y+dy[i]][jump]=vis[x][y][jump]+1;
      q.push({{x+dx[i],y+dy[i]},jump});
			if(x+dx[i]==h+1&&y+dy[i]==w+1){
				cout<<vis[x+dx[i]][y+dy[i]][jump]<<endl;
				return 0;
			}
    }
    if(jump<k){
      for(int i=0;i<8;i++){
      	if(init[x+jx[i]][y+jy[i]]==-1||vis[x+jx[i]][y+jy[i]][jump+1]!=-1||init[x+jx[i]][y+jy[i]]==1) continue;
				vis[x+jx[i]][y+jy[i]][jump+1]=vis[x][y][jump]+1;
      	q.push({{x+jx[i],y+jy[i]},jump+1}); 
				if(x+jx[i]==h+1&&y+jy[i]==w+1){
					cout<<vis[x+jx[i]][y+jy[i]][jump+1]<<endl;
					return 0;
				}
    	}
  	}
	}
	cout<<-1<<endl;
}
