#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
vector<int>par(51),t(51,-1),adj[51];
int rec(int cur){
	if(adj[cur].size()==0){
		t[cur]=0;
		return 0;
	}
	vector<int>list;
	for(auto i:adj[cur]){
		if(t[i]!=-1) list.push_back(t[i]);
		else list.push_back(rec(i));
	}
	sort(list.begin(),list.end(),greater<int>());
	int ans=-1;
	for(int i=0;i<list.size();i++)
		ans=max(ans,list[i]+(i+1));
	t[cur]=ans;
	return ans;
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>par[i];
		if(i!=0)
			adj[par[i]].push_back(i);
	}
	cout<<rec(0)<<endl;
}
