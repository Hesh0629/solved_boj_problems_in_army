// 사이클이 발생한다 == 같은 유니언끼리 묶으려고 시도했다.
// union-find 문제
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int uni[500001],sz[500001];
int find(int cur){
  if(uni[cur]==cur)return cur;
  // 경로압축을 위해 만나는 노드마다 부모를 자신의 최상위 노드로 설정
  else return uni[cur]=find(uni[cur]);
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
      if(sz[par_a]>sz[par_b]){
        sz[par_b]+=sz[par_a];
      }
      else{
        uni[par_a]=par_b;
        sz[par_a]+=sz[par_b];
      }
    }
  }
  cout<<0<<endl;
  return 0;
}
