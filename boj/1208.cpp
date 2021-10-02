//투 포인터 구현은 금방했지만 이상하게 계속 틀렸던 문제. 출력양식이 문제는 아니었을텐데 뭔가 이상했다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,s;
  cin>>n>>s;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
	  cin>>arr[i];
  }
  int l=0,r=0;
  int cur_sum=arr[0];
  int ans=2147483646;
  while(l<=r&&r<n){
	  if(cur_sum==s){
		  ans=min(ans,r-l+1);
		  cur_sum+=arr[++r];
	  }
	  else if(cur_sum>s){
		  ans=min(ans,r-l+1);
		  cur_sum-=arr[l++]; //실수
	  }
	  else if(cur_sum<s){
		  cur_sum+=arr[++r];
	  }
  }
  if(ans==2147483646)
	cout<<0<<endl;
  else
	cout<<ans<<endl;
  return 0;
}
