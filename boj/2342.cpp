// keypoint memo[l][r][i]를 i번째 일을 할 때 발 위치가 l,r일 때 남은 일을 하는데 걸리는 시간
// 좌우 대칭인 경우 결과값이 같다. DFS의 성질이긴함.(조사를 마친 시점에서 남은 가는데 걸리는 시간은 불변)
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
vector<int>list;
long long int memo[5][5][100001]={0};
long long int rec(int l,int r,int i){ // 왼발, 오른발, 처리해야하는 일 번호
	if(i==list.size())
		return 0;
	if(memo[l][r][i]==0 && memo[r][l][i]==0){
		int left_w,right_w;
		
		if(l==0) left_w=2;
		else if(l==list[i]) left_w=1;
		else if((int)abs(l-list[i])%2==0) left_w=4;
		else left_w=3;

		if(r==0) right_w=2;
		else if(r==list[i]) right_w=1;
		else if((int)abs(r-list[i])%2==0) right_w=4;
		else right_w=3;
		
		long long int ans1=rec(list[i],r,i+1)+left_w;
		long long int ans2=rec(l,list[i],i+1)+right_w;
		long long int ans=min(ans1,ans2);
		memo[l][r][i]=ans; memo[r][l][i]=ans;
		return ans;
	}
	else return memo[l][r][i];
}
int main() {
	int input;
	while(1){
		cin>>input;
		if(!input) break;
		list.push_back(input);
	}
	cout<<rec(list[0],0,1)+2<<endl;
}
