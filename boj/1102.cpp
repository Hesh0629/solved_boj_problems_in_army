// 2021.09.10 틀린문제
// 절대로 greedy하게 접근 X
// 비트마스킹으로 모든 경우의 수 체크 가능
// 시작 지점부터 접근 가능한 모든 dp[해당노드][비트마스크] 에 대하여 계산
// until 발전소 수==p
// 켜진 발전소 >=p 이면 cost=0 (p==0 도 가능)
// 만약 켜진 발전소 ==0 인데 p>0 이면 -1출력
#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
using namespace std;
int n,T,p;
int check(int state){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(state&(1<<(i-1))) cnt++;
		if(cnt>=p) return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cost[17][17]={0}, dp[17][65536];
	for(int i=0;i<17;i++){
		for(int j=0;j<65536;j++) dp[i][j]=INF;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>cost[i][j];
	}
	int initial_state=0,cnt=0;
	queue<pair<int,int>>q;
	vector<int>y;
	for(int i=1;i<=n;i++){
		char input;
		cin>>input;
		if(input=='Y'){
			initial_state=initial_state|1<<(i-1);
			cnt++;
			y.push_back(i);
		}
	}
	for(auto i:y){
		q.push({i,initial_state});
		dp[i][initial_state]=0;
	}
	cin>>p;
	if(cnt>=p) cout<<0<<endl;
	else if(cnt==0) cout<<-1<<endl;
	else{
		int ans=INF;
		while(!q.empty()){
			auto i=q.front();
			q.pop();
			int cur_node=i.first, cur_state=i.second;
			for(int i=1;i<=n;i++){
				int next_state=(cur_state|1<<(i-1));
				if(!(cur_state&1<<(i-1))){
					//cout<<cur_node<<" "<<i<<" "<<cur_state<<" "<<next_state<<endl;
					if(cost[cur_node][i]+dp[cur_node][cur_state]<dp[i][next_state]){
						dp[i][next_state]=cost[cur_node][i]+dp[cur_node][cur_state];
						q.push({i,next_state});
					}
					if(check(next_state)) ans=min(ans,dp[i][next_state]);
				}
				else{
					if(next_state==cur_state && dp[cur_node][cur_state]<dp[i][cur_state]){
						dp[i][cur_state]=dp[cur_node][cur_state];
						q.push({i,cur_state});
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
