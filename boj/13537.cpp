#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
long long int n,m,base;
vector<long long int>list;
vector<vector<long long int>>segtree;
int query(int i,int j,int k){
	long long int ans=0;
	long long int x=base+i,y=base+j;
	while(x<y){
		if(x%2){
			if(upper_bound(segtree[x].begin(),segtree[x].end(),k)!=segtree[x].end()){
				ans+=segtree[x].size()-(upper_bound(segtree[x].begin(),segtree[x].end(),k)-segtree[x].begin());
			}
			x++;
		}
		if(!(y%2)){
			if(upper_bound(segtree[y].begin(),segtree[y].end(),k)!=segtree[y].end())
				ans+=segtree[y].size()-(upper_bound(segtree[y].begin(),segtree[y].end(),k)-segtree[y].begin());
			y--;
		}
		x/=2;
		y/=2;
	}
	if(x==y) { //조건문 위치 신경 써주기
			if(upper_bound(segtree[x].begin(),segtree[x].end(),k)!=segtree[x].end())
				ans+=segtree[x].size()-(upper_bound(segtree[x].begin(),segtree[x].end(),k)-segtree[x].begin());
		}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	list.resize(n);
	for(base=1;base<n;base*=2);
	segtree.resize(base*2+1);
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		list.push_back(input);
		segtree[base+i].push_back(input);
	}
	for(long long int i=base-1;i>0;i--){
		segtree[i].insert(segtree[i].end(),segtree[2*i].begin(),segtree[2*i].end());
		segtree[i].insert(segtree[i].end(),segtree[2*i+1].begin(),segtree[2*i+1].end());
		sort(segtree[i].begin(),segtree[i].end());
	}
	cin>>m;
	for(int test=0;test<m;test++){
		int i,j,k;
		cin>>i>>j>>k;
		cout<<query(i-1,j-1,k)<<endl;
	}
}
