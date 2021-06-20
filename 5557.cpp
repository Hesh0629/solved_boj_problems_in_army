// Top->Down 발상은 좋았는데 어디선가 해메고 있었다.
// n=3일때랑 0이 입력되었을 때가 문제였음
// https://www.ioi-jp.org/joi/2010/2011-yo-prob_and_sol/2011-yo-t4/2011-yo-t4.html
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<long long int>v(n-1);
	for(int i=0;i<n-1;i++){
		int input;
		cin>>input;
		v[n-2-i]=input;
	}
	long long int ans=0, target;
	cin>>target;
	if(n>3){
		long long int dp[100][21]={0}; // dp[i][w] 뒤에서부터 순서를 매겨서 i번째 숫자를 처리했을 때 값이 w라면 target으로 갈 수 있는 경우의 수를 저장
		if(v[0]==0){
			dp[0][target]=2; // 만약 0이라면 +-둘다 가능하므로 저장
		}
		else{
			if(target+v[0]<=20)
				dp[0][target+v[0]]=1; //실제로는 빼는 경우. 빼기 전 상황을 저장한다.
			if(target-v[0]>=0)
				dp[0][target-v[0]]=1; //실제로는 더하는 경우. 더하기 전 상황을 저장한다.
		}
		for(int i=1;i<n-1;i++){
			for(int w=0;w<=20;w++){
				if(v[i]==0){
					dp[i][w]=dp[i-1][w]*2;
					continue;
				}
				if(w+v[i]<=20)
					dp[i][w]+=dp[i-1][w+v[i]]; //실제로는 빼는 경우. 빼기 전 상황을 저장한다.
				if(w-v[i]>=0)
					dp[i][w]+=dp[i-1][w-v[i]]; //실제로는 더하는 경우. 더하기 전 상황을 저장한다.
			}
		}
		if(v[n-2]+v[n-3]<=20)
			ans+=dp[n-4][v[n-2]+v[n-3]];
		if(v[n-2]-v[n-3]>=0)
			ans+=dp[n-4][v[n-2]-v[n-3]];
		cout<<ans<<endl;
	}
	else{
		if(v[1]+v[0]==target)
			ans++;
		if(v[1]-v[0]==target)
			ans++;
		cout<<ans<<endl;
	}
}
