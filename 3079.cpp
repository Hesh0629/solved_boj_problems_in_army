// 오버플로땜에 고생했던 문제;;
#include<bits/stdc++.h>
using namespace std;
long long int n,m,x,y,T,ans;
long double temp;
vector<long long int>t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		t.push_back(x);
	}
	x=0; y=1.0e+18+1; temp=-1; ans=1.0e+18 + 1;
	while(x<=y){
		temp=0;
		T=(x+y)/2;
		for(auto i:t) temp+=T/i; // 이 과정에서 overflow가 발생한다. 최대 10^23의 데이터가 유입
		if(temp>=m) {
			y=T-1;
			ans=min(T,ans);
		}
		else x=T+1;
	}
	cout.precision(0);
	cout<<ans<<endl;
}
