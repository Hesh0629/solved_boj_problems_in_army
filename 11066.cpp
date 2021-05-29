// dp 문제중 구간 별 최소 최대를 구해서 전체 구간을 따지는 문제였다.
// 점화식을 세울 때 너무 이전 경우에만 치중하지말자
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000000000000
#define endl '\n'
using namespace std;
long long int mem[501][501]={INF};
vector<long long int>input(501,0);
vector<long long int>psum(501,0);
void clear(){
	for(int i=0; i<501; i++){
		input[i]=0;
		psum[i]=0;
		for(int j=0; j<501; j++)
			mem[i][j]=INF;
	}
}
long long int dp(int s, int e){
	if(mem[s][e]!=INF) return mem[s][e];
	else if(s==e-1){
		mem[s][e]=input[s]+input[e];
		return mem[s][e];
	}
	else if(s==e){
		mem[s][e]=0; // ★ 오늘의 뒷목 포인트 ★ 사실 s==e이면 합치는게 불가능하다.
		return mem[s][e];
	}
	else{
		for(int i=s;i<e;i++){
			mem[s][i]=dp(s,i);
			mem[i+1][e]=dp(i+1,e);
			mem[s][e]=min(mem[s][e], (mem[s][i] + mem[i+1][e]) + psum[e]-psum[s-1]);
		}
		return mem[s][e];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t_case,n;
	cin>>t_case;
  	for(int t=0;t<t_case;t++){
		clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>input[i];
			if(i==1) psum[i]=input[i];
			else psum[i]=psum[i-1]+input[i];
		}
		cout<<dp(1,n)<<'\n';
  }
  return 0;
}
