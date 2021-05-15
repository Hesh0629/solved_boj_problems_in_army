// 합 분해 문제인데 그냥 k=1,2를 예외처리하고 3부터 0~n이 몇번 등장 할 수 있는지를 수학적으로 접근
// 그 결과 누적 합이 나왔다.
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
using namespace std;
long long int dp[201][201]={0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  cin>>n>>k;
  if(k==1)
	cout<<1;
  else if(k==2)
	cout<<n+1;
  else{
	for(long long int i=n;i>=0;i--)
		dp[3][i]=n+1-i;
	for(long long int i=4;i<=k;i++){
		for(long long int j=n;j>=0;j--){
			if(j!=n)
				dp[i][j]=(dp[i][j+1]+dp[i-1][j]) % MAX;
			else 
				dp[i][j]=1;
		}
	}
	long long int ans=0;
	for(int i=0;i<=n;i++)
		ans+=dp[k][i]%MAX;
	cout<<ans%MAX;
  }
  return 0;
}
