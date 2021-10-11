#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<unsigned long long int>v(1000001,0);
int check[1000001],vis[1000001];
vector<int>prime;
int t,x;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(check,0,sizeof(check));
  memset(vis,0,sizeof(vis));

  // 소수가 아니면 1 맞으면 0
  for(int i=2;i<=sqrt(1000000);i++){
    if(check[i]) continue;
    prime.push_back(i);
    for(int j=2;i*j<=(1000000);j++) check[i*j]=1;
  }

  for(int i=1;i<=1000000;i++){
    /* TLE가 난 코드. 전체에 대하여 N(sqrt(N)) 이였는데 터졌었다.
    if(i==1) v[i]=1;
    else if(!check[i])
      v[i]+=(1+i);
    else{
      for(int j=1;j<=sqrt(i);j++)
        if(i%j==0 && j*j!=i) v[i]+=(j+i/j);
        else if(i%j==0 && j*j==i) v[i] +=j;
    }
    */

    // NlogN으로 접근한 코드. 이건 통과
    for(int j=1;j<=1000000/i;j++) v[i*j]+=i;
    if(i!=1) v[i]+=v[i-1];
  }
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>x;
    cout<<v[x]<<endl;
  }
}
