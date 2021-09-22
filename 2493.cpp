// /O(nlogn)으로 가려다가 실패하고 O(n)으로 푼문제,,,
/* -----------틀린부분--------------
1. v.erase(x,y)를 하면 [x,y-1] 구간이 삭제된다.
2. iterator는 섬세히 다루자
3. ios_base, cin cout.tie를 꼭 쓰자
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,x;
stack<pair<int,int>>s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(s.empty()) {
			cout<<0<<" ";
			s.push({x,i+1});
		}
		else if(s.top().first>x){
			cout<<s.top().second<<" ";
			s.push({x,i+1});
		}
		else{
			while(!s.empty()){
				if(s.top().first<x) s.pop();
				else break;
			}
			if(s.empty()) cout<<0<<" ";
			else cout<<s.top().second<<" ";
			s.push({x,i+1});
		}
	}
	return 0;
}
