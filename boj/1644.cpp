#include <bits/stdc++.h>
#define endl '\n'
#define MAX 4000000
using namespace std;
vector<int>prime(MAX+1,1);
vector<int>prime_list;
int main() {
	int n;
	cin>>n;
	for(int i=2;i<=MAX;i++){ //sqrt를 쓰면 안된다 생각해보니
		if(prime[i]){
			for(int j=2;j*i<=MAX;j++) prime[i*j]=0;
			prime_list.push_back(i);
		}
	}
	int s=0, e=0,sum=prime_list[s], ans=0;
	while(prime_list[s]<=n &&e<prime_list.size()){
		if(s==e){
			if(sum==n) {
				ans++;
				sum-=prime_list[s++];
			}
			if(e==prime_list.size()-1) break;
			else sum+=prime_list[++e];
		}
		else if(sum<n){
			if(e==prime_list.size()-1) break;
			else sum+=prime_list[++e];
		}
		else if(sum>n)
			sum-=prime_list[s++];
		else {
			ans++;
			sum-=prime_list[s++];
		}
	}
	cout<<ans<<endl;
}
