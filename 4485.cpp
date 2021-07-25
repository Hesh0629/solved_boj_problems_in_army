#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 9876543210
#define endl '\n'
using namespace std;
int dx[3] = { -1,0,1 };
int dy[3] = { -1,0,1 };
int main() {
	int n, cnt = 1;;
	while (1) {
		cin >> n;
		if (n == 0) break;
		int map[127][127];
		int ans[127][127];
		for (int i = 0; i < 127; i++) {
			for (int j = 0; j < 127; j++) {
				map[i][j] = -1;
				ans[i][j] = MAX;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		}
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
		pq.push({ map[1][1],{1,1} });
		ans[1][1] = map[1][1];
		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (cost > ans[x][y]) continue;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (dx[i] == dy[j] || dx[i] - dy[j] == 2 || dy[j] - dx[i] == 2) continue;
					if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[j] >= 1 && y + dy[j] <= n) {
						int tx = x + dx[i], ty = y + dy[j];
						if (ans[tx][ty] > map[tx][ty] + cost) {
							ans[tx][ty] = map[tx][ty] + cost;
							pq.push({ ans[tx][ty],{tx,ty} });
						}
					}
					else continue;
				}
			}
		}
		cout << "Problem "<<cnt++<<": "<<ans[n][n] << endl;
	}
}
