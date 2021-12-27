#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,Q,base,p,q,opt;
long long int x;
vector<long long int>segtree;
long long int query(int x,int y){
  x+=base;
  y+=base;
  long long int ans=0;
  while(x<=y){
    if(x%2==1) ans+=segtree[x++];
    if(y%2==0) ans+=segtree[y--];
    x/=2;
    y/=2;
    if(x==y){
      ans+=segtree[x];
      break;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>Q;
  for(base=1;base<=N;base*=2);
  segtree.resize(base*2+1,0);
  for(int asdf=0;asdf<Q;asdf++){
    cin>>opt;
    if(opt==1){
      cin>>p>>x;
      for(int i=(base+p);i>0;i/=2)
        segtree[i]+=x;
    }
    else{
      cin>>p>>q;
      cout<<query(p,q)<<endl;
    }
  }
} 
