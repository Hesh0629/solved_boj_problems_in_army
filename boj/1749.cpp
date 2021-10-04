#include <bits/stdc++.h>
using namespace std;
long long int n,m,init[202][202],pre[202][202];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(init,0,sizeof(init));
  memset(pre,0,sizeof(pre));
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++) {
      cin>>init[i][j];
      pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+init[i][j];
    }
  }
  long long int ans=-9876543210;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){

      for(int x=0;x<i;x++){
        for(int y=0;y<j;y++)
          ans=max(ans,pre[i][j]-pre[i][y]-pre[x][j]+pre[x][y]);
      }
    }
  }
  cout<<ans<<endl;
}
