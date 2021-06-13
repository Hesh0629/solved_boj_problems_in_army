// D S L R 명령들을 기존 횟수보다 줄일 수 있다면 시행하고 BFS를 위해 대기열에 넣는 문제
// L R 명령을 잘못 이해해서 
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#define endl '\n'
#define INF 1000000000000000
using namespace std;
int cal(int input){ // 자릿수 
	if(input/10==0) return 1;
	else if(input/100==0) return 2;
	else if(input/1000==0) return 3;
	else return 4;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		int input,target;
		cin>>input>>target;
		long long int dp[10001];
		fill_n(dp,10001,INF);
		string res[10001]={};
		deque<int>list;
		list.push_front(input);
		dp[input]=0;
		while(!list.empty()){ //list가 빌때까지 시행 (target에 도달한다고 끝낼 수 없는게 더 줄일 여지가 있음.
			int cur=list.back();
			list.pop_back();
			// D 진행
			int d_cur=(cur*2)%10000;
			if(dp[d_cur]>dp[cur]+1){
				dp[d_cur]=dp[cur]+1;
				res[d_cur]=res[cur];
				res[d_cur].append(1,'D');
				list.push_front(d_cur);
			}
			// S 진행
			int s_cur=cur-1;
			if(s_cur==-1) s_cur=9999;
			if(dp[s_cur]>dp[cur]+1){
				dp[s_cur]=dp[cur]+1;
				res[s_cur]=res[cur];
				res[s_cur].append(1,'S');
				list.push_front(s_cur);
			}
			// L,R진행
			int digit=cal(cur), l_cur,r_cur;
			if(digit==1){
				l_cur=cur*10;
				r_cur=cur*1000;
			}
			if(digit==2){
				l_cur=cur*10;
				r_cur=(cur/10)+(cur%10)*1000;
			}
			if(digit==3){
				l_cur=cur*10;
				r_cur=(cur/10)+(cur%10)*1000;
			}
			if(digit==4){
				l_cur=(cur%1000)*10+cur/1000;
				r_cur=(cur/10)+(cur%10)*1000;
			}
			if(dp[l_cur]>dp[cur]+1){
				dp[l_cur]=dp[cur]+1;
				res[l_cur]=res[cur];
				res[l_cur].append(1,'L');
				list.push_front(l_cur);
			}
			if(dp[r_cur]>dp[cur]+1){
				dp[r_cur]=dp[cur]+1;
				res[r_cur]=res[cur];
				res[r_cur].append(1,'R');
				list.push_front(r_cur);
			}
		}
		cout<<res[target]<<endl;
	}
}
