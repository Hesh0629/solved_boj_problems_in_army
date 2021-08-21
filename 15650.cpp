// 간단한 백트래킹 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int>ans;
int n,m;
void rec(int cur){
	if(cur==m){
		if(cur==1){
			for(int i=1;i<=n;i++){
				ans.push_back(i);
				for(auto k:ans){
					cout<<k<<" ";
				}
				cout<<endl;
				ans.pop_back();
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(ans.back()<i){
					ans.push_back(i);
					for(auto k:ans){
						cout<<k<<" ";
					}
					cout<<endl;
					ans.pop_back();
				}
			}
		}
	}
	else if(cur==1&&cur!=m){
		for(int i=1;i<=n;i++){
			ans.push_back(i);
			rec(cur+1);
			ans.pop_back();
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(ans.back()<i){
				ans.push_back(i);
				rec(cur+1);
				ans.pop_back();
			}
		}
	}
}
int main() {
	cin>>n>>m;
	rec(1);
}
