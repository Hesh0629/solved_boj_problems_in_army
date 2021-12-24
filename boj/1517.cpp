// 배열을 정렬한 후에 기존 정렬에서 자신보다 오른쪽에 자신보다 작은 수가 몇개 있는지를 CNT
// 완료된 숫자에는 +1을 해서 뒤에 검사할 자신보다 큰 숫자가 자신을 cnt할 수 있도록 한다.
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
long long int base,n;
vector<long long int>tree;
vector<pair<long long int,long long int>>input;
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
	long long int ans=0;
  	for(int i=0;i<n;i++){
		long long int l=base,r=base+input[i].second-1;
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
