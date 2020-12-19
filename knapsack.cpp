/* 옛날에 푼거지만 업로드
    knapsack problem. 대표적인 dp문제. 물건의 가치와 무게가 주어지고 최대 무게가 주어졌을 때 가치를 최대로 하는 경우
    -> dp[현재 물건 개수][현재 무게] = max(dp[현재 물건 개수 -1][현재 무게-w[i]]], dp[현재 물건 개수-1][현재 무게])
    dp의 기본은 점화식
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, k, M = -500;
	cin >> n >> k; //n개의 물건이 입력되고 최대로 k까지 버팀
	vector<int>w(n); //무게
	vector<int>v(n); //가치
	int**dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[k]; //물건의 개수에 대해 각 무게를 버틸 수 있는지 + 버틸 수 있다면 그때 가치는 몇?
		for (int a = 0; a < k; a++) {
			dp[i][a] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	int i, j, W = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= k; j++) {
			if (j - w[i] >= 0) {
				if (i == 0)
					dp[i][j] = v[i];
				else 
                    dp[i][j] = max( (dp[i - 1][j - w[i]] + v[i]), dp[i - 1][j]); //(j- w[i]>=0) 으로 담을 순 있는데 이전 상황(i-1)에서 이 물건 w[i]를 담을지 또는 안담을지 가치가 큰쪽으로 결정
			}
			else {
				if (i == 0)
					dp[i][j] =0; 
				else 
                    dp[i][j] = dp[i - 1][j]; //현재 물건을 안담는 경우. 만약 담는다면 dp[i-1][j-w[i]] + v[i] <- 이전 상황에서 w[i]를 뺀값으로 완성 시켜야하니까
			}
			if (dp[i][j] > M) {
				M = dp[i][j];
			}
		}
	}
	cout << M << endl;
	return 0;
}
