#include <bits/stdc++.h>
using namespace std;
int k, init[50][50], dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
long double p[4],n,s,w,e;
long double dfs(int x,int y,int time,long double percent){
  if(time==k) return percent;
  if(init[x][y]) return 0;
  init[x][y]=1; // 일단 여기 순서에서 틀렸다.
  /*
  if(init[x][y]) return 0;
  init[x][y]=1;
  if(time==k) return percent; 
  이 코드는 틀리는 코드이다.
  생각해보니 이러면 해제안하고 도망간다. */

  long double ret=0;
  for(int i=0;i<4;i++){
    if(init[x+dx[i]][y+dy[i]]) continue;
    ret+=dfs(x+dx[i],y+dy[i],time+1,percent*p[i]);
  }
  init[x][y]=0;
  //cout<<x<<" "<<y<<" "<<time<<" "<<ret<<endl;
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(init,0,sizeof(init));
  cin>>k>>e>>w>>s>>n;
  p[0]=w/100;p[1]=e/100;p[2]=n/100;p[3]=s/100;
  cout.precision(11);
  cout<<fixed; //???????????????????????????????????????
  cout<<dfs(25,25,0,1); 
}
