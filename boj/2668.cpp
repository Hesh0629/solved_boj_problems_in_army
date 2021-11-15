// DFS를 이용하여 사이클 검출과 해당되는 노드를 찾아내기.
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
// fin[N]: DFS가 끝났는지 여부, vis[N]: 해당 노드를 이전에 방문했는지, par[N]= 현재 정점을 방문한 이전 정점
int n,init,fin[101],vis[101],par[101]; 
vector<int>adj[101],ans;
void dfs(int cur){
  if(vis[cur]){
    // 만약 방문한 적이 있지만 해당 정점이 DFS를 다 돈 상황이라면 더 들어가주지 않아도된다.
    if(fin[cur]) return;
    else{
      // 하지만 해당 방문한 적이 있지만 DFS를 다 안돌았다면 onCase라는 것이다.
      // 해당 정점부터 정답벡터에 넣어주고 자기 자신이 나올 때 까지 사이클에 있는 값들을 넣어준다.
      ans.push_back(cur);
      int i=par[cur];
      while(i!=cur){
        ans.push_back(i);
        i=par[i];
      }
      return;
    }
  }
  vis[cur]=1;
  for(auto i:adj[cur]){
    if(!fin[i]){
      par[i]=cur;
      dfs(i);
    }
  }
  // *DFS가 끝났다는 것을 반드시 써주자*
  fin[cur]=1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(fin,0,sizeof(fin));
  memset(vis,0,sizeof(vis));
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>init;
    adj[i].push_back(init);
  }
  for(int i=1;i<=n;i++) dfs(i);
  sort(ans.begin(),ans.end());

  cout<<ans.size()<<endl;
  for(auto i:ans) cout<<i<<endl;
}
