#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#define endl '\n'
#define MAX 100000
using namespace std;

int main(){
	int n, m;
	cin >> m >> n;
	int map[102][102] = { 0 };
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (i == 0 || i == n + 1) map[i][j] = -1;
			if (j == 0 || j == m + 1)map[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int input;
			scanf("%1d", &input);
			map[i][j] = input;
		}
	}
	vector<pair<pair<int,int>,int>>adj[101][101];
	// 벽을 뚫고지나가면 1, 아니면 0
  for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i - 1][j] == 1) adj[i][j].push_back({ {i - 1,j},1 });
			else if (map[i - 1][j] == 0) adj[i][j].push_back({ {i - 1,j},0 });

			if (map[i + 1][j] == 1) adj[i][j].push_back({ {i + 1,j},1 });
			else if (map[i + 1][j] == 0) adj[i][j].push_back({ {i + 1,j},0 });

			if (map[i][j - 1] == 1) adj[i][j].push_back({ {i,j - 1},1 });
			else if (map[i][j - 1] == 0) adj[i][j].push_back({ {i,j - 1},0 });
			
			if (map[i][j + 1] == 1) adj[i][j].push_back({ {i,j + 1},1 });
			else if (map[i][j + 1] == 0) adj[i][j].push_back({ {i,j + 1},0 });
			
		}
	}
	int dist[101][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) dist[i][j] = MAX;
	}
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
	pq.push({ 0, { 1,1 } });
	dist[1][1] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (auto i : adj[x][y]) {
			if (cost + i.second < dist[i.first.first][i.first.second]) {
				dist[i.first.first][i.first.second] = cost + i.second;
				pq.push({ dist[i.first.first][i.first.second],{i.first.first,i.first.second } });
			}
		}
	}
	cout << dist[n][m] << endl;
	return 0;
}
