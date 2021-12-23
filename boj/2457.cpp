#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,pair<int,int>>>v;
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    v.push_back({{a,b},{c,d}});
  }
  sort(v.begin(),v.end());
  pair<int,int>cur={3,1},temp={3,1};
  int ans=0;
  for(int i=0;i<n;i++){
    int sm=v[i].first.first,sd=v[i].first.second,em=v[i].second.first,ed=v[i].second.second;
    if(em<3||(em==3&&ed==1))continue;
    if(sm<cur.first||(sm==cur.first&&sd<=cur.second)){
      temp=max(temp,make_pair(em,ed));
      if(temp>make_pair(11,30)){
        ans++;
        break;
      }
    }
    else{
      ans++;
      cur=temp;
      if(cur<make_pair(sm,sd)){
        ans=0;
        break;
      }
      if(cur>make_pair(11,30))break;
      temp=max(temp,make_pair(em,ed));
      if(make_pair(em,ed)>make_pair(11,30)){
        ans++;
        break;
      }
    }
  }
  if(temp<=make_pair(11,30)){
    ans=0;
  }
  cout<<ans<<endl;
}
