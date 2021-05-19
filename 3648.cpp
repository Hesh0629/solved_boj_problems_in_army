// 우선 심사위원이 의심하는 상황 (자신의 두 제출중 어느것도 채택되지 않는 경우) 즉, 2-SAT Fail 케이스인경우 -> 모순 발생으로 치환
// 그런다음 진리값을 매기기 시작할 때, 상근이의 진리값이 먼저 조사되어 false로 설정되는 경우, 즉 상근이가 떨어지도록 매겨지는 경우 fail
// 매겨지는 순서가 ㄱ상근보다 앞설경우임.
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stdio.h>
#define base 1000
using namespace std;
deque<int>dfs_order;
vector<int>comp(2002,-1);
vector<int>vis(2002,0);
vector<int>adj[2002];
vector<int>adj2[2002];
vector<int>scc[2002];
vector<int>scc_ans(2002,-1);
int index=0;
void dfs(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj[cur])
		dfs(i);
	dfs_order.push_front(cur);
}
void dfs2(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj2[cur])
		dfs2(i);
	comp[cur]=index;
	scc[index].push_back(cur);
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	int n,m;
	while(cin>>n>>m){
		index=0;
		comp.assign(2002,-1);
		scc_ans.assign(2002,-1);
		vis.assign(2002,0);
		dfs_order.clear();
		for(int i=0;i<2002;i++){
			adj[i].clear();
			adj2[i].clear();
			scc[i].clear();
		}
  		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			if(x>0&&y>0){
				adj[x+base].push_back(y);
				adj[y+base].push_back(x);
			}
			else if(x>0&&y<0){
				adj[x+base].push_back(-y+base);
				adj[-y].push_back(x);
			}
			else if(x<0&&y>0){
				adj[-x].push_back(y);
				adj[y+base].push_back(-x+base);
			}
			else{
				adj[-x].push_back(-y+base);
				adj[-y].push_back(-x+base);
			}
  		}
 	 // (상근 V 상근) 항 추가. 이러면 상근이는 참이여야 문제조건이 만족됨
  	adj[1+base].push_back(1); 
  	for(int i=1;i<=n;i++){
		dfs(i);
	  	dfs(i+base);
  	}
  	for(int i=1;i<=n;i++){ //뒤집힌 간선리스트 제작
		for(auto j:adj[i])
	  		adj2[j].push_back(i);
		for(auto j:adj[i+base])
	  		adj2[j].push_back(i+base);
  	}
  	vis.assign(2002,0);
	//reverse(dfs_order.begin(),dfs_order.end());
  	for(auto i:dfs_order){
	  	dfs2(i);
	  	if(scc[index].size()!=0) index++;
  	}
	//심사위원이 의심하는 경우 (모순발생)
	int flag=0;
  	for(int i=1;i<=n;i++){
	  	if(comp[i]==comp[i+base])
	  		flag=1;
  	}
	if(flag){
	  cout<<"no"<<'\n';
	  continue;
	}

	int id=0;
	for(int i=0;i<=index-1;i++){
		for(auto j:scc[i]){
			scc_ans[j]=id++; //조사 순서를 매긴다. (2-SAT의 bool 값 지정시 조사 순서)
		}
	}
	if(scc_ans[1]<scc_ans[1+base]) // 1이 1+base보다 먼저 조사된다면 1은 false로 설정되므로 상근이가 떨어진다.
	  cout<<"no"<<'\n';
	else
		cout<<"yes"<<'\n';
  }
  return 0;
}
