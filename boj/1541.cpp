#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
char stored;
int ans=0;
int temp=0;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  stored=' ';
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9')
      v.push_back(s[i]-'0');
    else{
      int number=0;
      for(int j=0;j<v.size();j++) number+=(int)pow(10,v.size()-1-j)*v[j];
      //cout<<number<<" "<<s[i]<<endl;
      v.resize(0);
      if(stored==' '||stored=='+') {
        ans+=number;
        stored=s[i];
      }
      else{
        if(s[i]=='+'){
          temp+=number;
        }
        else{
          ans-=number;
          ans-=temp;
          temp=0;
        }
      }
    }
  }
  int number=0;
  for(int j=0;j<v.size();j++) number+=(int)pow(10,v.size()-1-j)*v[j];
  if(stored==' '||stored=='+') 
    ans+=number;
  else ans-=number;
  ans-=temp;
  cout<<ans<<endl;
}
