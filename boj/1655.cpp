#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,mid,input;
priority_queue<int,vector<int>,greater<int>>max_q;
priority_queue<int,vector<int>,less<int>>min_q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>input;
    if(i==0) {
      mid=input;
      cout<<mid<<endl;
    }
    else if(i%2==0){
      if(input>=mid) max_q.push(input);
      else min_q.push(input);

      if(min_q.size()<max_q.size()){
        min_q.push(mid);
        mid=max_q.top();
        max_q.pop();
      }
      else if(min_q.size()>max_q.size()){
        max_q.push(mid);
        mid=min_q.top();
        min_q.pop();
      }
      cout<<mid<<endl;
    }
    else{
      if(input>=mid) max_q.push(input);
      else min_q.push(input);

      if(min_q.size()<max_q.size()) cout<<mid<<endl;
      else cout<<min_q.top()<<endl;
    }
  }
}
