#include<bits/stdc++.h>
using namespace std;
int n,init;
multiset<int>ms;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>init;
    auto iter=ms.find(init+1);
    ms.insert(init);
    //현재 쏜 화살중에 자신의 높이+1이 있다면 터트릴 수 있다
    if(iter!=ms.end())ms.erase(iter);
  }
  //지워지지않고 남은 multiset 원소들이 화살개수
  cout<<ms.size()<<endl;
}
