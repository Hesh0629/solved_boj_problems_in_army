#include <bits/stdc++.h>
using namespace std;
long long int s,n,ans=1;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(n=2;;n++){
		if((n*(n+1)/2)<=s) ans=max(ans,n);
		else break;
	}
	cout<<ans<<endl;
}
