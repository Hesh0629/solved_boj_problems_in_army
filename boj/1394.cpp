// 식만 떠올리면 O(N)스케일로 풀 수 있는 문제
// 현재길이가 K이면 ans+=(사용가능한 문자 개수)^(k-1)*(현재 문자의 번호
#include<bits/stdc++.h>
#define endl '\n'
#define div 900528
using namespace std;
string s;
string s2;
vector<int>list;
map<char,int>mp;
int mul[1000001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  mul[0]=1;
  cin>>s;
  for(int i=0;i<s.size();i++)
    mp[s[i]]=i+1;
  cin>>s2;
  long long int ans=0;
  for(int i=1;i<=1000000;i++)
    mul[i]=(mul[i-1]*mp.size())%div;
  for(int i=0;i<s2.size();i++){
    int idx=s2.size()-i;
    ans+=(mul[idx-1]*mp[s2[i]])%div;
  }
  cout<<ans%div<<endl;
}
