// modulo 연산 주의
#include <bits/stdc++.h>
#define endl '\n'
#define div 1000000007
using namespace std;
int T,n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>T;
  for(int asdf=0;asdf<T;asdf++){
    cin>>n;
    priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
    for(int i=0;i<n;i++){
      long long int init;
      cin>>init;
      pq.push(init);
    }
    long long int ans=1;
    while(pq.size()>1){
        long long int cur=1;
        cur*=pq.top();
        pq.pop();

        cur*=pq.top();
        pq.pop();

        ans*=cur%div;
        ans%=div;
        pq.push(cur);
    }
    cout<<ans%div<<endl;
  }
  return 0;
}
