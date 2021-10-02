// ...많이 공허했던 문제
// dp 점화식만 제대로 세우면 풀릴 문제였다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int dp[100001][2];  //dp[i][0]는 i번째 까지 하나도 안지웠을 때 최대, dp[i][1]는 하나를 지웠을 때 최대값을 저장한다.
	dp[0][0]=arr[0];
	dp[0][1]=0;
	int ans=max(dp[0][0],dp[0][1]);
	for(int i=1;i<n;i++){
		dp[i][0]=max(0,dp[i-1][0])+arr[i]; //i번재에서 이전 것을 더했을 때 줄어든다면 배제(0을 선택)하고 현재 arr[i]를 더해준다. 아니면 누적합을 구한다.
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]+arr[i]); // 하나를 줄일때는 안지운 상태에서 arr[i]를 지우거나 이전에 지운 상태에서 arr[i]를 더해준것을 비교해서 넣어준다. 둘 중 큰것을 선택
		ans = max(ans,max(dp[i][0],dp[i][1])); //ans갱신
	}
	cout<<ans;
}
