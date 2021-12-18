#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,nxt[1000001],pre[1000001];
int a,b;
string s;
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(nxt,0,sizeof(nxt));
  memset(pre,0,sizeof(pre));
  cin>>n>>m;
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    v.push_back(init);
  }
  for(int i=0;i<n;i++){
    if(i==0){
      pre[v[i]]=v[n-1];
      nxt[v[i]]=v[i+1];
    }
    else if(i==n-1){
      pre[v[i]]=v[i-1];
      nxt[v[i]]=v[0];      
    }
    else{
      pre[v[i]]=v[i-1];
      nxt[v[i]]=v[i+1];      
    }
  }
  for(int i=0;i<m;i++){
    cin>>s;
    if(s=="BN"){
      cin>>a>>b;
      cout<<nxt[a]<<endl;
      nxt[b]=nxt[a];
      pre[b]=a;
      pre[nxt[a]]=b;
      nxt[a]=b;
    }
    else if(s=="BP"){
      cin>>a>>b;
      cout<<pre[a]<<endl;
      nxt[b]=a;
      pre[b]=pre[a];
      nxt[pre[a]]=b;
      pre[a]=b;      
    }
    else if(s=="CN"){
      cin>>a;
      int target=nxt[a];
      cout<<target<<endl;
      pre[nxt[target]]=a;
      nxt[a]=nxt[target];
      nxt[target]=0;
      pre[target]=0;
    }
    else if(s=="CP"){
      cin>>a;
      int target=pre[a];
      cout<<target<<endl;
      nxt[pre[target]]=a;
      pre[a]=pre[target];
      nxt[target]=0;
      pre[target]=0;
    }    
  }
}
