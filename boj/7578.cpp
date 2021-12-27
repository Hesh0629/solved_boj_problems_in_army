// 2번째 라인을 차례대로 보면서 자신보다 이전에 나왔던 기계들이
// 1번째 라인에 자신이 연결한 기계보다 앞쪽에 연결된 기계가 몇개있는지를 체크
// 차례대로 보는 과정에서 segtree로 구간별로 몇개의 기계가 있는지를 저장
#include<bits/stdc++.h>
using namespace std;
vector<long long int>segtree;
vector<int>idx;
long long int ans=0,n,base,init;
long long int query(int x,int y){
  long long int ret=0;
  x+=base;
  y+=base;
  while(x<=y){
    if(x%2==1)ret+=segtree[x++];
    if(y%2==0)ret+=segtree[y--];
    x/=2;
    y/=2;
    if(x==y){
      ret+=segtree[x];
      break;
    }
  }
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(base=1;base<=n;base*=2);
  segtree.resize(base*2+1,0);
  idx.resize(1000001);
  for(int i=0;i<n;i++){
    cin>>init;
    idx[init]=i;
  }
  for(int i=0;i<n;i++){
    cin>>init;
    for(int j=base+idx[init];j>0;j/=2) segtree[j]+=1;
    ans+=query(idx[init]+1,n-1);
  }
  cout<<ans<<endl;
}
