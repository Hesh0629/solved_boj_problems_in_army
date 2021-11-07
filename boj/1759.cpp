#include<bits/stdc++.h>
using namespace std;
int l,c;
char input;
vector<char>v,ans;
void rec(int idx,int s){
  if(idx<l){
    if(s>=c)return;
    for(int i=s;i<c;i++){
      ans.push_back(v[i]);
      rec(idx+1,i+1);
      ans.pop_back();
    }
  }
  else{
    int cnt1=0,cnt2=0;
    for(auto i:ans){
      if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u') cnt1++;
      else cnt2++;
    }
    if(cnt1>=1&&cnt2>=2){
      for(auto i:ans)cout<<i;
      cout<<endl;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>l>>c;
  for(int i=0;i<c;i++){
    cin>>input;
    v.push_back(input);
  }
  sort(v.begin(),v.end());
  rec(0,0);
}
