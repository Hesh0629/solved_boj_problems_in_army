#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,k,x_1,x_2,y_1,y_2;
int sum[1002][1002][3];
char init[1002][1002];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(sum,0,sizeof(sum));
  memset(init,0,sizeof(init));
  cin>>n>>m;
  cin>>k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++) {
      cin>>init[i][j];
      for(int k=0;k<3;k++){
        sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k];
        if(init[i][j]=='J' && k==0) sum[i][j][k]++;
        else if(init[i][j]=='O' && k==1) sum[i][j][k]++;
        else if(init[i][j]=='I' && k==2) sum[i][j][k]++;
      }
    }
  }
  for(int i=1;i<=k;i++){
    cin>>x_1>>y_1>>x_2>>y_2;
    int jungle = sum[x_2][y_2][0]-sum[x_1-1][y_2][0]-sum[x_2][y_1-1][0]+sum[x_1-1][y_1-1][0];
    int ocean = sum[x_2][y_2][1]-sum[x_1-1][y_2][1]-sum[x_2][y_1-1][1]+sum[x_1-1][y_1-1][1];
    int ice = sum[x_2][y_2][2]-sum[x_1-1][y_2][2]-sum[x_2][y_1-1][2]+sum[x_1-1][y_1-1][2];
    cout<<jungle<<" "<<ocean<<" "<<ice<<endl;
  }
}
