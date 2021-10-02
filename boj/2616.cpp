// prefix sum을 활용하는 dp문제
// dp[객차 수][전체 길이]를 놓고 점화식을 세운다.
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n';
using namespace std;

int main(){
	int n,len;
	cin>>n;
	vector<int>room(n);
	vector<int>sum(n);
	for(int i=0;i<n;i++){
		cin>>room[i];
		if(i==0) sum[i]=room[i];
		else sum[i]=sum[i-1]+room[i];
	}
	cin>>len;
	int dp[4][50001]={0}; //dp[객차수][기관차 총 길이]
	int ans=-1;
	for(int i=0;i<=n;i++){
		if(i<len) dp[1][i]=0;
		else if(i==len) dp[1][i]=sum[i-1];
		else dp[1][i]=max(dp[1][i-1],sum[i-1]-sum[i-len-1]);
		if(ans<dp[1][i]) ans=dp[1][i];
	}
	for(int i=0;i<=n;i++){
		if(i<len*2) dp[2][i]=0;
		else if(i==len*2) dp[2][i]=sum[i-1];
		else dp[2][i]=max(dp[2][i-1],dp[1][i-len]+sum[i-1]-sum[i-len-1]);
		if(ans<dp[2][i]) ans=dp[2][i];
	}
	for(int i=0;i<=n;i++){
		if(i<len*3) dp[3][i]=0;
		else if(i==len*3) dp[3][i]=sum[i-1];
		else dp[3][i]=max(dp[3][i-1],dp[2][i-len]+sum[i-1]-sum[i-len-1]);
		if(ans<dp[3][i]) ans=dp[3][i];
	}
	cout<<ans<<endl;
}
