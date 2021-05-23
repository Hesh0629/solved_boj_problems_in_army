// 13398 연속합2번과 유사하지만 고려해야할 케이스가 있는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int pizza,a,b;
  cin>>pizza>>a>>b;
  vector<int>arr(2*a);
  vector<int>brr(2*b);
  for(int i=0;i<a;i++){
	  cin>>arr[i];
	  arr[i+a]=arr[i];
  }
  for(int i=0;i<b;i++){
	  cin>>brr[i];
	  brr[i+b]=brr[i];
  }
  vector<int>a_res;
  vector<int>b_res;
  for(int i=0;i<a;i++){
	  long long int sum=0;
	  for(int j=i;j<i+a-1;j++){
		  sum+=arr[j];
		  a_res.push_back(sum);
	  }
  }
   for(int i=0;i<b;i++){
	  long long int sum=0;
	  for(int j=i;j<i+b-1;j++){
		  sum+=brr[j];
		  b_res.push_back(sum);
	  }
  }
  // 기존 문제와 달라지는 점 => 피자 a,b 둘 중 하나를 안고르거나 중복되는 케이스가 존재한다.
  int t_sum=0;
  for(int i=0;i<a;i++){
	  t_sum+=arr[i];
  }
  a_res.push_back(0);
  a_res.push_back(t_sum);
  t_sum=0;
  for(int i=0;i<b;i++){
	  t_sum+=brr[i];
  }
  b_res.push_back(0);
  b_res.push_back(t_sum);
  sort(a_res.begin(),a_res.end());
  sort(b_res.begin(),b_res.end());
  long long int ans=0;
  for(int i=0;i<a_res.size();){
	  int b_val=pizza-a_res[i];
	  long long int a_ans=(upper_bound(a_res.begin(),a_res.end(),a_res[i])-a_res.begin())-(lower_bound(a_res.begin(),a_res.end(),a_res[i])-a_res.begin());
	  long long int b_ans=(upper_bound(b_res.begin(),b_res.end(),b_val)-b_res.begin())-(lower_bound(b_res.begin(),b_res.end(),b_val)-b_res.begin());
	  ans+= a_ans*b_ans;
	  i+=a_ans;
  }
  cout<<ans<<'\n';
}
