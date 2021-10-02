#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dp[1001]={0};
	dp[1]=1;
	dp[2]=2;
	cin>>n;
	for(int i=3;i<=n;i++)
		dp[i]=(dp[i-2]+dp[i-1])%10007;
	cout<<dp[n]<<endl;
}
