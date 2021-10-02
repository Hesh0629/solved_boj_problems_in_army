// 보수한 흙길의 마지막 위치(최대값)를 갱신해가며 풀면 되는 문제
#include<bits/stdc++.h>
using namespace std;
int n,l,x,y,last_point;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	last_point=-1;
	cin>>n>>l;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.push_back({x,y-1});
	}
	sort(v.begin(),v.end());
	long long int ans=0;
	for(auto i:v){
		int s=i.first,e=i.second;
		if(s>last_point){
			for(int j=s;;j+=l){
				if(j>e) break;
				ans++;
				last_point=max(last_point,j+l-1);
			}
		}
		else{
			if(e<=last_point) continue;
			for(int j=last_point+1;;j+=l){
				if(j>e)break;
				ans++;
				last_point=max(last_point,j+l-1);
			}
		}
	}
	cout<<ans<<endl;
}
