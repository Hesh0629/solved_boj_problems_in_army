#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
// case1 {a>b, c>d} case2 {a>b, c<d} case3 {a<b, c<d}
// 노선의 시작지점과 끝나는 지점을 정렬하고 타임스케줄링하듯이 진행하면 된다.
// 단 case2할때 case3에 있는 경우들의 시작 지점과 끝나는 지점을 각각 -n,+n해주고 진행
// 해당 노선이 지워지는 경우 vis[해당노선]=0 으로 만들기
bool cmp(const pair<pair<int,int>,int>a,const pair<pair<int,int>,int>b){
	if(a.first.first<b.first.first) return true;
	else if(a.first.first>b.first.first) return false;
	else{
		if(a.first.second>b.first.second) return true;
		else return false;
	}
}
int main() {
	int n,m;
	vector<pair<pair<int,int>,int>>a,b,c,sa,sb; //a = case1, b = case2, c = case3
	cin>>n>>m;
	vector<char>vis(m+1,1);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(x<y)a.push_back({{x,y},i+1});
		else b.push_back({{x,y},i+1});
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	int cur=-987654321;
	for(auto i:a){
		if(i.first.second>cur){
			cur=i.first.second;
			sa.push_back(i);
		}
		else 
			vis[i.second]=0;
	}
	cur=-987654321;
	for(auto i:b){
		if(i.first.second>cur){
			int s=i.first.first,e=i.first.second,num=i.second;
			cur=e;
			pair<pair<int,int>,int>j=i,k=i;
			j.first.first=s-n;
			k.first.second=e+n;
			sb.push_back(j);
			sb.push_back(k);
		}
		else 
			vis[i.second]=0;
	}
	cur=-987654321;
	c.insert(c.end(),sa.begin(),sa.end());
	c.insert(c.end(),sb.begin(),sb.end());
	sort(c.begin(),c.end(),cmp);
	for(auto i:c){
		if(i.first.second>cur)
			cur=i.first.second;
		else
			vis[i.second]=0;
	}
	for(int i=1;i<=m;i++){
		if(vis[i]) cout<<i<<" ";
	}
	cout<<endl;
}
