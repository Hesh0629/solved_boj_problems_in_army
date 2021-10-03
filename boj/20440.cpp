#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,a,b;
deque<int>enter,out;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    enter.push_back(a);
    out.push_back(b);
  }
  sort(enter.begin(),enter.end());
  sort(out.begin(),out.end());
  int cur=0,mos=0,eoe=0;
  pair<int,int>ans;
  while(!(enter.empty()&&out.empty())){
    if(enter.empty()){
      if(eoe) ans.second=out.front();
      break;
    }
    else if(enter.front()<out.front()){
      cur++;
      if(cur>mos){
        eoe=1;
        ans.first=enter.front();
        mos=cur;
      }
      enter.pop_front();
    }
    else  if(enter.front()>out.front()){
      cur--;
      if(eoe){
        ans.second=out.front();
        eoe=0;
      }
      out.pop_front();
    }
    else{
      enter.pop_front();
      out.pop_front();
    }
  }
  cout<<mos<<endl<<ans.first<<" "<<ans.second<<endl;
}
