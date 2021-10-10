#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char board[9][9],init;
int row[9][10],col[9][10],box[9][10];
vector<pair<int,int>>v;
void rec(int idx){
  int x=v[idx].first,y=v[idx].second;
  for(int i=1;i<=9;i++){
    if(row[x][i]==0 && col[y][i]==0 && box[(x/3)*3+y/3][i]==0){
      board[x][y]=i;
      row[x][i]=1;
      col[y][i]=1;
      box[(x/3)*3+y/3][i]=1;
      if(idx==v.size()-1){
        for(int a=0;a<9;a++){
          for(int b=0;b<9;b++) 
            cout<<((int)board[a][b]);
          cout<<endl;
        }
        exit(0);
      }
      else{
        rec(idx+1);
        board[x][y]=0;
        row[x][i]=0;
        col[y][i]=0;
        box[(x/3)*3+y/3][i]=0;
      }
    }
  }
}
int main(){
  //ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(board,0,sizeof(board));
  memset(row,0,sizeof(row));
  memset(col,0,sizeof(col));
  memset(box,0,sizeof(box));
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin>>init;
      board[i][j]=init-'0';
      if(board[i][j]!=0){
        row[i][board[i][j]]=1;
        col[j][board[i][j]]=1;
        box[(i/3)*3+j/3][board[i][j]]=1;
      }
      else
        v.push_back({i,j});
    }
  }
  rec(0);
}
