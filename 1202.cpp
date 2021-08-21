// set를 사용합시다,,,,

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
using namespace std;
int n,k,weight,cost;
long long int ans=0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	multiset<int>bag_lim;
	vector<pair<int,int>>dia(n);
	for(int i=0;i<n;i++){
		cin>>weight>>cost;
		dia[i]={cost,weight};
	}
	sort(dia.begin(),dia.end(),greater<>());
	for(int i=0;i<k;i++){
		cin>>weight;
		bag_lim.insert(weight);
	}
	for(int i=0;i<n;i++){ // O(N) 물론 n전에 대부분 끝나긴 한다.
		auto iter=bag_lim.lower_bound(dia[i].second); //O(log N)
		if(iter==bag_lim.end()) continue;
		ans+=dia[i].first;
		bag_lim.erase(iter); //vector erase O(N) >>>> set erase O(log N)
		if(bag_lim.size()==0) break;
	}
	cout<<ans<<endl;
	return 0;
}
