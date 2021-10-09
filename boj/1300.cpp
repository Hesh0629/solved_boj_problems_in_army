#include <bits/stdc++.h>
using namespace std;
long long int n,k;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  cin>>k;
  long long int x=1,y=k,half,ans;
  while(x<=y){
    half=(x+y)/2;
    long long int cur=0;
    /*  
      i번째 행에서 half값보다 작거나 같은 수의 개수를 구한다.
      min( half / i , n ) 이 나오는데 각 행이 i*j의 형태이므로 half/i가 결과값이 되거나 n이 된다.
    */
    for(int i=1;i<=n;i++)
      cur+=min(half/i,n);
    // 이를 찾기 위하여 이분탐색 진행
    if(cur<k) x=half+1;
    else if(cur>=k){
      //단, k보다 크거나 같으면 현재값이 정답일 수 있으니까 저장해둔다. 위에서 k보다 작은경우에는 택도 없으니까 상관없다.
      ans=half;
      y=half-1;
    }
  }
  cout<<ans<<endl;
  return 0;
}
