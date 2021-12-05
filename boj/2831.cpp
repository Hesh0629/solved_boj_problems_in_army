// 양수남자-음수여자 / 양수여자-음수남자로 매칭
// 음수그룹은 오름차순, 양수 그룹은 내림차순으로 설정
// 음수그룹을 기준으로 양수 그룹이 매칭 가능하다면 둘다 pop 아니라면 양수만 pop
// (양수는 내림차순이여서 이번에 안된다면 이후에도 매칭X)
// (음수는 반면 오름차순이기에 이후에도 매칭될 가능성 O)
#include<bits/stdc++.h>
using namespace std;
int n,init,ans=0;
priority_queue<int,vector<int>,greater<int>>neggirl,negman;
priority_queue<int,vector<int>,less<int>>posgirl,posman;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>init;
    if(init>0)posman.push(init);
    else negman.push(init);
  }
  for(int i=0;i<n;i++){
    cin>>init;
    if(init>0)posgirl.push(init);
    else neggirl.push(init);
  }
  while(1){
    if(posman.empty()||neggirl.empty())break;
    int pm=posman.top();
    int ng=neggirl.top();
    if(pm<ng*-1){
      posman.pop();
      neggirl.pop();
      ans++;
    }
    else posman.pop();
  }
  while(1){
    if(negman.empty()||posgirl.empty())break;
    int nm=negman.top();
    int pg=posgirl.top();
    if(pg<nm*-1){
      negman.pop();
      posgirl.pop();
      ans++;
    }
    else posgirl.pop();
  }  
  cout<<ans<<endl;
}
