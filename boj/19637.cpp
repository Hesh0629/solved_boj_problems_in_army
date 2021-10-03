// 어째 구간합 문제를 점점 큐,덱 구조로 푸는게 더 쉬워진다.
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int l,ml,mk,c,x,used;
queue<int>q,out;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>l;
  cin>>ml>>mk;
  cin>>c;
  for(int i=0;i<l;i++){
    cin>>x;
    q.push(x);
  }
  used=0;
  for(int i=0;i<l;i++){
    int cur=q.front();
    q.pop();
    if(i<ml) cur-=mk*(i+1);
    else cur-=mk*ml;
    if(!out.empty()){
      if(out.front()<i){
        used--;
        out.pop();
      }
    }    
    if(used>0) cur+=used*mk;
    if(!out.empty()){
      if(out.front()==i){
        used--;
        out.pop();
      }
    }
    if(cur>0){
      if(!c){
        cout<<"NO"<<endl;
        return 0;
      }
      else{
        out.push(i+ml-1);
        c--;
        used++;
      }
    }
  }
  cout<<"YES"<<endl;
}
