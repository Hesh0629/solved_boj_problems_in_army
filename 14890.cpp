#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,l;
	cin>>n>>l;
	int map[100][100]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>map[i][j];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int loc=0;
		vector<int>pre(11,0);
		int cur,flag=0;
		while(loc<n){
			if(loc==0) {
				pre[map[i][loc]]++;
				cur=map[i][loc];
				loc++;
			}
			else if(map[i][loc]==cur+1){
				if(pre[cur]<l){
						flag=1;
						break; 
				}
				else {
					pre.clear();
					pre.resize(11,0);
					pre[++cur]++;
					loc++;
				}
			}
			else if(map[i][loc]==cur-1){
				if(loc+l-1>=n) flag =1;
				for(int k=loc;k<loc+l;k++){
					if(map[i][k]!=cur-1){
						flag=1;
						break;
					}
				}
				if(!flag){
					pre.clear();
					pre.resize(11,0);
					pre[--cur]-=(l-1);
				}
				loc++;
			}
			else if(map[i][loc]==cur){
				loc++;
				pre[cur]++;
			}
			else flag=1;
			if(flag) break;
		}
		if(!flag) ans++;
	}
	for(int i=0;i<n;i++){
		int loc=0;
		vector<int>pre(11,0);
		int cur,flag=0;
		while(loc<n){
			if(loc==0) {
				pre[map[loc][i]]++;
				cur=map[loc][i];
				loc++;
			}
			else if(map[loc][i]==cur+1){
				if(pre[cur]<l){
						flag=1;
						break; 
				}
				else {
					pre.clear();
					pre.resize(11,0);
					pre[++cur]++;
					loc++;
				}
			}
			else if(map[loc][i]==cur-1){
				if(loc+l-1>=n) flag =1;
				for(int k=loc;k<loc+l;k++){
					if(map[k][i]!=cur-1){
						flag=1;
						break;
					}
				}
				if(!flag){
					pre.clear();
					pre.resize(11,0);
					pre[--cur]-=(l-1);
				}
				loc++;
			}
			else if(map[loc][i]==cur){
				loc++;
				pre[cur]++;
			}
			else flag=1;
			if(flag) break;
		}
		if(!flag) ans++;
	}
	cout<<ans<<endl;
}
