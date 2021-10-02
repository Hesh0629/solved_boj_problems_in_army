// 유클리드 선생님... 당신은 대체...
// 선분 교차 판별법 : 두 선분의 벡터 곱이 0보다 작거나 같을 때, 둘다 같다면 끝점과 시작점을 비교하자.
// 2-SAT 세우는 건 쉬웠는데 선분 교차 판별이 어려웠다.
#include <iostream>
#include <vector>
#include <algorithm>
#define base 1000
using namespace std;
struct v{
	int x; int y;
	int operator == (v other) const{
		return x == other.x && y == other.y;
	}
	int operator < (v other) const{
		return x < other.x && y < other.y;
	}
};
vector<int>adj[2001];
vector<int>adj2[2001];
vector<int>vis(2001,0);
vector<int>comp(2001,-1);
vector<int>dfs_order;
vector<pair<v,v>>pipe(1001);
vector<pair<int,int>>water(1001);
int index=0;
int ccw(v s,v d1, v d2){ // (e1-s) X (e2-s) 값 계산
	v v1,v2;
	v1.x=d1.x-s.x; v2.x=d2.x-s.x;
	v1.y=d1.y-s.y; v2.y=d2.y-s.y;
	int ans= (v1.x * v2.y)-(v2.x * v1.y);
	if(ans>0)
		return 1;
	else if(ans<0)
		return -1;
	else
		return 0;
}
int contact(v a1, v a2, v b1, v b2){
	int ans1=ccw(a1,a2,b1)*ccw(a1,a2,b2);
	int ans2=ccw(b1,b2,a1)*ccw(b1,b2,a2);
	if(ans1==0&&ans2==0){
		if(a1==b1) return 0; //시작점이 같은 경우 (수원지가 같다면 배제)
		if(a2<a1) swap(a2,a1);
		if(b2<b1) swap(b2,b1);
		return !(a2<b1||b2<a1);
	}
	return ans1<=0 && ans2<=0;
}
void dfs1(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj[cur])
		dfs1(i);
	dfs_order.push_back(cur);
}
void dfs2(int cur){
	if(vis[cur]) return;
	vis[cur]=1;
	for(auto i:adj2[cur])
		dfs2(i);
	comp[cur]=index;
}
int main() {
	int w,p;
	cin>>w>>p;
	for(int i=1;i<=w;i++){
		int x,y;
		cin>>x>>y;
		water[i]={x,y};
	}
	for(int i=1;i<=p;i++){
		int num,x,y;
		cin>>num>>x>>y;
		v from, to;
		from.x=water[num].first;
		from.y=water[num].second;
		to.x=x;
		to.y=y;
		pipe[i]={from,to};
	}
	for(int i=1;i<=p-1;i++){
		for(int j=i+1;j<=p;j++){
			if(contact(pipe[i].first,pipe[i].second,pipe[j].first,pipe[j].second)){
				//파이프 i,j가 교차할 시
				adj[i].push_back(j+base);
				adj[i+base].push_back(j);
				adj[j].push_back(i+base);
				adj[j+base].push_back(i);
			}
		}
	}
	for(int i=1;i<=p;i++){
		dfs1(i);
		dfs1(i+base);
		for(auto j:adj[i])
			adj2[j].push_back(i);
		for(auto j:adj[i+base])
			adj2[j].push_back(i+base);
	}
	reverse(dfs_order.begin(),dfs_order.end());
	vis.assign(2001,0);
	for(auto i:dfs_order){
		dfs2(i);
		index++;
	}
	for(int i=1;i<=p;i++){
		if(comp[i]==comp[i+base]){
			cout<<"impossible"<<'\n';
			return 0;
		}
	}
	cout<<"possible"<<'\n';
	return 0;
}
