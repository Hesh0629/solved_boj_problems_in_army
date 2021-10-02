//파도파도 나오는 DP, memozation 문제
//dp[s][e]에 [s,e] 구간의 최소값을 저장하고 분할 정복하는 방식.
//이렇게 하면 기존 방식보단 편하게 풀 수 있었다.
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483646
using namespace std;
vector<pair<int,int>>mat;
int dp[500][500]={0};
int rec(int s,int e){
	if(s>e)
		return 0;
	else if(s==e)
		return 0;
	else if(dp[s][e])
		return dp[s][e];
	else{
		int res= INF;
		for(int i=s;i<e;i++){
			res=min(res, rec(s,i)+rec(i+1,e)+mat[s].first*mat[i].second*mat[e].second);
		}
		dp[s][e]=res; //memozation 진행
		return res;
	}
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long int r,c;
		cin>>r>>c;
		mat.push_back({r,c});
	}
	int ans = rec(0,n-1);
	if(ans==INF)
		cout<<0<<'\n';
	else
		cout<<ans<<'\n';
}
