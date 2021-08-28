// BFS의 특징 : 도달할 때 가장 첫번째로 도착했음을 보장 가능
// 더 나아가 queue에다가 여러 위치를 돌릴 수 있다.
// visit배열을 어떻게 응용할지, queue를 어떻게 관리할지를 늘 문제에 따라 맞게 생각해야한다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
#define endl '\n'
using namespace std;
char map[102][102];
int vis[102][102]; //방문할 때 비트마스크 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int cur_case=0;cur_case<n;cur_case++){
		int key=0,paper=0;
		memset(map,'*',sizeof(map));
		memset(vis,-1,sizeof(vis));
		vector<pair<int,int>>start_input;
		int w,h;
		cin>>h>>w;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				cin>>map[i][j];
				if(((i==1||i==h)||(j==1||j==w))&&map[i][j]!='*')start_input.push_back({i,j});
			}
		}
		string input;
		cin>>input;
		if(input[0]!='0'){
			for(auto i:input)
			key=key|(1<<(i-'a'));
		}
		queue<pair<int,int>>q;
		for(auto start:start_input){
			if(map[start.first][start.second]>='a'&&map[start.first][start.second]<='z'){
				key=key|(1<<(map[start.first][start.second]-'a'));
				q.push({start});
				vis[start.first][start.second]=key;
			}
			else if(map[start.first][start.second]>='A'&&map[start.first][start.second]<='Z'){
				if((1<<(map[start.first][start.second]-'A')&key)!=0){
					q.push({start});
					vis[start.first][start.second]=key;
				}
			}
			else if(map[start.first][start.second]=='$'){
				q.push({start});
				vis[start.first][start.second]=key;
				paper++;
			}
			else {
				q.push({start});
				vis[start.first][start.second]=key;
			}
		}
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				if(vis[x+dx[i]][y+dy[i]]<key||vis[x+dx[i]][y+dy[i]]==-1){
					if(map[x+dx[i]][y+dy[i]]=='*') continue;
					else if(map[x+dx[i]][y+dy[i]]>='A'&&map[x+dx[i]][y+dy[i]]<='Z'){
						if((key&(1<<(map[x+dx[i]][y+dy[i]]-'A')))==0) continue;
						else {
							q.push({x+dx[i],y+dy[i]});
							vis[x+dx[i]][y+dy[i]]=key;
						}
					}
					else if(map[x+dx[i]][y+dy[i]]>='a'&&map[x+dx[i]][y+dy[i]]<='z'){
						key=key|(1<<(map[x+dx[i]][y+dy[i]]-'a'));
						q.push({x+dx[i],y+dy[i]});
						vis[x+dx[i]][y+dy[i]]=key;
						for(auto start:start_input){
							if(vis[start.first][start.second]<key){
								if(map[start.first][start.second]>='A'&&map[start.first][start.second]<='Z'){
									if((key&(1<<(map[start.first][start.second]-'A')))!=0){
										q.push({start});
										vis[start.first][start.second]=key;
									}
								}
								else{
									q.push({start});
									vis[start.first][start.second]=key;
								}
							}
						}
					}
					else if(map[x+dx[i]][y+dy[i]]=='$'){
						q.push({x+dx[i],y+dy[i]});
						if(vis[x+dx[i]][y+dy[i]]==-1) {
							paper++;
						}
						vis[x+dx[i]][y+dy[i]]=key;
					}
					else{
						q.push({x+dx[i],y+dy[i]});
						vis[x+dx[i]][y+dy[i]]=key;
					}
				}
			}			
		}
		cout<<paper<<endl;
	}
}
