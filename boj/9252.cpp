// string을 얼마나 안했으면,,, 최장증가부분문자열 문제
// dp긴 한데 문자열 처리하는게 너무 미숙하다.
#include <bits/stdc++.h>
using namespace std;
int dx[2]={-1,0};
int dy[2]={0,-1};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2;
	cin>>s2>>s1;
	int dp[1002][1002];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<s1.size();i++){
		for(int j=0;j<s2.size();j++){
			if(s1[i]==s2[j])dp[i+1][j+1]=dp[i][j]+1;
			else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	}
	int x=s1.size(), y=s2.size();
	int now=dp[x][y];
	vector<char>ans;
	while(1){
		if((dp[x+dx[0]][y+dy[0]]==dp[x+dx[1]][y+dy[1]]) && (dp[x+dx[0]][y+dy[0]]!=dp[x][y])){
			ans.push_back(s1[x-1]);
			x--;
			y--;
		}
		else if(dp[x+dx[0]][y+dy[0]]==dp[x][y]){
			x+=dx[0];
			y+=dy[0];
		}
		else if(dp[x+dx[1]][y+dy[1]]==dp[x][y]){
			x+=dx[1];
			y+=dy[1];
		}
		if(!dp[x][y]) break;
	}
	reverse(ans.begin(),ans.end());
	if(ans.size()==0) {
		cout<<ans.size()<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i];
	return 0;
}
