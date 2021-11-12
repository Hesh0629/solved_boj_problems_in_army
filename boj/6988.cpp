// 이분탐색으로 푼 문제. 원래는 DP로 접근하려다가 메모리문제로 fail
#include <bits/stdc++.h>
using namespace std;
long long int n,x;
vector<long long int>v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	long long int ans=0;
  for(int i=0;i<n;i++){
    long long int pre=i;
    for(int j=i+1;j<n;j++){
      long long int gap=v[j]-v[i];
      long long int cnt=2;
      long long int cur=v[j]+gap, temp=v[i]+v[j];
      auto asdf=lower_bound(v.begin(),v.end(),v[i]-gap);
      if(*asdf==v[i]-gap) continue;
      while(1){
        auto iter=lower_bound(v.begin(),v.end(),cur);
        if(iter!=v.end()&&*iter==cur){
          cnt++;
          temp+=cur;
          cur+=gap;
        }
        else break;
      }
      if(cnt>=3) ans=max(ans,temp);
    }
  }
	cout<<ans<<endl;
}
