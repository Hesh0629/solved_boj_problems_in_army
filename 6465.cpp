//오랜만에 풀어보는 dp문제. 덕분에 중간에 한번 체해서 화장실을 다녀왔다.
//이 문제에서 점화식은 
//dp[0][i]= max(dp[1][i-1], dp[1][i-2]) + arr[0][i] 
//dp[1][i]= max(dp[0][i-1], dp[0][i-2]) + arr[1][i] 
//왜냐면 각 자리에 도달할수 있는 경우의 수가 위와 같기때문
#include <iostream>
#include <algorithm>
int**arr;
int**dp;
int max_score=0;
using namespace std;
void asdf(int i,int j){
}
int main() {
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		arr=new int*[2];
		dp=new int*[2];
		arr[0]=new int[n]; arr[1]=new int[n];
		dp[0]=new int[n]; dp[1]=new int[n];
		for(int j=0;j<n;j++){
			cin>>arr[0][j];
		}
		for(int j=0;j<n;j++){
			cin>>arr[1][j];
		}
		for(int j=0;j<n;j++){
			if(j==0){
				dp[0][j]=arr[0][j];
				dp[1][j]=arr[1][j];
			}
			else if(j==1){
				dp[0][j]=dp[1][j-1]+arr[0][j];
				dp[1][j]=dp[0][j-1]+arr[1][j];
			}
			else{
				dp[0][j]=max(dp[1][j-1],dp[1][j-2])+arr[0][j];
				dp[1][j]=max(dp[0][j-1],dp[0][j-2])+arr[1][j];
			}
			if(dp[0][j]>max_score)
				max_score=dp[0][j];
			if(dp[1][j]>max_score)
				max_score=dp[1][j];
		}
		cout<<max_score<<endl;
		max_score=0;
	}
}
