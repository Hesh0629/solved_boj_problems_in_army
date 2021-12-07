// 동전문제의 극악 확장판
// 사탕 종류와 개수를 기억해놓는다.
// 이후에 특정 가격을 만들 수 있는 경우의 수를 저장한다.
// 그런되 메모리제한이 극악이라,,,
#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
set<int>st;
int n,erathos[500001];
long long int dp[2][500001];
vector<int>v;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp,0,sizeof(dp));
  memset(erathos,0,sizeof(erathos));
  cin>>n;
  for(int i=0;i<=500000;i++)erathos[i]=1;
  erathos[0]=0;
  erathos[1]=0;
  for(int i=2;i<=500000;i++){
    if(erathos[i]==0)continue;
    for(int j=2;i*j<=500000;j++){
      erathos[i*j]=0;
    }
  }
  for(int i=0;i<n;i++){
    int init;
    cin>>init;
    mp[init]++;
    st.insert(init);
  }
  int preDp=0,curDp=1;
  for(auto it=st.begin();it!=st.end();it++){
    int cur=*it,cnt=mp[*it];
    for(int j=1;j<=cnt;j++)
      dp[curDp][cur*j]+=1; //현재 사탕종류만으로도 만들 수 있는 거
    for(int i=0;i<=500000;i++){
      dp[curDp][i]+=dp[preDp][i]; //일단 이전 상황을 다 땡겨오자.
      for(int j=1;j<=cnt;j++){
        if(i-cur*j>=0){
          dp[curDp][i]+=dp[preDp][i-cur*j]; // 그리고 현재 사탕종류*(1~ 최대개수)를 더하자
        }
      }
    }
    swap(preDp,curDp);
    memset(dp[curDp],0,sizeof(dp[curDp]));
  }
  long long int ans=0;
  for(int i=2;i<=500000;i++){
    if(erathos[i])
      ans+=dp[preDp][i];
  }
  cout<<ans<<endl;
}
