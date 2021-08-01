#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
long long int base,n;
vector<long long int>tree;
vector<pair<long long int,long long int>>input;
long long int srch(int val){
	long long int l=val+1,r=n-1;
	long long int ans=0;
	while(l<r){
		if(l%2==1) ans+=tree[l++];
		if(r%2==0) ans+=tree[r--];
		l/=2; r/=2;
	}
	if(l==r) ans+=tree[l];
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	cin>>n;
  	for(base=1;base<=n;base*=2);
  	tree.resize(2*base+1,0);
  	for(int i=0;i<n;i++){
		int init;
	  	cin>>init;
	  	input.push_back({init,i});
  	}
  	stable_sort(input.begin(),input.end());
  	for(int i=0;i<n-1;i++){
		if(input[i].first==input[i+1].first) input[i+1].second=input[i].second;
	}
	long long int ans=0;
  	for(int i=0;i<n;i++){
		long long int l=base+input[i].second+1,r=base+n-1;
		while(l<r){
			if(l%2==1) ans+=tree[l++];
			if(r%2==0) ans+=tree[r--];
			l/=2; r/=2;
		}
		if(l==r) ans+=tree[l];
		tree[base+input[i].second]++;
		for(int k=(base+input[i].second)/2;k>0;k/=2)
			tree[k]=tree[k*2]+tree[k*2+1]; 
  	}
  	cout<<ans<<endl;
}
