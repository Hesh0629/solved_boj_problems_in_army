// ...그냥 구현문제에 더 가까웠다.
#include<bits/stdc++.h>
using namespace std;
long long int n,one=INT_MAX,two=INT_MAX,three=INT_MAX,big=0,ans=0;
vector<long long int>v(6);
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<6;i++){
    cin>>v[i];
    one=min(one,v[i]);
  }
  for(int i=0;i<6;i++){
    for(int j=i+1;j<6;j++){
      if(!(i==0&&j==5)&&!(i==1&&j==4)&&!(i==2&&j==3))
        two=min(two,v[i]+v[j]);
    }
  }
  three=min(three,v[0]+v[3]+v[4]);
  three=min(three,v[0]+v[1]+v[3]);
  three=min(three,v[0]+v[2]+v[4]);
  three=min(three,v[0]+v[1]+v[2]);
  three=min(three,v[1]+v[3]+v[5]);
  three=min(three,v[1]+v[2]+v[5]);
  three=min(three,v[2]+v[4]+v[5]);
  three=min(three,v[3]+v[4]+v[5]);
  if(n==1){
    for(auto i:v) {
      big=max(big,i);
      ans+=i;
    }
    ans-=big;
  }
  else{
    ans+=one*(n-1)*(n-2)*4+one*(n-2)*(n-2);
    ans+=two*(n-1)*4+two*(n-2)*4;
    ans+=three*4;
  }
  cout<<ans<<endl;
}
