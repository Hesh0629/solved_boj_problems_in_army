#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
	int n;
	cin>>n;
	int dp[501][501]={0},input[501][501];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			cin>>input[i][j];
	}
	dp[1][1]=input[1][1];
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1) dp[i][j]=dp[i-1][j]+input[i][j];
			else if(j==i) dp[i][j]=dp[i-1][j-1]+input[i][j];
			else dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+input[i][j];
			if(i==n&&dp[i][j]>ans) ans=dp[i][j];
		}
	}
	cout<<ans<<endl;
}
