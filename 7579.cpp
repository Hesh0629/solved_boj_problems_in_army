// 처음에는 dp[ 현재 조사하고 있는 앱 ][ 현재 메모리 ] 하다가 용량 터져서 dp[0] dp[1] 번갈아 쓰는걸로 해결
// 근데 85퍼에서 틀리는것을 막을 수 없었다...
// 그래서 dp [ 현재 조사하고 있는 앱 ][ 현재 비용 ] = 현재 메모리 식으로 하니 간단히 해결

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	vector<int>w(n,0);
	vector<int>c(n,0);
	long long int sum=0;
	for(int i=0;i<n;i++){
		cin>>w[i];
		sum+=w[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int dp[101][10001]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<=10000;j++){
			if(i==0){
				if(j-c[i]>=0)
					dp[i][j]=w[i];
				else
					dp[i][j]=0;
			}
			else{
				if(j-c[i]>=0)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
				else
					dp[i][j]=dp[i-1][j];
			}
		}
	}
	int ans=100000;
	for(int j=0;j<=10000;j++){
		if(dp[n-1][j]>=m)
			ans=min(ans,j);
	}
	cout<<ans;
}
