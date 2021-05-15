// 매번 테스트 케이스마다 다익스트라마냥 돌리면 되긴하는데 원래는 위상정렬을 진행해야 한다.
// 내가 푼거는 위상정렬 순서로만 진행해서 노드에 접근할 때 도착 시간을 늘릴 수 있다면 늘리는 형식으로 구함.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	int t,n,k,w;
  	cin>>t;
  	for(int test=0;test<t;test++){
		cin>>n>>k;
		vector<int>d(n+1,0);
		vector<int>input(n+1,0);
		vector<int>adj[n+1];
		vector<int>res(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>d[i];
		}
		for(int i=0;i<k;i++){
			int from,to;
			cin>>from>>to;
			adj[from].push_back(to);
			input[to]++;
		}
		queue<int>ready;
		for(int i=1;i<=n;i++){
			if(input[i]==0)
			ready.push(i);
		}
		while(!ready.empty()){	//위상정렬 생성
			int cur=ready.front();
			if(res[cur]==0)
				res[cur]=d[cur];
			ready.pop();
			for(auto i:adj[cur]){
				input[i]--;
				if(input[i]==0)
					ready.push(i);
				if(res[i]==0)
				  	res[i]=res[cur]+d[i];
				else
					res[i]=max(res[i],res[cur]+d[i]);
			}
		}
		cin>>w;
		cout<<res[w]<<'\n';
  	}
  	return 0;
}
