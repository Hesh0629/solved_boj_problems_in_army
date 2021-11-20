// 사이클이 발생한다 == 같은 유니언끼리 묶으려고 시도했다.
#include<bits/stdc++.h>
using namespace std;
int n,m;
int uni[500001],sz[500001];
int find(int cur){
  if(uni[cur]==cur)return cur;
  else return uni[cur]=find(uni[cur]);
}
void merge(int cur,int tar){
  if(uni[cur]==tar) return;
  merge(uni[cur],tar);
  uni[cur]=tar;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    uni[i]=i;
    sz[i]=1;
  }
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    int par_a=find(a),par_b=find(b);
    if(par_a==par_b){
      cout<<i+1<<endl;
      return 0;
    }
    else{
      if(sz[par_a]<sz[par_b]){
        uni[par_a]=par_b;
        sz[par_b]+=sz[par_a];
      }
      else{
        uni[par_b]=par_a;
        sz[par_a]+=sz[par_b];
      }
    }
  }
  cout<<0<<endl;
  return 0;
}
