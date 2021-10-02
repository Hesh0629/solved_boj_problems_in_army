// 기본적인 외판원 순회문제. 외판원이 n개의 도시를 모두 거쳐 다시 원래 도시로 돌아옴.
// 이때 한번 방문한 도시는 방문불가. 가장 적은 비용을 출력.
// 다 좋은데 memozation을 배제하고 풀어서 겁나 해맷던 문제. dfs가 들어가면 memozation을 반드시 하자.

#include <iostream>
#include <vector>
#include <algorithm>
#include<memory.h>
#include <math.h>
#define INF 987654321
using namespace std;
vector<int>adj[16];
int w[16][1<<16]; //dp[현재 위치][현재 상태]일 때 출발 위치로 돌아오는 비용 의미. 현재 상태는 비트마스킹
long long int f_cond; // 종료 상태
int n;
int dp(int cur,int pre_cond){ //현재 위치, 현재 상태.
	int cur_cond=pre_cond|(1<<cur); //현재 상태에 cur노드에 온적 있음을 비트마스킹
	if(cur_cond==f_cond){ //만약 모든 경우를 본 경우 시작점 (0)으로 이동(가능하다면)
		if(adj[cur][0]!=0) return adj[cur][0];
		else return INF; //모든 경우를 봤지만 0으로 가는 경로가 없다면 컽
	}
	if(w[cur][cur_cond]==-1){
		w[cur][cur_cond]=INF;
		for(int i=0;i<n;i++){
			if(adj[cur][i]==0 || ((cur_cond&(1<<i))!=0 || i==cur)) 
				continue; // 갈 수 있는 경로가 없거나, 해당 정점은 이미 현재 상태에서 와봤던 정점(0제외)인 경우 컽
			w[cur][cur_cond]=min(w[cur][cur_cond],dp(i,cur_cond)+adj[cur][i]); // w[cur]["] = 현재 또는 다음 정점에서 0으로 가는 경로의 최소값 + 간선의 cost
		}
		return w[cur][cur_cond];
	}
	else
		return w[cur][cur_cond];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	f_cond=pow(2,n)-1;
	memset(w, -1,sizeof(w));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int dest;
			cin>>dest;
			adj[i].push_back(dest);
		}
	}
	int ans=dp(0,0);
	cout<<ans<<'\n';
}
