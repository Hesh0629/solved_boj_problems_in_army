#include<bits/stdc++.h>
using namespace std;
int n;
long long int sum=0,cnt=0,ans=0;
vector<long long int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    long long int init;
    cin>>init;
    v.push_back(init);
  }
  sort(v.begin(),v.end(),greater<>());
  for(auto i:v){
    if((sum+i)*(cnt+1)>=sum*cnt+i){
      sum+=i;
      cnt++;
    }
    else ans+=i;
  }
  cout<<ans+sum*cnt<<endl;
}
