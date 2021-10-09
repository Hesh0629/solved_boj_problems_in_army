// unsigned long long int -> 0~ 2^64-1
// overflow가 나면 자연스럽게 2^64로 나누는것과 같다.
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
unsigned long long int n,m,total,x,total_gap,personal_gap,remained;
vector<unsigned long long int>v,gap;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>m>>n;
  gap.resize(n,0);
  total=0;
  for(int i=0;i<n;i++){
    cin>>x;
    total+=x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  total_gap=total-m;
  for(int i=0;i<n;i++){
     if(v[i]*(n-i)==total_gap){
       for(int j=i;j<n;j++)
         gap[j]=v[i];
       break;
     }
     else if(v[i]*(n-i)<total_gap){
       gap[i]=v[i];
       total_gap-=v[i];
     }
    else{
       personal_gap=total_gap/(n-i);
       remained=total_gap%(n-i);
       for(int j=i;j<n;j++){
         gap[j]=personal_gap;
         if(remained>0){
           gap[j]++;
           remained--;
         }
      }
      break;
    }
  }
  unsigned long long int ans=0;
  for(auto i:gap)
    ans+=(i*i);
  cout<<ans<<endl;
}
