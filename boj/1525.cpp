//BFS와 브루트포스 그 사이 어딘가였던 문제
//visit 체크를하려고 배열 썻다간 메모리초과가 난다.
//핵심은 3*3 배열을 1*9로 쭉 펴버리는것.
//더 나아가 visit 체크를 1*9 배열을 하나의 숫자로 봐서 처리하면 OK
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int table[5][5],x,y;
set<int>vis;
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(table,-1,sizeof(table));
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      cin>>table[i][j];
      if(table[i][j]==0){
        table[i][j]=9;
        x=i;
        y=j;
      }
      v.push_back(table[i][j]);
    }
  }
  queue<pair<pair<int,int>,pair<vector<int>,int>>>q;
  q.push({{x,y},{v,0}});
  v.shrink_to_fit();
  while(!q.empty()){
    int cur_x=q.front().first.first,cur_y=q.front().first.second,time=q.front().second.second;
    vector<int>v=q.front().second.first;
    q.pop();
    int temp[5][5];
    memset(temp,-1,sizeof(temp));
    int ans=1;
    for(int i=0;i<9;i++) {
      temp[i/3+1][i%3+1]=v[i];
      if(v[i]!=i+1) ans=0;
    }
    v.shrink_to_fit();
    if(ans){
      cout<<time<<endl;
      return 0;
    }
    for(int i=0;i<4;i++){
      if(temp[cur_x+dx[i]][cur_y+dy[i]]!=-1){
        int next[5][5];
        for(int a=0;a<5;a++){
          for(int b=0;b<5;b++) next[a][b]=temp[a][b];
        }
        next[cur_x][cur_y]=next[cur_x+dx[i]][cur_y+dy[i]];
        next[cur_x+dx[i]][cur_y+dy[i]]=9;
        vector<int>nv(9);
        int idx=0;
        for(int k=0;k<9;k++) {
          nv[k]=next[k/3+1][k%3+1];
          idx+=(int)pow(10,8-k)*nv[k];
        }
        if(vis.find(idx)==vis.end()){
          q.push({{cur_x+dx[i],cur_y+dy[i]},{nv,time+1}});
          vis.insert(idx);
        }
        nv.shrink_to_fit();
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
