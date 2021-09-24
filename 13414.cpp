//v.erase() 는 O(n) 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int string_to_int(string s){
	int res=0;
	for(int i=0;i<s.size();i++)
		res+=(s[i]-'0')*(int)(pow(10,s.size()-(i+1)));
	return res;
}
map<int,int>mem;
vector<string>v;
string s;
int n,m;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>s;
		int cur=string_to_int(s);
		if(mem.find(cur)!=mem.end()) {
			v[mem[cur]]="-1";
		}
		v.push_back(s);
		mem[cur]=i;
	}
	int cnt=0;
	for(int i=0;i<m;i++) {
		if(v[i]!="-1") {
			cout<<v[i]<<endl;
			cnt++;
			if(cnt==n) return 0;
		}
	}
	return 0;
}
