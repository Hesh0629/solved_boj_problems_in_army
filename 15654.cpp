#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n' // 잊지말자
using namespace std;
vector<int>ans;
int n,m;
vector<int>input;
vector<int>check(8,0); //중복 방지용
void rec(int cur){
	if(cur==m){
		if(cur==1){
			for(int i=0;i<n;i++){
				ans.push_back(input[i]);
				for(auto k:ans){
					cout<<k<<" ";
				}
				cout<<endl;
				ans.pop_back();
			}
		}
		else{
			for(int i=0;i<n;i++){
				if(check[i]) continue;
				check[i]=1;
				ans.push_back(input[i]);
				for(auto k:ans){
					cout<<k<<" ";
				}
				cout<<endl;
				check[i]=0;
				ans.pop_back();
			}
		}
	}
	else if(cur==1&&cur!=m){
		for(int i=0;i<n;i++){
			check[i]=1;
			ans.push_back(input[i]);
			rec(cur+1);
			ans.pop_back();
			check[i]=0;
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(check[i]) continue;
			check[i]=1;
			ans.push_back(input[i]);
			rec(cur+1);
			ans.pop_back();
			check[i]=0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int init;
		cin>>init;
		input.push_back(init);
	}
	sort(input.begin(),input.end());
	rec(1);
}
