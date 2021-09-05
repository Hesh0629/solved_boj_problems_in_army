#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100000
using namespace std;
char op;
vector<int>prime(MAX+1,1);
vector<int>prime_list;
vector<int>lef(MAX+1,0); //생각해보니 원소 접근 속도는 vector가 더 빠르다.
void asdf(int input){
	for(auto i:prime_list){
		if(prime[i]){
			while(!(input%i)){
				if(op=='*') lef[i]--;
				else lef[i]++;
				input/=i;
			}
		}
		else continue;
		if(input==1) break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=2;i<=sqrt(MAX);i++){
		if(prime[i]){
			for(int j=2;j*i<=MAX;j++) prime[i*j]=0;
			prime_list.push_back(i);
		}
	}
	int n,input;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i==0){
			op='*';
			cin>>input;
		}
		else{
			cin>>op;
			cin>>input;
		}
			if(input<0)input*=-1;
			if(input==0 &&op=='*'){
				cout<<"mint chocolate"<<endl;
				return 0;
			}
			else if(input==1) continue;
			else if(prime[input]){
				if(op=='*') lef[input]--;
				else lef[input]++;
			}
			else asdf(input);
	}
	for(auto i:lef){
		if(i>0) {
			cout<<"toothpaste"<<endl;
			return 0;
		}
	}
	cout<<"mint chocolate"<<endl;
	return 0;
}
