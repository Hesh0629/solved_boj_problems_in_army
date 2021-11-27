#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>vis;
long long int half,n,s,ans;
vector<int>v;
void left(int idx,int val){
	if(idx==half){
		vis[val]++;
	}
	else{	
		left(idx+1,val);
		left(idx+1,val+v[idx]);
	}
}
void right(int idx,int val){
	if(idx==n){
		ans+=vis[s-val];
	}
	else{
		right(idx+1,val);
		right(idx+1,val+v[idx]);
	}
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans=0;
  cin>>n>>s;
  for(int i=0;i<n;i++){
	  int x;
	  cin>>x;
	  v.push_back(x);
  }
  half=n/2;
  left(0,0);
  right(half,0);
  if(!s)ans--;
  cout<<ans<<endl;
  return 0;
}
