// stack 영역 터지지않게 큰 변수들은 전역변수로 선언해서 heap 영역에 저장하자
// 체스판은 인접한 영역의 블럭 색이 다르다는 관찰로부터 출발.
// 이를 이용하여 O(nm) 시간내에 해결이 가능한 문제였다.
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[3004][3004];
char init[3004][3004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	memset(init,0,sizeof(init));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>init[i][j];
	}
	memset(dp,0,sizeof(dp));
	long long int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)%2==1) {
				if(init[i][j]=='W')
				 init[i][j]='B';
				else if(init[i][j]=='B')
				 init[i][j]='W';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(init[i][j]=='B') {
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				ans+=dp[i][j];
			}
			else dp[i][j]=0;
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(init[i][j]=='W') {
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				ans+=dp[i][j];
			}
			else dp[i][j]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
