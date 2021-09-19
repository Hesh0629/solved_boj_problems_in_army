//2-SAT 문제인 것을 알아내기만 하면 풀만한 문제
// 오랜만에 풀어서 해메긴 했지만 선분교차나 기타 구현 과정이 원만했다.
#include <bits/stdc++.h>
#define endl '\n'
#define base 3001
using namespace std;
vector<pair<pair<int,int>,pair<int,int>>>v;
vector<int>adj[6006];
vector<int>adj2[6006];
vector<int>scc_group[6006],bool_value(6006,-1),ans;
int vis[6006],comp;
vector<int>DAG;
void dfs(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj[cur]) dfs(i);
	DAG.push_back(cur);
}
void dfs2(int cur){
	if(vis[cur]) return;
	vis[cur]=comp;
	scc_group[comp].push_back(cur);
	for(auto i:adj2[cur]) dfs2(i);
}
int cross(pair<int,int>a,pair<int,int>b){
	int ret;
	if(a.first*b.second-a.second*b.first>0) ret=1;
	else if(a.first*b.second-a.second*b.first<0) ret=-1;
	else ret=0;
	return ret;
}
int check_cross(pair<pair<int,int>,pair<int,int>>a,pair<pair<int,int>,pair<int,int>>b){
	pair<int,int>v1={a.second.first-a.first.first,a.second.second-a.first.second};
	pair<int,int>v2={b.second.first-a.first.first,b.second.second-a.first.second};
	pair<int,int>v3={b.first.first-a.first.first,b.first.second-a.first.second};
	int res1=cross(v1,v2)*cross(v1,v3);
	v1={b.second.first-b.first.first,b.second.second-b.first.second};
	v2={a.first.first-b.first.first,a.first.second-b.first.second};
	v3={a.second.first-b.first.first,a.second.second-b.first.second};
	int res2=cross(v1,v2)*cross(v1,v3);
	if(res1==-1&&res2==-1) return 1;
	else return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(vis,0,sizeof(vis));
  int n;
	cin>>n;
	for(int i=1;i<=3*n;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		v.push_back({{x1,y1},{x2,y2}});
	}
	int cnt=0;
	for(int i=0;i<3*n;i++){
		for(int j=0;j<3*n;j++){
			if(check_cross(v[i],v[j])&&i!=j) {
				adj[i+1].push_back(base+j+1); // 두 선분이 교차한다면 한쪽이 남아있다면 다른쪽은 사라져야한다.
				cnt++;
			}
		}
		if((i+1)%3==0){ // 한 학생이 들고있는 막대기를 버리면 나머지는 버리면 안된다.
			adj[base+(i+1)].push_back((i+1)-2);
			adj[base+(i+1)].push_back((i+1)-1);
			adj[base+(i+1)-1].push_back((i+1)-2);
			adj[base+(i+1)-1].push_back((i+1));
			adj[base+(i+1)-2].push_back((i+1)-1);
			adj[base+(i+1)-2].push_back((i+1));
		}
	}
	if(!cnt){
		cout<<0<<endl; return 0;
	}
	for(int i=1;i<=3*n;i++) {
		if(!vis[i]) dfs(i);
		if(!vis[i+base]) dfs(i+base);
		for(auto k:adj[i]) adj2[k].push_back(i);
		for(auto k:adj[i+base]) adj2[k].push_back(i+base);
	}
	reverse(DAG.begin(),DAG.end());
	memset(vis,0,sizeof(vis));
	comp=1;
	for(auto i:DAG){
		dfs2(i);
		if(!scc_group[comp].empty()) comp++;
	}
	for(int i=1;i<=3*n;i++){ //예상외로 틀린부분. i를 comp까지 돌려놨었다.
		if(vis[i]==vis[base+i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=0;i<comp;i++){
		for(auto k:scc_group[i]){
			if(bool_value[k]==-1){
				if(k>base){
					bool_value[k]=0;
					bool_value[k-base]=1;
				}
				else{
					bool_value[k]=0;
					bool_value[k+base]=1;
					ans.push_back(k);
				}
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto i:ans) cout<<i<<" ";
}
