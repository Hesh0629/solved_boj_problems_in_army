// 좌표압축,변환 + offline query가 가장 중요했던 문제
// 좌표압축 테크닉을 늘리자.
// offline query로 내가 유리한 방식으로 query 순서 바꾸기
// 좌표 압축으로 실력을 1~N으로 줄인다.
// 큰 실력부터 자신보다 앞쪽에 큰 실력이 몇개 있는지를 segtree로 체크한다.
// 이때 입력 순서는 그대로 유지하고 segtree만 1~N으로 두기 때문에 좌표 변환을 해준다.
/*
Ex)   2 8 10 7 1 9 4 15
변환-> 2 5 7 4 1 6 3 8

2 5 7 4 1 6 3 8
0 0 0 0 0 0 0 0
8을 기준으로 앞에 체크된 숫자는 X
7도 마찬가지임. 그러면 이후에는 아래와 같이 됨
2 5 7 4 1 6 3 8
0 0 1 0 0 0 0 1
하지만 6은 자신보다 앞쪽에 체크된 숫자가 하나 존재
따라서 6은 2등이 최선
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,base;
map<int,int>mp,mp2;
vector<int>v1,v2,segtree,ans;
int query(int x,int y){
  int ret=0;
  x+=base;
  y+=base;
  while(x<=y){
    if(x%2==1) ret+=segtree[x++];
    if(y%2==0) ret+=segtree[y--];
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
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    v1.push_back(init);
    v2.push_back(init);
  }
  sort(v2.begin(),v2.end());
  int idx=1;
  for(auto i:v2)
    mp[i]=idx++;
  for(int i=1;i<=n;i++)
    mp2[mp[v1[i-1]]]=i;
  for(base=1;base<=n+1;base*=2);
  segtree.resize(base*2+1,0);
  ans.resize(n+1);
  for(int i=n;i>=1;i--){
    int idx=mp2[i];
    ans[idx]=query(0,idx-1)+1;
    segtree[base+idx]++;
    for(int j=(base+idx)/2;j>0;j/=2)
      segtree[j]=segtree[2*j]+segtree[2*j+1];
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<endl;
}
