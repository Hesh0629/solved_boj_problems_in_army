#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long int>a_arr(1001,0);
vector<long long int>b_arr(1001,0);
vector<long long int>a_cnt; // (구간 합, 개수)
vector<long long int>b_cnt;
long long int a, b, t;
int main() {
 	cin>>t;

	cin>>a;
	for(int i=0;i<a;i++)
		cin>>a_arr[i];
	for(int i=0;i<a;i++){
		long long int sum=a_arr[i];
		a_cnt.push_back(sum);
		for(int j=i+1;j<a;j++){
			sum+=a_arr[j];
			a_cnt.push_back(sum);
		}
	}
	sort(a_cnt.begin(),a_cnt.end());
	cin>>b;
	for(int i=0;i<b;i++)
		cin>>b_arr[i];
	for(int i=0;i<b;i++){
		long long int sum=b_arr[i];
		b_cnt.push_back(sum);
		for(int j=i+1;j<b;j++){
			sum+=b_arr[j];
			b_cnt.push_back(sum);
		}
	}
	sort(b_cnt.begin(),b_cnt.end());
	long long int ans=0;
	for(int i=0;i<a_cnt.size();){ //배열에 일일이 누적합의 개수를 저장하면 저장용량이 1GB이상 필요하다. 그냥 계산하는대로 push_back하고 개수 카운팅 하는게 더 낫다.
		long long int cur_a=a_cnt[i];
		long long int cur_b=t-cur_a;
		// int a_ans=count(a_cnt.begin(),a_cnt.end(),cur_a); 이런 방식으로 하니까 TLE가 터졌다.
		// int b_ans=count(b_cnt.begin(),b_cnt.end(),cur_b);
		long long int a_ans=(upper_bound(a_cnt.begin(),a_cnt.end(),cur_a)-a_cnt.begin())-(lower_bound(a_cnt.begin(),a_cnt.end(),cur_a)-a_cnt.begin()); //이런식으로 upper-lower bound 해야한다.
		long long int b_ans=(upper_bound(b_cnt.begin(),b_cnt.end(),cur_b)-b_cnt.begin())-(lower_bound(b_cnt.begin(),b_cnt.end(),cur_b)-b_cnt.begin());
		ans+=a_ans*b_ans;
		i+=a_ans;
	}
	cout<<ans;
}
