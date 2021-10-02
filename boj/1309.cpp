#include <bits/stdc++.h>
using namespace std;
int dp[100001][3];
int main(){
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	dp[1][1]=1;
	dp[1][2]=1;
	for(int i=2;i<=100000;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901; // 바로 전 줄에 암것도 없을 때
		dp[i][1]=dp[i-1][0]+dp[i-1][2]%9901; // 바로 전 줄에 왼쪽에 위치
		dp[i][2]=dp[i-1][0]+dp[i-1][1]%9901; // 바로 전 줄에 오른쪽에 위치
	}
	cout<<(dp[n][0]+dp[n][1]+dp[n][2])%9901;
}
