//비유향 그래프 (Directed Acyclic Graph, DAG)의 중요한 위상 정렬을 하는 방법
//정신전력 자료는 잊어먹어도 이건 잊으면 안된다.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>adj[32001];
vector<int>jin_ip(32001,0);
vector<int>vis(32001,0);
vector<int>ans;
queue<int>q;
int main() {
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
	  int a,b;
	  cin>>a>>b;
	  adj[a].push_back(b);
	  jin_ip[b]++; //각 노드의 진입 차수를 기록한다.
  }
  for(int i=1;i<=n;i++){
	  if(jin_ip[i]==0){
		  q.push(i); //큐에는 진입 차수가 0인 노드들을 저장
	  }
  }
  while(!q.empty()){
	  int cur=q.front(); //큐에서 진입 차수가 0인 노드를 꺼내온다.
	  q.pop();
	  if(vis[cur]) //중복 방지용
	  	continue;
	  vis[cur]=1;
	  ans.push_back(cur);
	  for(auto i:adj[cur]){ //현재 노드를 지우고 그에 따른 연결된 노드들의 진입차수를 1씩 빼고 0이 된 애들을 큐에 새로 넣는다.
		 if(--jin_ip[i]==0)
		 	q.push(i);
	  }
  }
  for(auto i:ans) //요걸 큐가 빌때 까지 반복하면 위상 정렬 완료. 이걸로 DP도 풀 수 있다.
	cout<<i<<" ";
}
