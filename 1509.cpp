#include <bits/stdc++.h>
using namespace std;
int pel[2501][2501], dp[2501];
string s;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<=2500;i++){
		dp[i]=987654321;
		for(int j=0;j<=2500;j++)
			pel[i][j]=0;
	}
	cin>>s;
	//모든 구간에 대하여 O(n^2) 으로 펠린드롬 여부 체크
	for(int len=0;len<s.size();len++){
		for(int x=0;x<s.size();x++){
			int y=x+len;
			if(x==y)pel[x][y]=1;
			else if(len==1&&s[x]==s[y])pel[x][y]=1;
			else if(pel[x+1][y-1]&&s[x]==s[y]) pel[x][y]=1;
		}
	}

	//dp[i]를 i까지의 최소 분할 횟수라고 할 때
	for(int i=0;i<s.size();i++){
		//s[0,i]가 펠린드롬이면 dp[i]=1
		if(pel[0][i]) dp[i]=1;
		else{
			for(int j=1;j<=i;j++)
				if(pel[j][i]) dp[i]=min(dp[i],dp[j-1]+1); //s[j,i]가 펠린드롬이면 옆 식이 성립
		}
	}
	cout<<dp[s.size()-1];
}
