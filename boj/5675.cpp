#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k,base,segtree[300000],a,b;
char opt;
char query(int x,int y){
  long long int res=1;
  x+=base;
  y+=base;
  while(x<=y){
    if(x%2)res*=segtree[x++];
    if(y%2==0)res*=segtree[y--];
    x/=2;
    y/=2;
    if(x==y){
      res*=segtree[x];
      break;
    }
  }
  if(res>0)return '+';
  else if(res==0) return '0';
  else return '-';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(cin>>n>>k){
    string ans;
    fill_n(segtree,300000,1);
    for(base=1;base<=n;base*=2);
    for(int i=0;i<n;i++){
      int init;
      cin>>init;
      if(init>0)init=1;
      else if(init==0)init=0;
      else init=-1;
      segtree[base+i]=init;
    }
    for(int i=base-1;i>0;i--)
      segtree[i]=segtree[2*i]*segtree[2*i+1];
    for(int i=0;i<k;i++){
      cin>>opt>>a>>b;
      if(opt=='C'){ // 이게 소문자로 되있었음
        if(b>0)b=1;
        else if(b==0)b=0;
        else b=-1;
        segtree[base+a-1]=b;
        for(int j=(base+a-1)/2;j>0;j/=2)
          segtree[j]=segtree[2*j]*segtree[2*j+1];
      }
      else if(opt=='P')ans.push_back(query(a-1,b-1));
    }
    cout<<ans<<endl;
  }
}
