#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int asdf=0;asdf<t;asdf++){
		int v,e;
		cin>>v>>e;
		vector<int>adj[v+1];
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		queue<pair<int,char>>list;
		vector<char>vis(v+1,0);
		int flag=0;
		for(int i=1;i<=v;i++){ //처음부터 같은 componant에 속한다는 보장이 없다
			if(vis[i]==0){
				list.push({i,'R'});
				while(!list.empty()){
					auto cur=list.front();
					list.pop();
					if(vis[cur.first]!=0){
						if((vis[cur.first]=='R'&&cur.second=='B')||(vis[cur.first]=='B'&&cur.second=='R')) {
							flag=1;
							break;
						}
						else continue;
					}
					vis[cur.first]=cur.second;
					char next=(cur.second=='R')?'B':'R';
					for(auto i:adj[cur.first]){
						if(vis[i]==0) list.push({i,next});
					}
				}
			}
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
