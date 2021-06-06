#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cal(pair<int,int> a,pair<int,int> b){ // 오늘 2시간 날린 부분.
	int ret1,ret2;
	if(a.first>b.first) ret1=a.first-b.first;
	else ret1=b.first-a.first;
	if(a.second>b.second) ret2=a.second-b.second;
	else ret2=b.second-a.second;
	return ret1+ret2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	int n,w,base;
	cin>>n>>w;
	base=n;
	vector<pair<int,int>>pos(w+2);
	pos[0]={1,1};
	pos[w+1]={n,n};
	int x,y;
	for(int i=1;i<=w;i++){
		cin>>x>>y;
		pos[i]={x,y};
	}
	int dp[1001][1001]={0}; // dp[1번 경찰차가 마지막으로 출동한 사건][2번 경찰차가 마지막으로 출동한 사건] = 두 경찰차가 다음 사건을 해결하는데 필요한 시간
	int car[1001][1001]={0};
	for(int i=w-1;i>=1;i--){ //i는 마지막으로 움직인 위치
		for(int j=0;j<=i-1;j++){
			if(!car[i][j]){ //딱히 필요없긴한데 이미 거친 부분은 pass
				if(j==0){
					dp[i][0]=min(dp[i][i+1]+cal(pos[w+1],pos[i+1]),dp[i+1][0]+cal(pos[i],pos[i+1]));
					if(dp[i][i+1]+cal(pos[w+1],pos[i+1])<dp[i+1][0]+cal(pos[i],pos[i+1]))
						car[i][0]=2;
					else
						car[i][0]=1;
				}
				else{
					dp[i][j]=min(dp[i][i+1]+cal(pos[j],pos[i+1]),dp[i+1][j]+cal(pos[i],pos[i+1]));
					if(dp[i][i+1]+cal(pos[j],pos[i+1])<dp[i+1][j]+cal(pos[i],pos[i+1]))
						car[i][j]=2;
					else
						car[i][j]=1;
				}
			}
			if(!car[j][i]){
				if(j==0){
					dp[0][i]=min(dp[0][i+1]+cal(pos[i],pos[i+1]),dp[i+1][i]+cal(pos[0],pos[i+1]));
					if(dp[0][i+1]+cal(pos[i],pos[i+1])<dp[i+1][i]+cal(pos[0],pos[i+1]))
						car[0][i]=2;
					else
						car[0][i]=1;
				}
				else{
					dp[j][i]=min(dp[j][i+1]+cal(pos[i],pos[i+1]),dp[i+1][i]+cal(pos[j],pos[i+1]));
					if(dp[j][i+1]+cal(pos[i],pos[i+1])<dp[i+1][i]+cal(pos[j],pos[i+1]))
						car[j][i]=2;
					else
						car[j][i]=1;
				}	
			}
		}
	}
	dp[0][0]=min(dp[0][1]+cal(pos[w+1],pos[1]),dp[1][0]+cal(pos[0],pos[1]));
	if(dp[0][1]+cal(pos[w+1],pos[1])<dp[1][0]+cal(pos[0],pos[1]))
		car[0][0]=2;
	else
		car[0][0]=1;
	cout<<dp[0][0]<<endl;
	int a=0,b=0;
	while(a<w&&b<w){
		int next;
		if(a==0&&b==0){
			cout<<car[0][0]<<endl;
			if(car[0][0]==1) a=1;
			else b=1;
		}
		else{
			cout<<car[a][b]<<endl;
			next=max(a,b)+1;
			if(car[a][b]==1)
				a=next;
			else
				b=next;
		}
	}
	return 0;
}
