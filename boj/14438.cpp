#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
long long int n,m,base;
vector<long long int>segtree;
void update(){
	int loc,v;
	cin>>loc>>v;
	loc--;
	segtree[base+loc]=v;
	for(int i=(base+loc)/2;i>0;i/=2)
		segtree[i]=min(segtree[2*i],segtree[2*i+1]);
}
void print(){
	int i,j;
	long long int ans=999999999999;
	cin>>i>>j;
	i--;
	j--;
	int x=base+i, y=base+j;
	while(x<=y){
		if(x%2) ans=min(ans,segtree[x++]);
		if(!(y%2)) ans=min(ans,segtree[y--]);
		x/=2;
		y/=2;
		if(x==y){
			ans=min(ans,segtree[x]);
			break;
		}
	}
	cout<<ans<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(base=1;base<=n;base*=2);
	segtree.resize(2*base+1);
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		segtree[base+i]=input;
	}
	for(int i=base-1;i>0;i--) segtree[i]=min(segtree[2*i],segtree[2*i+1]);
	cin>>m;
	for(int test=0;test<m;test++){
		int option;
		cin>>option;
		if(option==1) update();
		else if(option==2) print();
	}
	return 0;
}
