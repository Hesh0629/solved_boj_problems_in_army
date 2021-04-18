//파스칼 삼각형과 조합의 관계를 DP와 메모제이션으로 푸는문제
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string tri[101][101];

string bigint(string a,string b){
	long long int up=0;
	string res;
	while(!a.empty() || !b.empty () ||up){
		if(!a.empty()){
			up+= a.back() -'0';
			a.pop_back();
		}
		if(!b.empty()){
			up+=b.back()-'0';
			b.pop_back();
		}
		res.push_back((up%10)+'0');
		up/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string combi(int n,int m){
	if(n==m||m==0){ //파스칼 삼각형에서 양 끝은 1이다. 그런데 왜 나는 노안이 와서 n과 m을 햇갈렸을까 (여기서 20분씀)
		return "1";
	}
	string &res=tri[n][m];
	if(res !=""){
		return res;
	}
	res=bigint(combi(n-1,m-1),combi(n-1,m)); //nCm = n-1Cm-1 + n-1Cm
	return res; 
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	cout<<combi(n,m);
	return 0;
}
