#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<long long int>segtree;
long long int base=1;
void query(int a,int b){
	a+=base;
	b+=base;
	long long int ans=999999999999999999;
	while(a<=b){
		if(a%2==1)
			ans=min(ans,segtree[a++]);
		if(b%2==0)
			ans=min(ans,segtree[b--]);
		a/=2;
		b/=2;
		if(a==b){
			ans=min(ans,segtree[a]);
		}
	}
	cout<<ans<<endl;
}
int main() {
	// 흔치않게 요 부분 빼먹어서 틀린 문제
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  int n,m;
	cin>>n>>m;
	for(base=1;base<=n;base*=2);
	segtree.resize(2*base+1,999999999999999999);
	for(int i=0;i<n;i++) cin>>segtree[base+i];
	for(int i=base-1;i>0;i--) segtree[i]=min(segtree[2*i],segtree[2*i+1]);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		query(a-1,b-1);
	}
}
