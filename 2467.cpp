#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long int abs(long long int a,long long int b){
	long long int res=a-b;
	if(res<0)return (-1)*(res);
	else return res;
}
int main() {
	int n;
	cin>>n;
	vector<long long int>list;
	for(int i=0;i<n;i++){
		long long int input;
		cin>>input;
		list.push_back(input);
	}
	int sidx=0,eidx=n-1;
	if(list[sidx]>0){
		cout<<list[sidx]<<" "<<list[sidx+1]<<endl;
		return 0;
	}
	if(list[eidx]<0){
		cout<<list[eidx-1]<<" "<<list[eidx]<<endl;
		return 0;
	}
	pair<int,int>ans={0,0};
	for(int i=0;i<n;i++){ //모든 위치를 보면서 O(N)
		int lower_idx=lower_bound(list.begin(),list.begin()+i,-list[i])-list.begin(); //해당원소의 반대부호를 가진 값과 가장 근접한 값 (따라서 더하면 0에 가까워지는)을 찾는다. O(longN)
		long long int lower=list[lower_idx];
		if(abs(list[lower_idx]+list[i],0)<abs(list[ans.first]+list[ans.second],0)&&lower_idx!=i)
			ans={lower_idx,i};
		if(lower_idx<n-1){
			if(abs(list[lower_idx+1]+list[i],0)<abs(list[ans.first]+list[ans.second],0)&&lower_idx+1!=i)
				ans={lower_idx+1,i};
		}
		if(lower_idx>0){
			if(abs(list[lower_idx-1]+list[i],0)<abs(list[ans.first]+list[ans.second],0)&&lower_idx-1!=i)
				ans={lower_idx-1,i};
		}
	}
	if(ans.first>ans.second) cout<<list[ans.second]<<" "<<list[ans.first];
	else cout<<list[ans.first]<<" "<<list[ans.second];
	return 0;
}
