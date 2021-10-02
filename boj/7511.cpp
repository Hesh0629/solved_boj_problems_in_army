#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int T,n,k,m,a,b;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		cin>>k;
		vector<int>adj[n];
		for(int j=0;j<k;j++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cin>>m;
		cout<<"Scenario "<<i<<":"<<endl;
		vector<int>vis(n,0);
		int idx=0;

		// 모든 사람들에 대하여 그룹을 만듬
		for(int person=0;person<n;person++){
			if(vis[person]) continue;
			idx++;
			queue<int>q;
			q.push(person);
			vis[person]=idx;
			while(!q.empty()){
				int cur=q.front();
				q.pop();
				for(auto asdf:adj[cur]){
					if(!vis[asdf]){
						vis[asdf]=idx;
						q.push(asdf);
					}
				}
			}
		}
		for(int j=0;j<m;j++){
			cin>>a>>b;
			if(vis[a]==vis[b]&&vis[a]!=0) cout<<1<<endl; // 둘이 같은 그룹이고 외톨이가 아님
			else cout<<0<<endl;
		}
    cout<<endl;
	}
}
