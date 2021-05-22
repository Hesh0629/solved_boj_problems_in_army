// 각 도로의 방향 = 불리언 변수 취급 가능 (왼쪽 오른쪽 또는 위 아래 둘중 하나 )
// 가로 세로의 방향이 노드인 그래프에 대하여 각각 SCC구하기. 모순발생 => 도로들에 방향성 부여 X
// 여기서 경로가 두가지인데 둘중 하나가 안된다면 나머지 하나가 반드시 되야하므로 4개의 항이 등장. 이를 adj에 추가하여 함의 그래프 

#include <iostream>
#include <vector>
#include <algorithm>
#define base 1000
#define sero 2000
using namespace std;
vector<int>adj[4001];
vector<int>adj2[4001];
vector<int>dfs_order;
vector<int>comp(4001,-1);
vector<int>vis(4001,0);
int index=0;
void clear(){
	dfs_order.clear();
	comp.assign(4001,-1);
	index=0;
	for(int i=1;i<=4000;i++){
		adj[i].clear();
		adj2[i].clear();
	}
}
void dfs1(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj[cur])
		dfs1(i);
	dfs_order.push_back(cur);
}
void dfs2(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj2[cur])
		dfs2(i);
	comp[cur]=index;
}
int main() {
  	int t,n,m,k;
  	cin>>t;
  	for(int t_case=0;t_case<t;t_case++){
		clear();
	  	cin>>n>>m>>k;
	  	for(int i=0;i<k;i++){
			int x1,y1,x2,y2;
		  	cin>>x1>>y1>>x2>>y2;
			y1+=sero;
			y2+=sero;
		  	if(x1==x2&&y1==y2)
		  		continue;
			else if(x1==x2){
				if(y1<y2)
					adj[x1+base].push_back(x1);
				else
					adj[x1].push_back(x1+base);
			}
			else if(y1==y2){
				if(x1<x2)
					adj[y1+base].push_back(y1);
				else
					adj[y1].push_back(y1+base);
			}
			else{
				if(y1<y2){ //오른쪽으로 이동해야 할 시 (ㄱx1 -> x2, y1)
					adj[x1+base].push_back(x2);
					adj[x2+base].push_back(x1);
					if(x1<x2){ //아래로 가야할 시
						adj[x1+base].push_back(y1);
						adj[x2+base].push_back(y2);
					}
					else{ //위로 가야할 시
						adj[x1+base].push_back(y1+base);
						adj[x2+base].push_back(y2+base);
					}	
				}
				else{ //왼쪽으로 이동해야 할 시
					adj[x1].push_back(x2+base);
					adj[x2].push_back(x1+base);
					if(x1<x2){ //아래로 가야할 시
						adj[x1].push_back(y1);
						adj[x2].push_back(y2);
					}
					else{ //위로 가야할 시
						adj[x1].push_back(y1+base);
						adj[x2].push_back(y2+base);
					}	
				}
				if(x1<x2){ //아래로 가야할 시
					adj[y1+base].push_back(y2);
					adj[y2+base].push_back(y1);
					if(y1<y2){ //오른쪽로 가야할 시     -> (살다살다 여기서 틀려서 시간 다잡아 먹을줄 몰랐다.) <-
						adj[y1+base].push_back(x1);
						adj[y2+base].push_back(x2);
					}
					else{ //왼쪽으로 가야할 시
						adj[y1+base].push_back(x1+base);
						adj[y2+base].push_back(x2+base);
					}
				}
				else{ //위로 가야할 시
					adj[y1].push_back(y2+base);
					adj[y2].push_back(y1+base);
					if(y1<y2){ //오른쪽로 가야할 시
						adj[y1].push_back(x1);
						adj[y2].push_back(x2);
					}
					else{ //왼쪽으로 가야할 시
						adj[y1].push_back(x1+base);
						adj[y2].push_back(x2+base);
					}
				}
			}
		}
		//입력 종료, dfs시행하여 dfs순서 구하기.
		vis.assign(4001,0);
		for(int i=1;i<=n;i++){
			dfs1(i);
			dfs1(i+base);
		}
		for(int i=1;i<=m;i++){
			dfs1(i+sero);
			dfs1(i+sero+base);
		}
		//뒤집힌 간선 리스트 제작
		for(int i=1;i<=n;i++){
			for(auto j:adj[i])
				adj2[j].push_back(i);

			for(auto j:adj[i+base])
				adj2[j].push_back(i+base);
		}
		for(int i=1;i<=m;i++){
			for(auto j:adj[i+sero])
				adj2[j].push_back(i+sero);

			for(auto j:adj[i+sero+base])
				adj2[j].push_back(i+sero+base);
		}
		reverse(dfs_order.begin(),dfs_order.end());
		vis.assign(4001,0);
		for(auto i:dfs_order){
			dfs2(i);
			index++;
		}
		int ans=1;
		for(int i=1;i<=n;i++) {
			if(comp[i]==comp[i+base])
				ans=0;
		}
		for(int i=1;i<=m;i++){
			if(comp[i+sero]==comp[i+sero+base])
				ans=0;
		}
		if(ans)
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
  }
  return 0;
}
