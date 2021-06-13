// RGB거리 문제와 달리 첫번째 집과 마지막 집이 연결되어 있다.
// 달라지는건 크진 않고 그냥 첫번째 집의 색을 지정해주고 푸면 되긴하는데 식이 너무 길어진다...
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define INF 1000000000
using namespace std;
int main() {
	int n;
	long long int input[1003][4]={0};
	long long int dp[1003][4][4]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>input[i][1]>>input[i][2]>>input[i][3];
	dp[1][1][1]=input[1][1];
	dp[1][2][2]=input[1][2];
	dp[1][3][3]=input[1][3];
	for(int c=1;c<=3;c++){
		for(int i=2;i<=n;i++){
			if(i==2){
				dp[i][c][c]=INF;
				if(c==1){
					dp[i][2][c]=dp[i-1][c][c]+input[i][2];
					dp[i][3][c]=dp[i-1][c][c]+input[i][3];
				}
				else if(c==2){
					dp[i][1][c]=dp[i-1][c][c]+input[i][1];
					dp[i][3][c]=dp[i-1][c][c]+input[i][3];
				}
				else{
					dp[i][1][c]=dp[i-1][c][c]+input[i][1];
					dp[i][2][c]=dp[i-1][c][c]+input[i][2];
				}
			}
			else if(i==n){
				dp[i][c][c]=INF;
				if(c==1){
					dp[i][2][c]=min(dp[i-1][1][c],dp[i-1][3][c])+input[i][2];
					dp[i][3][c]=min(dp[i-1][1][c],dp[i-1][2][c])+input[i][3];
				}
				else if(c==2){
					dp[i][1][c]=min(dp[i-1][2][c],dp[i-1][3][c])+input[i][1];
					dp[i][3][c]=min(dp[i-1][1][c],dp[i-1][2][c])+input[i][3];
				}
				else{
					dp[i][1][c]=min(dp[i-1][2][c],dp[i-1][3][c])+input[i][1];
					dp[i][2][c]=min(dp[i-1][1][c],dp[i-1][3][c])+input[i][2];
				}
			}
			else{
				dp[i][1][c]=min(dp[i-1][2][c],dp[i-1][3][c])+input[i][1];
				dp[i][2][c]=min(dp[i-1][1][c],dp[i-1][3][c])+input[i][2];
				dp[i][3][c]=min(dp[i-1][1][c],dp[i-1][2][c])+input[i][3];
			}
		}
	}
	long long int ans=INF;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++)
			ans=min(ans,dp[n][i][j]);
	}
	cout<<ans<<endl;
}
