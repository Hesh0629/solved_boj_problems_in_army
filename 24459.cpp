#include<bits/stdc++.h>
#define endl '\n'
#define MAX 10101010
#define INF 1e13
typedef long long int ll;
using namespace std;
ll n, cnt[101010], vis[101010], root, ans_max = 0, ans_min = INF;
vector<ll>asdf[101010];
vector<pair<ll,ll>>adj[101010];
vector<ll> dfs(ll pre, ll cur) {
	vector<ll>now;
	for (auto i : adj[cur]) {
		if (i.first == pre)continue;
		vector<ll>nxt = dfs(cur, i.first);
		for (int j = 0; j < nxt.size(); j++)nxt[j] += i.second;
		now.insert(now.end(), nxt.begin(), nxt.end());
	}
	if (now.size() == 0)now.push_back(0);
	asdf[cur] = now;
	if (asdf[cur].size() >= 2) {
		sort(asdf[cur].begin(), asdf[cur].end());
		ans_min = min(ans_min, asdf[cur][0] + asdf[cur][1]);
		ans_max = max(ans_max, asdf[cur][asdf[cur].size() - 1] + asdf[cur][asdf[cur].size() - 2]);
	}
	return now;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		cnt[a]++;
		cnt[b]++;
		if (cnt[a] > 1)root = a;
		if (cnt[b] > 1)root = b;
	}
	dfs(n, root);
	cout << ans_max << endl << ans_min << endl;
}
