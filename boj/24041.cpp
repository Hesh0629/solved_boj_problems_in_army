// 모든 날짜에 대하여 굳이 구해줄 필요는 없다.
// 이진 탐색으로 해당 날짜에 대하여 구하고 최대 날짜를 구해주면 끝
#include<bits/stdc++.h>
using namespace std;
long long int n,g,k,x=1,y=2000000000;
vector<pair<long long int,long long int>>important,notImportant;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>g>>k;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(c) notImportant.push_back(make_pair(a,b)); // 부패속도, 유통기한
    else important.push_back(make_pair(a,b));
  }
  int ans;
  while(x<=y){
    long long int cur=(x+y)/2;
    long long int curG=0;
    vector<long long int> discard;
    for(auto i:important)
      curG+=i.first*max((long long int)1,(cur-i.second));
    for(auto i:notImportant){
      curG+=i.first*max((long long int)1,(cur-i.second));
      discard.push_back(i.first*max((long long int)1,(cur-i.second)));
    }
    sort(discard.begin(),discard.end(),greater<>());
    for(int i=0;i<min(k,(long long int)discard.size());i++)
      curG-=discard[i];
    if(curG<=g){
      x=cur+1;
      ans=cur;
    }
    else y=cur-1;
  }
  cout<<ans<<endl;
}
