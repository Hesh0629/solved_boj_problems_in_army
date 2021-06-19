#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int test=0;test<t;test++){
		int n,m;
		int dp[10001]={0};
		dp[0]=1; // 기저조건 (0을 만드는 방법은 단 하나).
		cin>>n;
		vector<int>coin;
		for(int i=0;i<n;i++){
			int input;
			cin>>input;
			coin.push_back(input);
		}
		cin>>m;
		for(auto bit:coin){ //동전이 오름차순 정렬이므로 이렇게 하면 섞이는 일이 없다. (이걸 생각못함)
			for(int w=bit;w<=m;w++){
					dp[w]+=dp[w-bit];
			}
		}
		cout<<dp[m]<<endl;
	}
}
