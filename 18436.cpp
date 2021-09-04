#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
long long int n,m,base;;
vector<int>segtree;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(base=1;base<=n;base*=2);
	segtree.resize(base*2+1,0);
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		if(input%2==0)
			segtree[base+i]=1; //짝수이면 1
	}
	for(int i=base-1;i>0;i--)
		segtree[i]=segtree[2*i]+segtree[2*i+1];
	cin>>m;
	for(int i=0;i<m;i++){
		int option;
		cin>>option;
		if(option==1){
			long long int loc,change;
			cin>>loc>>change;
			loc--;
			if((change%2==0)&&segtree[base+loc]==0){
			  for(int j=(base+loc);j>0;j/=2)
					segtree[j]++;
			}
			else if((change%2==1)&&segtree[base+loc]==1){
			  for(int j=(base+loc);j>0;j/=2)
					segtree[j]--;
			}
		}
		else if(option==2){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			long long int ans=0,x=base+l, y=base+r;
			while(x<=y){
				if(x%2) ans+=segtree[x++];
				if(!(y%2)) ans+=segtree[y--];
				x/=2;
				y/=2;
				if(x==y){
					ans+=segtree[x];
					break;
				}
			}
			cout<<ans<<endl;
		}
		else{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			long long int ans=0,x=base+l, y=base+r;
			while(x<=y){ //어이없게 틀린 부분. 등호를 날려먹었다.
				if(x%2) ans+=segtree[x++];
				if(!(y%2)) ans+=segtree[y--];
				x/=2;
				y/=2;
				if(x==y){
					ans+=segtree[x];
					break;
				}
			}
			cout<<(r-l+1)-ans<<endl;
		}
	}
	return 0;
}
