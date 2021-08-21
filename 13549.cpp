//시작은 DP였는데 풀고나니 BFS가 된 문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000
using namespace std;

int main() {
	int dp[100001]={0}; //그 지점에 도달하는데 걸리는 최소시간
	int n,k,flag=0;
	cin>>n>>k;
	if(n>k) flag=1;
	queue<int>q;
	q.push(k);
	if(n==k) { // 틀린 케이스. 예외처리
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;;i++){
		queue<int>next;
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			if(cur%2==0&&cur!=0){
				if(!dp[cur/2]){
					q.push(cur/2);
					dp[cur/2]=i;
				}
				if(cur/2==n){
					cout<<i<<endl;
					return 0;
				}
			}
			if(cur+1==n){
				cout<<i+1<<endl;
				return 0;
			}
			if(cur-1==n){
				cout<<i+1<<endl;
				return 0;
			}
			if(!dp[cur+1]&&cur+1<=MAX){
				next.push(cur+1);
				dp[cur+1]=i+1;
			}
			if(!dp[cur-1]&&!flag&&cur-1>=0){
				next.push(cur-1);
				dp[cur-1]=i+1;
			}
		}
		q=next;
		while(!next.empty())next.pop();
	}
}
