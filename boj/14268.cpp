//DFS를 실행하여 pre_order순회를 돌고 이를 통해 tree를 쭉 펴주면 segtree형성 가능
// l배열에 해당 인원의 인덱스를, 그리고 r배열에 dfs를 돌면서 얻은 부하의 숫자를 더해서 관리 OK
#include <bits/stdc++.h>
#define endl '\n'
#define INF 100001
using namespace std;
int n,m,idx;
long long int base;
vector<int>adj[INF];
vector<int>l(INF),r(INF),pre_order;
vector<int>segtree;
int dfs(int cur){
	l[cur]=idx++;
	pre_order.push_back(cur);
	int child=0;
	for(auto i:adj[cur])
		child+=dfs(i);
	r[cur]=l[cur]+child;
	return child+1;
}
void update(int person,int w){
	int x=l[person]+base, y=r[person]+base;
	while(x<=y){
		if(x%2)segtree[x++]+=w;
		if(y%2==0)segtree[y--]+=w;
		x/=2; y/=2;
		if(x==y){
			segtree[x]+=w;
			return;
		}
	}
	if(x==y)
		segtree[x]+=w;
}
void query(int num){
	int x=0, y=base-1, target=l[num], idx=1;
	while(x<=y){
		int half=(x+y)/2;
		if(segtree[idx]&&idx<base){
			segtree[2*idx]+=segtree[idx];
			segtree[2*idx+1]+=segtree[idx];
			segtree[idx]=0;
		}
		if(x==y) {
			cout<<segtree[idx]<<endl;
			return;
		}
		else if(target<=half){
			y=half;
			idx=idx*2;
		}
		else{
			x=half+1;
			idx=idx*2+1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int input;
		cin>>input;
		if(input!=-1) adj[input].push_back(i);
	}
	for(base=1;base<=n;base*=2);
	segtree.resize(base*2+1);
	idx=0;
	dfs(1);
	for(int T=0;T<m;T++){
		int opt;
		cin>>opt;
		if(opt==1){
			int i,w;
			cin>>i>>w;
			update(i,w);
		}
		else{
			int i;
			cin>>i;
			query(i);
		}
	}
	return 0;
}
