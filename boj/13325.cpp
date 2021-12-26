// segtree와 lazy propagation을 살짝 차용
// 현재 구간에서 얼마나 늘려야하는지를 저장하고 ans에 해당 값만큼 더해준다.
// 하위 구간에는 현재 늘린것만큼 줄여줘야하는데 이때 lazy propagate를 살짝 적용
#include<bits/stdc++.h>
using namespace std;
int segtree[2100000],lazy[2100000],base;
int n,len;
long long int ans=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(segtree,0,sizeof(segtree));
  memset(lazy,0,sizeof(lazy));
  cin>>n;
  len=(int)pow(2,n+1)-1;
  base=(int)pow(2,n);
  int max_len=0;
  for(int i=1;i<=(int)pow(2,n+1)-2;i++){
    cin>>segtree[i+1];
    ans+=segtree[i+1];
    segtree[i+1]+=segtree[(i+1)/2];
    if(i+1>=base)max_len=max(max_len,segtree[i+1]);
  }
  for(int i=base*2-1;i>=base;i--){
    segtree[i]=max_len-segtree[i];
  }
  for(int i=base-1;i>0;i--){
    segtree[i]=min(segtree[2*i],segtree[2*i+1]);
  }
  for(int i=1;i<=2*base-1;i++){
    if(lazy[i]){
      segtree[i]-=lazy[i];
      lazy[2*i]+=lazy[i];
      lazy[2*i+1]+=lazy[i];
      lazy[i]=0;
    }
    ans+=segtree[i];
    lazy[2*i]+=segtree[i];
    lazy[2*i+1]+=segtree[i];
  }
  cout<<ans<<endl;
}
