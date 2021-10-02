//문제 해석때문에 해멘 문제. 사실 (음수 사이클이 있다) = (그 정점에서 시간 역행 가능)
//결과적으로 벨만 포드를 이용하여 음수 사이클을 찾는게 목적이지 실제 dist가 음수가 되는건 굳이 찾을 필요가 없는 문제 
//생각해보니 벨만 포드는 음수인 간선이 있을 때 음수 사이클 여부를 찾는데도 사용이 됬었다.
#include <iostream>
#include <queue>
#include <vector>
#define INF 100000000
using namespace std;
vector<pair<pair<int,int>,int>>adj;
int n,m,w;
void bell(int start){
	vector<int>dist(n+1,INF);
	dist[start]=0;
	for(int i=0;i<n-1;i++){
		for(auto k:adj){
			int from=k.first.first, to=k.first.second, time=k.second;
			if(dist[to]>dist[from]+time)
				dist[to]=dist[from]+time;
		}
	}
	for(auto k:adj){
		int from=k.first.first, to=k.first.second, time=k.second;
		if(dist[to]>dist[from]+time){
			cout<<"YES"<<'\n';
			return;
		}
	}
	cout<<"NO"<<'\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int TC;
  cin>>TC;
  for(int i=0;i<TC;i++){
	  cin>>n>>m>>w;
	  adj.clear();
	  for(int j=0;j<m;j++){
		  int s,e,t;
		  cin>>s>>e>>t;
		  adj.push_back({{s,e},t});
		  adj.push_back({{e,s},t});
	  }
	   for(int j=0;j<w;j++){
		  int s,e,t;
		  cin>>s>>e>>t;
		  adj.push_back({{s,e},-t});
	  }
	 bell(1);
  }
  return 0;
}
