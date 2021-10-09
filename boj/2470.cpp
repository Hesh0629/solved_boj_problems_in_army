// 기존 용액 문제 풀때보다 메모리, 시간을 개선한 버전
#include <bits/stdc++.h>
using namespace std;
int n,x;
pair<int,int>ans;
vector<int>v;
int trans(int input){
  return (input>0)?input:-input;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  ans={1000000001,1000000001};
  for(int i=0;i<n;i++){
    auto iter=lower_bound(v.begin()+i+1,v.end(),-v[i]);
    if(iter==v.end()){
      if(v[i]!=v.back()&&trans(v[i]+v.back())<trans(ans.first+ans.second)) ans={v[i],v.back()};
    }
    else if(*iter==-v[i]){
      cout<<v[i]<<" "<<*iter<<endl;
      return 0;
    }
    else if(iter-1==v.begin()+i){
      if(trans(v[i]+*iter)<trans(ans.first+ans.second))
        ans={v[i],*iter};
    }
    else{
      if(trans(v[i]+*iter)<trans(v[i]+*(iter-1))&&trans(v[i]+*iter)<trans(ans.first+ans.second))
        ans={v[i],*iter};
      else if(trans(v[i]+*iter)>trans(v[i]+*(iter-1))&&trans(v[i]+*(iter-1))<trans(ans.first+ans.second))
        ans={v[i],*(iter-1)};
    }
  }
  cout<<ans.first<<" "<<ans.second<<endl;
}
