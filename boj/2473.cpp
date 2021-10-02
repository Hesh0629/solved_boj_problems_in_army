#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int abs(long long int a, long long int b){
	long long int res=a-b;
	return (res>0)? res:-res;
}
int main() {
	long long int n,input;
	cin>>n;
	vector<long long int>init;
	for(int i=0;i<n;i++) {
		cin>>input;
		init.push_back(input);
	}
	sort(init.begin(),init.end());
	if(init[0]>0){
		cout<<init[0]<<" "<<init[1]<<" "<<init[2]<<endl;
		return 0;
	}
	long long int positive;
	for(int i=0;;i++){
		if(init[i]>0){
			positive=i;
			break;
		}
		else if(init[i]<0&&i==init.size()-1){
			cout<<init[init.size()-3]<<" "<<init[init.size()-2]<<" "<<init[init.size()-1]<<endl;
			return 0;
		}
	}
	pair<pair<long long int,long long int>,long long int>ans_idx={{0,0},0};
	for(int idx=0;idx<positive;idx++){ // idx는 음수에만 위치
		long long int cur=init[idx];
		for(int idx2=idx+1;idx2<init.size()-1;idx2++){ //idx2는 idx+1부터 끝까지 순회
			long long int pre_sum=init[ans_idx.first.first]+init[ans_idx.first.second]+init[ans_idx.second];
			long long int second=init[idx2];
			long long int lower_idx=lower_bound(init.begin()+idx2+1,init.end(),(long long int)-(cur+second))-init.begin();
			if(lower_idx>0&&lower_idx-1!=idx2){
				long long int cur_sum=cur+second+init[lower_idx-1];
				if(abs(cur_sum,0)<abs(pre_sum,0)){
					ans_idx.first.first=idx;
					ans_idx.first.second=idx2;
					ans_idx.second=lower_idx-1;
				}
			}
			if(lower_bound(init.begin()+idx2+1,init.end(),(long long int)-(cur+second))==init.end()) continue;
			if(lower_idx+1<init.size()&&lower_idx+1!=idx2){
				long long int cur_sum=cur+second+init[lower_idx+1];
				if(abs(cur_sum,0)<abs(pre_sum,0)){
					ans_idx.first.first=idx;
					ans_idx.first.second=idx2;
					ans_idx.second=lower_idx+1;
				}
			}
			long long int cur_sum=cur+second+init[lower_idx];
			if(abs(cur_sum,0)<abs(pre_sum,0)){
				ans_idx.first.first=idx;
				ans_idx.first.second=idx2;
				ans_idx.second=lower_idx;
			}
		}
	}
	long long int pre_sum=(init[ans_idx.first.first])+(init[ans_idx.first.second])+(init[ans_idx.second]);
	if(positive+2<init.size()&&abs(init[positive]+init[positive+1]+init[positive+2],0)<abs(pre_sum,0)){
		ans_idx.first.first=positive;
		ans_idx.first.second=positive+1;
		ans_idx.second=positive+2;
	}
	cout<<init[ans_idx.first.first]<<" "<<init[ans_idx.first.second]<<" "<<init[ans_idx.second]<<endl;
	return 0;
}
