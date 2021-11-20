#include<bits/stdc++.h>
using namespace std;
long long int n,ans=0;
deque<int>pos,nag;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    if(init>0) pos.push_back(init);
    else nag.push_back(init);
  }
  sort(pos.begin(),pos.end(),greater<>());
  sort(nag.begin(),nag.end(),less<>());
  while(pos.size()>=2){
    if(pos[0]*pos[1]>pos[0]+pos[1]){
      ans+=pos[0]*pos[1];
      pos.pop_front();
      pos.pop_front();
    }
    else{
      ans+=pos[0];
      pos.pop_front();
    }
  }
  if(!pos.empty()) ans+=pos[0];
  while(nag.size()>=2){
    if(nag[0]*nag[1]>nag[0]+nag[1]){
      ans+=nag[0]*nag[1];
      nag.pop_front();
      nag.pop_front();
    }
    else{
      ans+=nag[0];
      nag.pop_front();
    }
  }
  if(!nag.empty()) ans+=nag[0];
  cout<<ans<<endl;
}
