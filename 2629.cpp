#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	int dp[32][40001]={0};
	vector<int>list;
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		list.push_back(input);
	}
	dp[0][0]=1;
	dp[0][list[0]]=1;
	for(int i=1;i<n;i++){
		for(int w=0;w<=40000;w++){ // calculate all possible case by knapsack
			if(w==list[i]) dp[i][w]=1;
			if(dp[i-1][w]==1) dp[i][w]=1;
			if(w-list[i]>0){
				if(dp[i-1][w-list[i]]) dp[i][w]=1;
			}
			if(list[i]-w>0){
				if(dp[i-1][list[i]-w]) dp[i][w]=1;
			}
			if(dp[i-1][list[i]+w]) dp[i][w]=1;
		}
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int input;
		cin>>input;
		if(dp[n-1][input]) cout<<"Y ";
		else cout<<"N ";
	}
}
