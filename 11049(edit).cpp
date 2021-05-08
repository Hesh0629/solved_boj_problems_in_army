#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<pair<long long int,long long int>>mat;
	for(int i=0;i<n;i++){
		long long int r,c;
		cin>>r>>c;
		mat.push_back({r,c});
	}
	long long int dp[n][n];
	for(int i=0;i<n-1;i++){
		dp[0][i]=mat[i].first*mat[i].second*mat[i+1].second;
	}
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			dp[i][j]=min(dp[i-1][j] + (mat[j].first * mat[i+1+j].first * mat[i+1+j].second), (mat[j].first * mat[j].second * mat[i+1+j].second) + dp[i-1][j+1]);
		}
	}
	cout<<dp[n-2][0];
}
