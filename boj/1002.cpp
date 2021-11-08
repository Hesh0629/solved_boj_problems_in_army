#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,ax,ay,ar,bx,by,br;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for(int asdf=0;asdf<n;asdf++){
    cin>>ax>>ay>>ar>>bx>>by>>br;
    long double dist=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    if(dist==0&&ar==br) cout<<-1<<endl;
    else if(dist==(long double)(ar+br)) cout<<1<<endl;
    else if(dist+ar==br||dist+br==ar) cout<<1<<endl;
    else if(dist+ar<br||dist+br<ar) cout<<0<<endl;
    else if(dist>ar+br) cout<<0<<endl;
    else cout<<2<<endl;
  }
}
