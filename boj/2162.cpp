#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long int sz[3001],uni[3001];
pair<pair<int,int>,pair<int,int>>v[3001];
int find(int cur){
  if(uni[cur]==cur) return cur;
  else return uni[cur]=find(uni[cur]);
}
int ccw(pair<int,int>a, pair<int,int>b, pair<int,int>c){
  // vector a->b에 대하여 a->c의 상대 위치 판단
  pair<int,int>ab={b.first-a.first,b.second-a.second},ac={c.first-a.first,c.second-a.second};
  int ret=ab.first*ac.second-ab.second*ac.first;
  if(ret>0)return 1;
  else if(ret==0) return 0;
  else return -1;
}
int cross_check(pair<pair<int,int>,pair<int,int>>a,pair<pair<int,int>,pair<int,int>>b){
  if(a.first>a.second) a={a.second,a.first};
  if(b.first>b.second) b={b.second,b.first};
  int check1=ccw(a.first,a.second,b.first)*ccw(a.first,a.second,b.second);
  int check2=ccw(b.first,b.second,a.first)*ccw(b.first,b.second,a.second);
  if(check1<=0 && check2<=0){
    if(check1==0 && check2==0){
      if(a.second<b.first||b.second<a.first) return 0;
      else return 1;
    }
    else return 1;
  }
  else return 0;
}
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    uni[i]=i;
    sz[i]=1;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    v[i]={{x1,y1},{x2,y2}};
    for(int j=0;j<=i-1;j++){
      if(cross_check(v[i],v[j])){
        int parj=find(j),pari=find(i);
        if(pari==parj) continue;
        else if(sz[pari]>sz[parj]){
          uni[parj]=pari;
          sz[pari]+=sz[parj];
        }
        else{
          uni[pari]=parj;
          sz[parj]+=sz[pari];
        }
      }
    }
  }
  long long int ans=-1;
  set<long long int>list;
  for(int i=0;i<n;i++){
    list.insert(uni[find(i)]);
  }
  for(auto i:list)
    ans=max(ans,sz[i]);
  cout<<list.size()<<endl<<ans<<endl;
  return 0;
}
