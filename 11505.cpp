// 오버플로 상황을 꼼꼼히 체크하자

#include <bits/stdc++.h>
#define endl '\n'
#define div 1000000007
using namespace std;
int n,m,k;
long long int base;
vector<long long int>segtree;
void query(int a,int b){
	a+=base; b+=base;
	long long int ans=1;
	while(a<=b){
		if(a%2) {
			ans*=(segtree[a++]%div);
			ans%=div;
		}
		if(b%2==0) {
			ans*=(segtree[b--]%div);
			ans%=div;
		}
		a/=2;
		b/=2;
		if(a==b) {
			ans*=segtree[a]%div;
			ans%=div;
			cout<<ans<<endl;
			return;
		}
	}
	cout<<ans%div<<endl;
	return;
}
void update(int loc,long long int num){
	long long int orig=segtree[base+loc];
	int index=base+loc;
	segtree[index]=num;
	index/=2;
	for(;index>0;index/=2)
		segtree[index]=(segtree[index*2]*segtree[index*2+1])%div;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(base=1;base<=n;base*=2);
	segtree.resize(base*2+1,1);
	for(int i=0;i<n;i++)
		cin>>segtree[base+i];
	for(int i=base-1;i>0;i--) segtree[i]=(segtree[2*i]*segtree[2*i+1])%div;
	int a,b,c;
	for(int i=0;i<m+k;i++){
		cin>>a>>b>>c;
		if(a==2) query(b-1,c-1);
		else update(b-1,c);
	}
	return 0;
}
