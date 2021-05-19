// 모든 학생에 대하여 입력받은 x,y 둘중 하나를 만족시키면 OK
// 문제 이름은 가위바위보 이지만 실제로는 가위 또는 바위. 즉 True False 2-SAT으로 변환됨
// 모순상황은 원장님이 가위와 바위를 동시에 내는 케이스. 일반적인 2-SAT 강결합 컴포넌트 풀이로 가능
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define base 10000
using namespace std;
deque<int>dfs_order;
vector<int>comp(20002,-1);
vector<int>vis(20002,0);
vector<int>adj[20002];
vector<int>adj2[20002];
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
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	int n,m;
	cin>>n>>m;
  	for(int i=0;i<n;i++){
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
  for(int i=1;i<=m;i++){
	  dfs(i);
	  dfs(i+base);
  }
  for(int i=1;i<=m;i++){ //뒤집힌 간선리스트 제작
		for(auto j:adj[i])
	  		adj2[j].push_back(i);
		for(auto j:adj[i+base])
	  		adj2[j].push_back(i+base);
  }
  vis.assign(20002,0);
  for(auto i:dfs_order){
	  dfs2(i);
	  index++;
  }
  for(int i=1;i<=m;i++){
	  if(comp[i]==comp[i+base]){
	  	cout<<"OTL"<<'\n';
		return 0;
	  }
  }
  cout<<"^_^"<<'\n';
  return 0;
}
