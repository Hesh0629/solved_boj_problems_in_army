#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define endl '\n'
using namespace std;
vector<int>adj[1001];
vector<int>indegree(1001,0);
vector<int>ans;
int vis[1001]={0};
int check[1001][1001]={0};
int no_answer=0;
//진입 차수가 없는 노드에 대해 dfs진행 이후 dfs순서를 저장하고 뒤집으면 위상정렬 끝
void dfs(int cur,vector<int> history){
	if(history[cur]){ // 현재 DFS시행중 (가지 기준임) 이전에 방문한 노드라면
		no_answer=1;
		return;
	}
	if(vis[cur])
		return;
	else {
		vis[cur]=1;
		history[cur]=1;
	}
	for(auto i:adj[cur]) dfs(i,history);
	ans.push_back(cur);
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int input,num,cur,pre=0;
		cin>>num;
		for(int j=0;j<num;j++){
			cin>>input;
			if(pre==0){
				pre=input;
				cur=input;
			}
			else{
				pre=cur;
				cur=input;
				if(check[pre][cur]) continue;
				adj[pre].push_back(cur);
				indegree[cur]++;
				check[pre][cur]++;
			}
		}
	}
	vector<int>start;
	for(int i=1;i<=n;i++){ //진입차수가 0인 노드들을 저장
		if(indegree[i]==0) start.push_back(i);
	}
	for(auto i:start){
		vector<int>his(1001,0); // 사이클 체크를 잘 하자,,,,
		dfs(i,his);
	}
	if(ans.size()<n||no_answer){ // 만약 사이클이 발생하거나 진입차수가 0인 모든 노드로 DFS를 돌렸음에도 안된 부분이 있는 경우 위상정렬X
		cout<<0<<endl;
		return 0;
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)
		cout<<i<<endl;
}
