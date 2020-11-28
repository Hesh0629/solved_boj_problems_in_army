#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,base;
vector<long long>segtree;
void add(int l,int r,int d);
long long res(int l,int r);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(base=1;base<n;base*=2);
    segtree.resize(2*base+1);
    for(int i=0;i<n;i++){
        cin>>segtree[base+i];
    }
    for(int i=base-1;i>=0;i--){
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
    for(int i=0;i<m+k;i++){
        int a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            add(b-1,c-1,d);
        }
        else{
            cin>>b>>c;
            cout<<res(b-1,c-1)<<'\n';
        }
    }
}
void add(int l,int r,int d){
    for(int i=l;i<=r;i++){
        for(int j=base+i;j;j/=2)
            segtree[j]+=d;
    }
}
long long res(int l,int r){
    long long ans=0;
    l+=base;
    r+=base;
    while(l<=r){
        if(l%2==1)
            ans+=segtree[l++];
        if(r%2==0)
            ans+=segtree[r--];
        l/=2;
        r/=2;
        if(l==r){
            ans+=segtree[l];
            break;
        }
        else{
            continue;
        }
    }
    return ans;
}