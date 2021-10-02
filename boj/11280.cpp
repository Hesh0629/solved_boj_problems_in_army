// 각 x1, x2에 대하여 생기는 2개의 관계식을 방향그래프로 표현하고 코사라주 시행이후
// 같은 컴포넌트에 x, not x가 같이있다면 false, 다 통과하면 true

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define base 10000
using namespace std;
vector<int>adj[20002];
vector<int>adj2[20002];
vector<int>vis(20002,0); // 1~10000: 양수, 10001~20000: 음수
vector<int>dfs_order;
vector<int>same_comp(20002,-1);
int index=0;
void dfs(int cur){
	if(vis[cur])
		return;
	vis[cur]=1;
	for(auto i:adj[cur])
		dfs(i);
	dfs_order.push_back(cur); //뒷목 잡을뻔 했다. dfs를 다 마친 시점을 dfs_order 넣어야한다. 이부분 틀리지말자
}
void dfs2(int cur){
	if(vis[cur])
		return;
	vis[cur]=1;
	same_comp[cur]=index;
	for(auto i:adj2[cur])
		dfs2(i);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(x>0&&y>0){ // x or y		
			adj[x+base].push_back(y);
			adj[y+base].push_back(x);
		}
		else if(x>0&&y<0){ // x or not y
			adj[x+base].push_back(-y+base);
			adj[-y].push_back(x);
		}
		else if(x<0&&y>0){ // not x or y
			adj[-x].push_back(y);
			adj[y+base].push_back(-x+base);
		}
		else{ // not x or not y
			adj[-x].push_back(-y+base);
			adj[-y].push_back(-x+base);
		}
	}
	
	//강결합 컴포넌트 형성을 위하여 dfs시작 + 뒤집힌 인접간선 리스트 제작;
	for(int i=1;i<=n;i++){
		dfs(i);
		dfs(i+base);
		for(auto k:adj[i])
			adj2[k].push_back(i);
		for(auto k:adj[i+base])
			adj2[k].push_back(i+base);
	}

	// dfs_order 거꾸로 dfs시작
	reverse(dfs_order.begin(),dfs_order.end());
	vis.clear();
	vis.resize(20002,0);
	for(auto i:dfs_order){
		dfs2(i);
		index++; //같은 comp에 대하여 같은 index를 매김
	}
	for(int i=1;i<=n;i++){
		if(same_comp[i]==same_comp[i+base]){ // x와 ㄱx가 같은 comp인지 확인
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	return 0;
}
