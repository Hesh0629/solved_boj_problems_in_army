// 계단 오르기, 연속된 3개의 계단은 못밟고 한번에 1개 또는 2개만 올라갈 수 있음.
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
	int n;
	int stair[301]={0}, dp[301][3]={0}; //dp[현재 층수][현재 층수에 도달할 때 건너 뛴 계단 수]
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>stair[i];
	for(int i=1;i<=n+1;i++){
		if(i==1){
			dp[1][1]=stair[1];
			dp[1][2]=-100000000;
		}
		else if(i==2){
			dp[2][1]=dp[1][1]+stair[2];
			dp[2][2]=stair[2];
		}
		else{
			dp[i][1]=dp[i-1][2]+stair[i];
			dp[i][2]=max(dp[i-2][1],dp[i-2][2])+stair[i];
		}
	}
	cout<<max(dp[n][1],dp[n][2])<<endl;
}
