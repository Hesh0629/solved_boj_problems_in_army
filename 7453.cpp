#include <bits/stdc++.h>
#define endl '\n'
#define MAX 16000001
using namespace std;
vector<int>a,b,c,d,x,y;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	a.reserve(MAX);
	b.reserve(MAX);
	c.reserve(MAX);
	d.reserve(MAX);
	x.reserve(MAX);
	y.reserve(MAX);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int q,w,e,r;
		cin>>q>>w>>e>>r;
		a.push_back(q);
		b.push_back(w);
		c.push_back(e);
		d.push_back(r);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			x.push_back(a[i]+b[j]);
			y.push_back(c[i]+d[j]);
		}
	}
	sort(y.begin(),y.end());
	long long int ans=0;
	for(auto i:x){
		int counter=0-i;
		auto iter=lower_bound(y.begin(),y.end(),counter);
		if(iter==y.end()) continue;
		else{
			int index=iter-y.begin();
			if(y[index]==counter){
				ans+=(upper_bound(y.begin(),y.end(),counter)-y.begin())-index;
				//여길 그냥 for문으로 카운팅하다가 O(n^3) 가능성을 열면서 TLE
			}
			else continue;
		}
	}
	cout<<ans<<endl;
}
