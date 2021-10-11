/*
  2진수의 i번째 자리수는 N에 대하여 N/(2^i)+ (n%(2^i)-n/2) 만큼 나온다.
  이거 하나만 알면 나머진 누적합 문제,,,
*/
#include <bits/stdc++.h>
using namespace std;
unsigned long long int a,b;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>a>>b;
  b++;
  vector<unsigned long long int>v1(55,0),v2(55,0);
  for(int i=1;i<=54;i++){
    v1[i]=(b/(unsigned long long int)(pow(2,i)))*(unsigned long long int)(pow(2,i-1));
    if(b%(unsigned long long int)(pow(2,i))){
      if((b%(unsigned long long int)(pow(2,i)))>(unsigned long long int)(pow(2,i))/2)
        v1[i]+=(b%(unsigned long long int)(pow(2,i)))-(unsigned long long int)(pow(2,i))/2;
    }
    v2[i]=(a/(unsigned long long int)(pow(2,i)))*(unsigned long long int)(pow(2,i-1));
    if(a%(unsigned long long int)(pow(2,i))){
      if((a%(unsigned long long int)(pow(2,i)))>(unsigned long long int)(pow(2,i))/2)
        v2[i]+=(a%(unsigned long long int)(pow(2,i)))-(unsigned long long int)(pow(2,i))/2;
    }
  }
  unsigned long long int ans=0;
  for(auto i:v1) ans+=i;
  for(auto i:v2) ans-=i;
  cout<<ans;
}
