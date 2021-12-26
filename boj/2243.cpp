// segtree에 구간별 사탕이 몇개가 있고 마지막 index를 저장
// segtree[base+idx]에 맛이 idx이 사탕의 개수와 자기 자신 인덱스 저장
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
pair<int,int>segtree[2100000];
int cnt[1000001];
int n,base; // base를 100만이 아니라 segtree형성시 n=100만에 대하여 잡아줘야함
void fix(int b,int c){
  cnt[b]+=c;
  if(cnt[b]==0)segtree[base+b]={0,0};
  else segtree[base+b]={cnt[b],b}; // 해당구간에 몇개 원소 존재 / 마지막 원소 index
  for(int i=(base+b)/2;i>0;i/=2){
    if(segtree[i*2+1]==make_pair(0,0))segtree[i]=segtree[i*2];
    else segtree[i]={segtree[i*2].first+segtree[i*2+1].first,segtree[i*2+1].second};
  }
}
int find(int tar){
  int idx=1;
  while(1){
    if(segtree[idx].first==tar||idx>=base)return segtree[idx].second;
    else if(segtree[idx*2].first<tar){
      tar-=segtree[idx*2].first;
      idx=idx*2+1;
    }
    else
      idx=idx*2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(segtree,0,sizeof(segtree));
  memset(cnt,0,sizeof(cnt));
  for(base=1;base<1000000;base*=2);
  cin>>n;
  for(int asdf=0;asdf<n;asdf++){
    int a;
    cin>>a;
    if(a==2){
      int b,c;
      cin>>b>>c;
      fix(b,c);
    }
    else{
      int b;
      cin>>b;
      int res=find(b);
      cout<<res<<endl;
      fix(res,-1);
    }
  }
} 
