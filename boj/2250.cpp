#include<bits/stdc++.h>
using namespace std;
int n,lc[10001],rc[10001],cnt=1,root;
vector<int>level[10001];
set<int>st;
void mid(int cur,int lev){
  if(lc[cur]!=-1)mid(lc[cur],lev+1);
  level[lev].push_back(cnt);
  cnt++;
  if(rc[cur]!=-1)mid(rc[cur],lev+1);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(lc,0,sizeof(lc));
  memset(rc,0,sizeof(rc));
  cin>>n;
  for(int i=1;i<=n;i++)st.insert(i);
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    st.erase(b);
    st.erase(c);
    lc[a]=b;
    rc[a]=c;
  }
  // root노드는 어느 누구의 자녀가 될 수 없다.
  auto it=st.begin();
  mid(*it,1);
  pair<int,int>ans={-1,-1};
  for(int i=1;i<=n;i++){
    if(level[i].empty())break;
    sort(level[i].begin(),level[i].end());
    if(level[i].back()-level[i].front()+1>ans.second)
      ans={i,level[i].back()-level[i].front()+1};
  }
  cout<<ans.first<<" "<<ans.second<<endl;
}
