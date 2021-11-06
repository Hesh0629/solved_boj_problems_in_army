/*
N개의 비행기에 대하여 한 비행기당 logN 스케일로 처리해야함

=> segtree

j 번호를 가진 비행기가 왔다면 [1,j] 중에서 
이용할 수 있는 게이트의 최대값으로 넣어주면 OK
만약 이용할 수 있는 게이트가 없으면 끝
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int base,g,p,init,ans=0;
vector<long long int>segtree;
long long int check(int x,int y){
  x+=base;
  y+=base;
  long long int ret=-1;
  while(x<=y){
    if(x%2==1)ret=max(ret,segtree[x++]);
    if(y%2==0)ret=max(ret,segtree[y--]);
    x/=2;
    y/=2;
    if(x==y) {
      ret=max(ret,segtree[x++]);
      break;
    }
  }
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>g;
  cin>>p;
  for(base=1;base<=g;base*=2);
  segtree.resize(base*2+1,-1);
  for(int i=0;i<g;i++) segtree[base+i]=i;
  for(int i=base-1;i>0;i--) segtree[i]=max(segtree[2*i],segtree[2*i+1]);
  for(int i=0;i<p;i++){
    cin>>init;
    int idx=check(0,init-1);
    if(idx!=-1){
      ans++;
      segtree[base+idx]=-1;
      for(int j=(base+idx)/2;j>0;j/=2){
        // *중요* 구간의 최대값이 방금 사용한 게이트인지 체크해서 지워주기
        if(segtree[j]==idx) segtree[j]=-1; 
        segtree[j]=max(segtree[2*j],segtree[2*j+1]);
      }
    }
    else break;
  }
  cout<<ans<<endl;
}
