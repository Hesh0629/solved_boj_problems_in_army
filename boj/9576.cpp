// 정렬 순서 => 1.구간이 끝나는 위치 2. 구간의 시작 위치
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n,m,a,b;
vector<pair<int,int>>v;
set<int>book;
bool cmp(pair<int,int>a, pair<int,int>b){
  if(a.second==b.second)
    return a.first<b.first;
  else
    return a.second<b.second;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int asdf=0;asdf<t;asdf++){
    v.clear();
    v.shrink_to_fit();
    book.clear();
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)book.insert(i);
    for(int qwer=0;qwer<m;qwer++){
      cin>>a>>b;
      v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto i:v){
      auto it=book.lower_bound(i.first);
      if(it==book.end()||*it>i.second)continue;
      else{
        ans++;
        book.erase(*it);
      }
    }
    cout<<ans<<endl;
  }
}
