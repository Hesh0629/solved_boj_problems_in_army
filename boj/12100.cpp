#include <bits/stdc++.h>
using namespace std;
int n,init[22][22][6],ans,check[22][22][6];
void rec(int idx){
  /*
    dir 0 = up
    dir 1 = down
    dir 2 = left
    dir 3 = right
  */
  for(int dir=0;dir<4;dir++){
    int change=0;
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++) 
        init[i][j][idx+1]=init[i][j][idx];
    }
    if(dir==0){
      for(int j=1;j<=n;j++){
        for(int i=2;i<=n;i++){
          if(init[i][j][idx+1]==0) continue;
          else{
            int flag=0;
            for(int k=i-1;k>=1&&!flag;k--){
              if(init[k][j][idx+1]>0){
                if(init[k][j][idx+1]==init[i][j][idx+1]&&!check[k][j][idx+1]){
                  init[k][j][idx+1]=init[k][j][idx+1]*2;
                  init[i][j][idx+1]=0;
                 check[k][j][idx+1]=1;
                 change=1;
                }
                else if(init[k][j][idx+1]!=init[i][j][idx+1]||check[k][j][idx+1]){
                  int temp=init[i][j][idx+1];
                  init[i][j][idx+1]=0;
                  init[k+1][j][idx+1]=temp;
                  if(k+1!=i) change=1;
                }
                flag=1;
              }
              if(flag) break;
            }
            if(!flag){
              init[1][j][idx+1]=init[i][j][idx+1];
              init[i][j][idx+1]=0;
              change=1;
            }
          }
        }
      }
    }
    else if(dir==1){
      for(int j=1;j<=n;j++){
        for(int i=n-1;i>=1;i--){
          if(init[i][j][idx+1]==0) continue;
          else{
            int flag=0;
            for(int k=i+1;k<=n&&!flag;k++){
              if(init[k][j][idx+1]>0){
                if(init[k][j][idx+1]==init[i][j][idx+1]&&!check[k][j][idx+1]){
                  init[k][j][idx+1]=init[k][j][idx+1]*2;
                  init[i][j][idx+1]=0;
                  check[k][j][idx+1]=1;
                  change=1;                  
                }
                else if(init[k][j][idx+1]!=init[i][j][idx+1]||check[k][j][idx+1]){
                  int temp=init[i][j][idx+1];
                  init[i][j][idx+1]=0;
                  init[k-1][j][idx+1]=temp;
                  if(k-1!=i) change=1;
                }
                flag=1;
              }
              if(flag) break;
            }
            if(!flag){
              init[n][j][idx+1]=init[i][j][idx+1];
              init[i][j][idx+1]=0;
              change=1;
            }
          }
        }
      }
    }
    else if(dir==2){
      for(int i=1;i<=n;i++){
        for(int j=2;j<=n;j++){
          if(init[i][j][idx+1]==0) continue;
          else{
            int flag=0;
            for(int k=j-1;k>=1&&!flag;k--){
              if(init[i][k][idx+1]>0){
                if(init[i][k][idx+1]==init[i][j][idx+1]&&!check[i][k][idx+1]){
                  init[i][k][idx+1]=init[i][k][idx+1]*2;
                  init[i][j][idx+1]=0;
                  check[i][k][idx+1]=1;
                  change=1;
                }
                else if(init[i][k][idx+1]!=init[i][j][idx+1]||check[i][k][idx+1]){
                  int temp=init[i][j][idx+1];
                  init[i][j][idx+1]=0;
                  init[i][k+1][idx+1]=temp;
                  if(k+1!=j) change=1;
                }
                flag=1;
              }
              if(flag) break;
            }
            if(!flag){
              init[i][1][idx+1]=init[i][j][idx+1];
              init[i][j][idx+1]=0;
              change=1;
            }
          }
        }
      }
    }
    else if(dir==3){
      for(int i=1;i<=n;i++){
        for(int j=n-1;j>=1;j--){
          if(init[i][j][idx+1]==0) continue;
          else{
            int flag=0;
            for(int k=j+1;k<=n&&!flag;k++){
              if(init[i][k][idx+1]>0){
                if(init[i][k][idx+1]==init[i][j][idx+1]&&!check[i][k][idx+1]){
                  init[i][k][idx+1]=init[i][k][idx+1]*2;
                  init[i][j][idx+1]=0;
                  check[i][k][idx+1]=1;
                  change=1;
                }
                else if(init[i][k][idx+1]!=init[i][j][idx+1]||check[i][k][idx+1]){
                  int temp=init[i][j][idx+1];
                  init[i][j][idx+1]=0;
                  init[i][k-1][idx+1]=temp;
                  if(k-1!=j) change=1;
                }
                flag=1;
              }
              if(flag) break;
            }
            if(!flag){
              init[i][n][idx+1]=init[i][j][idx+1];
              init[i][j][idx+1]=0;
              change=1;
            }
          }
        }
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        /*if(ans<=init[i][j][idx+1]&&idx==4&&init[i][j][idx+1]==64){
          cout<<endl<<idx+1<<endl;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<init[i][j][idx+1]<<" ";
            cout<<endl;
          }
          cout<<endl;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<init[i][j][idx]<<" ";
            cout<<endl;
          }
          cout<<endl;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<init[i][j][idx-1]<<" ";
            cout<<endl;
          }
          cout<<endl;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<init[i][j][idx-2]<<" ";
            cout<<endl;
          }
          cout<<endl;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<init[i][j][idx-3]<<" ";
            cout<<endl;
          }
          cout<<endl;
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<init[i][j][idx-4]<<" ";
            cout<<endl;
          }
        }*/
        ans=max(ans,init[i][j][idx+1]);
      }
    }
    memset(check,0,sizeof(check));
    if(idx+1!=5&&change) rec(idx+1);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(init,-1,sizeof(init));
  ans=-2;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) cin>>init[i][j][0];
  }
  rec(0);
  cout<<ans<<endl;
}
