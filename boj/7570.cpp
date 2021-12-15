// 1씩 증가하는 최장 부분 수열을 찾아내면 되는 문제
// LIS를 찾아내면 나머지 숫자들을 기준으로 차례차례 정렬하면 되는 것이다. (greedy)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,init,dp[1000001],ans=-1;
vector<int>v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++){
    cin>>init;
		v.push_back(init);
	}
  for(int i=0;i<v.size();i++){
    // v[i]로 끝나는 최장부분수열의 길이 = v[i]-1로 끝나는 최장부분수열의 길이 +1
    dp[v[i]]=dp[v[i]-1]+1;
    ans=max(dp[v[i]],ans);
  }
  cout<<n-ans<<endl;
	return 0;
}
