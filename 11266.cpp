#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>adj[10001];
vector<int>art(10001,0);
vector<int>dfs_list(10001,0); //dfs를 돌면서 돈 순서대로(dfs스패닝 트리) 번호를 매김
// 여기서 조사하는 정점에 대하여 자신보다 늦게 탐색되는 정점들에서 dfs를 돌렸을때 나오는 가장 작은 번호가 자신과 같거나 크다면(즉, 무조건 자신을 거쳐야 앞 번호를 탐색할 수 있다면) 단절점
// 자식들에대해 dfs를 실행할 때 가장 작은 번호를 물어오도록 시키자
// 단 처음 dfs를 돌리는 곳(루트)는 스패닝 트리에서 자식이 둘이면 단절점이 됨
// 이 문제에만 1시간 이상을 박았는데 원인은 인터넷 단절이였다. 하...
int root;
int cnt=0;
int dfs_idx=1;
int dfs(int  cur){ // 함수의 return 값은 자식들이 물어오는 가장 작은 dfs_list 값
	if(!dfs_list[cur])
		dfs_list[cur]=dfs_idx++;
	int child=0;
	int min_val = dfs_list[cur];
	for(auto i : adj[cur]){
		if(!dfs_list[i]){
			child++;
			int res=dfs(i);
			min_val=min(min_val, res); // 너 왜 지워졌었니...?
			if(res >= dfs_list[cur] && cur!=root && !art[cur]){
				art[cur]=1;
				cnt++;
			}
		}
		else
		    min_val=min(min_val, dfs_list[i]);
	}
	if(cur==root&&child>=2){
		art[root]=1;
		cnt++;
	}
	return min_val;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=v;i++){
		if(!dfs_list[i]){
			root=i;
			dfs(i);
		}
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=v;i++){
		if(art[i])
			cout<<i<<" ";
	}
	return 0;
}
