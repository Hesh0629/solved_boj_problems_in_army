// 난이도 낮아서 dfs 1번으로 날먹하려다가 다시 푼 문제;;

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100000
using namespace std;
int n;
int ans=0;
int a;
vector<pair<int,long long int>>tree[MAX]; // tree[node_num](node_num.pair)
void dfs(int pre,int cur,long long int w){
	if(ans<w){
		ans=w;
		a=cur;
	}
	for(int i=0;i<tree[cur].size();i++){
		if(tree[cur][i].first!=pre)
			dfs(cur,tree[cur][i].first,tree[cur][i].second+w);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		int node;
		cin>>node;
		while(1){
			int tar;
			long long int dist;
			cin>>tar;
			if(tar!=-1){
				cin>>dist;
				tree[node-1].push_back({tar-1,dist});
			}
        	else
            	break;
		}	
	}
	dfs(0,0,0);
	dfs(a,a,0);
	cout<<ans;
}
