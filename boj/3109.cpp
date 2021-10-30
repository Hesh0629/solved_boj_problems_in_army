#include <bits/stdc++.h>
using namespace std;
int r,c,vis[10002][502],ans,memo[10002][502]; // memo에는 진입하면 안되는 길 명시 (TLE 해결)
char init[10002][502];
vector<int>v;
int dfs(int i,int j){
  vis[i][j]=1;
  if(j==c) return 1;
  else{
    int result;
    for(int next=-1;next<=1;next++){
      if(init[i+next][j+1]=='.'&&!vis[i+next][j+1]&&!memo[i][j]){
        result=dfs(i+next,j+1);
        if(result) return result;
      }
    }
    vis[i][j]=0;
    memo[i][j]=1;
    return 0;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>r>>c;
  v.resize(c+1,0);
  memset(init,-1,sizeof(init));
  memset(vis,0,sizeof(vis));
  memset(memo,0,sizeof(memo));
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++)
      cin>>init[i][j];
  }
  for(int i=1;i<=r;i++)
    ans+=dfs(i,1);
  cout<<ans<<endl;
}
