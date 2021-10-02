#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <memory.h>
#define INF 10000000
#define endl '\n'
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	int s;
	cin>>s;
	long long int img[1001][1001]; //img[이모티콘 개수][클리보드에 저장된 이모티콘 개수]
	for(int i=0;i<1001;i++)
		fill_n(img[i],1001,INF);
	deque<pair<int,int>>list;
	img[1][0]=0;
	list.push_front({1,0});
	while(!list.empty()){
		int cur=list.back().first;
		int clip=list.back().second;
		list.pop_back();
		if(cur!=1&&cur<=1000){ //현재 클립보드에서 하나 삭제
			if(img[cur-1][clip]>img[cur][clip]+1){
				img[cur-1][clip]=img[cur][clip]+1;
				list.push_front({cur-1,clip});
			}
		}
		if(clip!=0&&cur+clip<=1000){ // 현재 클립보드에서 복붙 (단, 클립보드 != 0)
			if(img[cur+clip][clip]>img[cur][clip]+1){
				img[cur+clip][clip]=img[cur][clip]+1;
				list.push_front({cur+clip,clip});
			}
		}
		if(clip!=cur&&cur*2<=1000){ // 현재 이모티콘을 복사하고 클립보드에서 복붙
			if(img[cur*2][cur]>img[cur][clip]+2)
				img[cur*2][cur]=img[cur][clip]+2;
			list.push_front({cur*2,cur});
		}
	}
	long long int ans=INF;
	for(int i=1;i<=s;i++)
		ans=min(ans,img[s][i]);
	cout<<ans<<endl;
}
