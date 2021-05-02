// 2021.05.02 일병 6호봉 A.K.A 일말
//강결합 컴퍼넌트 구하기. 강결합 그래프(모드 노든에서 모든 노드로 이동가능한 그래프의 부분 그래프)
// 1) DFS로 쓱 조사하고 조사 완료된 노드를 리스트에 추가
// 2) 간선의 방향들을 다 swap하고 리스트의 뒷부분부터 차례대로 조사
// 어제 연등시간에 공부해서 무난하게 풀긴 했는데 코드가 난잡해진 기분
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>dfs_list;
vector<int>vis(10001,0);
vector<int>comp;
vector<pair<int,int>>edge;
vector<int>adj1[10001];
vector<int>adj2[10001];
vector<int>res[10001];
vector<int>res_idx;
void dfs(int cur){
	if(vis[cur])
		return;
	vis[cur]=1;
	for(auto i:adj1[cur])
		dfs(i);
	dfs_list.push_back(cur);
}
void dfs2(int cur){
	if(vis[cur])
		return;
	vis[cur]=1;
	for(auto i:adj2[cur])
		dfs2(i);
	comp.push_back(cur);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v,e;
  cin>>v>>e;
  for(int i=0;i<e;i++){
	  int start,end;
	  cin>>start>>end;
	  adj1[start].push_back(end);
	  edge.push_back({start,end});
  }
  for(int i=1;i<=v;i++){
	  dfs(i);
  }
  for(int i=1;i<=v;i++){
	  for(auto j:adj1[i])
		  adj2[j].push_back(i);
  }
  vis.clear();
  vis.resize(10001,0);
  reverse(dfs_list.begin(),dfs_list.end());
  for(auto i:dfs_list){
	  comp.clear();
	  dfs2(i);
	  sort(comp.begin(),comp.end());
	  if(!comp.empty()){
	  res_idx.push_back(comp[0]);
	  	for(int i=1;i<comp.size();i++){
		  res[comp[0]].push_back(comp[i]);
	  	}
	  }
  }
  sort(res_idx.begin(),res_idx.end());
  cout<<res_idx.size()<<'\n';
  for(auto i:res_idx){
	  cout<<i<<" ";
	  for(auto j:res[i]){
		  cout<<j<<" ";
	  }
	  cout<<-1<<'\n';
  }
}
