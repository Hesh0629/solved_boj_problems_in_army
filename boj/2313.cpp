#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,l,x;
long long int ans;
vector<long long int>v[1001],prefix_sum[1001];
pair<int,int>ans2[1001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>l;
    for(int j=0;j<l;j++){
      cin>>x;
      v[i].push_back(x);
      if(prefix_sum[i].size()==0) prefix_sum[i].push_back(x);
      else prefix_sum[i].push_back(+prefix_sum[i][j-1]+x);
    }
    int local_ans=-987654321;
    ans2[i]={97654321,987554321};
    for(int j=0;j<prefix_sum[i].size();j++){
      for(int k=j;k<prefix_sum[i].size();k++){
        if(local_ans<prefix_sum[i][k]-prefix_sum[i][j]+v[i][j]){
          ans2[i]={j,k};
          local_ans=prefix_sum[i][k]-prefix_sum[i][j]+v[i][j];
        }
        else if(local_ans==prefix_sum[i][k]-prefix_sum[i][j]+v[i][j]){
          if(k-j<ans2[i].second-ans2[i].first)
            ans2[i]={j,k};
          else if(k-j==ans2[i].second-ans2[i].first){
            if(j<ans2[i].first) ans2[i]={j,k};
          }
        }
      }
    }
    ans+=local_ans;
  }
  cout<<ans<<endl;
  for(int i=0;i<n;i++)
    cout<<ans2[i].first+1<<" "<<ans2[i].second+1<<endl;
  return 0;
}
