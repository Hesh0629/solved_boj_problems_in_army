#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
long long int base,n;
vector<long long int>tree;
vector<pair<int,int>>input;
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
  	stable_sort(input.begin(),input.end(),greater<pair<long long int,long long int>>());
	long long int res=-1;
  	for(int i=0;i<n;i++){
		long long int ans=0;
		long long int l=base,r=base+input[i].second-1;
		while(l<r){
			if(l%2==1) ans+=tree[l++];
			if(r%2==0) ans+=tree[r--];
			l/=2; r/=2;
		}
		if(l==r) ans+=tree[l];
		res=max(ans,res);
		tree[base+input[i].second]++;
		for(int k=(base+input[i].second)/2;k>0;k/=2)
			tree[k]=tree[k*2]+tree[k*2+1]; 
  	}
	cout<<res+1<<endl;
}
