#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int dp[31][31] = { 0 }; //미리 n=30 까지구해둔다
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 0; i <= 30; i++) { // dp[j][i] W H
		for (int j = i; j <= 30; j++) {
			if (i == 0) dp[j][i] = 1;
			else if (j == i) dp[j][i] = dp[j][i - 1]; //IF j==i , dp[j][i] = dp[j][i-1] + 'H' 
			else dp[j][i] = dp[j - 1][i] + dp[j][i - 1]; //ELSE dp[j][i] = dp[j-1][i] + 'W' + dp[j][i-1] + 'H'
		}
	}
	int input;
	while (1) {
		cin >> input;
		if (input == 0)break;
		cout << dp[input][input] << endl;
	}
	return 0;
}
