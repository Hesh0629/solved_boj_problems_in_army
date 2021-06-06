#include <iostream>
#define BIG 1000000000
#define endl '\n'
using namespace std;
int n;
long long int dp[101][10][1024]={0}; // 1111111111 (2) == 1023 (10)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	cin>>n;
	for(int x=1;x<=9;x++)
		dp[1][x][0|(1<<x)]=1; //한자리 숫자의 dp값 책정
	for(int i=2;i<=n;i++){
		for(int x=0;x<=9;x++){
			for(int condition=1;condition<=1023;condition++){
				if(x>0&&x<9)
					dp[i][x][condition|(1<<x)]+=(dp[i-1][x-1][condition]+dp[i-1][x+1][condition]) % BIG; // +=으로 갱신해줘야함. 당연하게도 condition|(1<<x) 값이 같은 경우가 있는데 생각을 
				else if(x==0)
					dp[i][x][condition|(1<<x)]+=dp[i-1][x+1][condition];
				else
					dp[i][x][condition|(1<<x)]+=dp[i-1][x-1][condition];
			}
		}		
	}
	long long int ans=0;
	for(int i=0;i<=9;i++){
		ans+=dp[n][i][1023];
		ans%=BIG;
	}
	cout<<ans<<endl;
	return 0;
}
