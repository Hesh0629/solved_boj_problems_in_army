// dp[n][l][r]로 놓고 구하기...?
// 빌딩을 내림차순으로 정렬 dp[1][1][1] = 1
// dp[i=2][1~i][1~i]를 차례대로 구해서 dp[n][l][r]을 구하면 되긴 하는데....
// dp[i][l][r] = dp[i-1][l][r-1]+dp[i-1][l-1][r]+(현재 숫자를 숨기는 경우의 수)
// 숨길 숫자를 미리 선정하는게 나을까 <- 헛소리, (현재 숫자를 숨기는 경우의 수) = (i-2)*dp[i-1][l][r] 이다. 앞서 나온 숫자들이 자신보다 크니까 놓을 수 있는 위치는 i-2임
#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX 1000000007
using namespace std;
long long int dp[101][101][101]={0};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,left,right;
	cin>>n>>left>>right;
	dp[1][1][1]=1;
	for(int i=2;i<=n;i++){
		for(int l=1;l<=i;l++){
			for(int r=1;r<=i;r++){
				dp[i][l][r]=(dp[i-1][l][r-1]+dp[i-1][l-1][r]+(i-2)*dp[i-1][l][r])%MAX; //현재 숫자를 버리는 경우 left right를 유지시킨 상태로 옴. 이걸 생각못해서 해멧다.
			}
		}
	}
	cout<<dp[n][left][right]%MAX<<endl;
}
