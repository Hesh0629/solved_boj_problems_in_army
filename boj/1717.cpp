// union find 구현인데 메모리 초과를 우려해서 shrink_to_fit()을 넣었다가 O(N)인걸 몰라서 TLE
// 그리고 b,c각각이 '속한' 집합 번호를 찾아야한다.
#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;
vector<int>s[1000001];
int mem[1000001];
int n,m,a,b,c;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(int i=0;i<=n;i++){
    s[i].push_back(i);
    mem[i]=i;
  }
  for(int cur=0;cur<m;cur++){
    cin>>a>>b>>c;
    if(a==0){
      if(mem[b]==mem[c]);
      else if(s[mem[b]].size()<s[mem[c]].size()){
        for(auto i:s[mem[b]]){
          s[mem[c]].push_back(i);
          mem[i]=mem[c];
        }
        //s[mem[b]].shrink_to_fit();
      }
      else{
        for(auto i:s[mem[c]]){
          s[mem[b]].push_back(i);
          mem[i]=mem[b];
        }
       // s[mem[c]].shrink_to_fit();
      }
    }
    else{
      if(mem[b]==mem[c]) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
}
