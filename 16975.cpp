#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
vector<long long int>segtree;
int n,m,base;
void propagate(int x,int y,int i,int j,int index, int k){
	int half=(x+y)/2;
	if(i<=x&&y<=j)
		segtree[index]+=k;
	else if(y<i||j<x||y<x) return;
	else{
		if(half>=i&&x<=j) propagate(x,half,i,j,index*2,k);
		if(y>=i&&half+1<=j) propagate(half+1,y,i,j,index*2+1,k);
	}
}
void query(int target){
	int index=1;
	int x=0, y=base-1, half=(x+y)/2; //틀린 부분. y를 base-1로 처음부터 수색해줘야 한다.
	while(index<base){
		if(segtree[index]) { //지나는 길에 있는 경우만 업데이트 해주자!
			long long int value=segtree[index];
			segtree[index]=0;
			segtree[index*2]+=value;
			segtree[index*2+1]+=value;
		}
		if(target<=half) {
			y=half;
			index=index*2;
		}
		else {
			x=half+1;
			index=index*2+1;
		}
		half=(x+y)/2;
	}
	cout<<segtree[index]<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(base=1;base<n;base*=2);
	segtree.resize(base*2+1);
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		segtree[base+i]=input;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int option;
		cin>>option;
		if(option==1){
			int i,j,k;
			cin>>i>>j>>k;
			propagate(0,base-1,i-1,j-1,1,k);
		}
		else if(option==2){
			int x;
			cin>>x;
			query(x-1);
		}
	}
	return 0;
}
