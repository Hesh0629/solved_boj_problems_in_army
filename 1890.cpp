// 자료형 주의
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int n,init[102][102],mem[102][102];
int dx[2]={1,0}, dy[2]={0,1};
long long int dfs(int x,int y){ // 2^64-1까지 값이 올라가므로 long long int 이용
	int dist=init[x][y];
	if(x==n&&y==n){
		mem[x][y]=1;
		return 1;
	}
	else if(init[x][y]==0) {
		return 0;
	}
	for(int i=0;i<2;i++){
		if(x+dx[i]*dist>n||y+dy[i]*dist>n) continue;
		if(mem[x+dx[i]*dist][y+dy[i]*dist]) mem[x][y]+=mem[x+dx[i]*dist][y+dy[i]*dist];
		else mem[x][y]+=dfs(x+dx[i]*dist,y+dy[i]*dist);
	}
	return mem[x][y];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(init,-1,sizeof(init));
	memset(mem,0,sizeof(mem));
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin>>init[i][j];
	}
	cout<<dfs(1,1)<<endl;
}
