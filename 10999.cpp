//10999 구간 합 구하기2 (2020.11.28 D+82, 이병때 푼 마지막 문제)
//예전 방식대로 하면 TLE, Lazy Propagation 이용해야하는 문제
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,base;
typedef struct {
    long long value,lazy;
    int x,y,len,blank=1;
}str;
vector<str>segtree;
void add(int l,int r,int d,int index);
void srch(int l,int r,int index);
void propagate(int index);
long long res(int l,int r);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(base=1;base<n;base*=2);
    segtree.resize(2*base+1);
    for(int i=0;i<n;i++){
        cin>>segtree[base+i].value;
        segtree[base+i].x=i+1;
        segtree[base+i].y=i+1;
        segtree[base+i].len=1;
        segtree[base+i].blank=0;
    }
    for(int i=base-1;i>=0;i--){
        segtree[i].value=segtree[2*i].value+segtree[2*i+1].value;
        if(segtree[2*i].blank==1||segtree[2*i+1].blank==1){
            if(segtree[2*i].blank==1&&segtree[2*i+1].blank==1){
                segtree[base+i].blank=1;
            }
            else if(segtree[2*i].blank==1){
                segtree[i].x=segtree[2*i+1].x;
                segtree[i].y=segtree[2*i+1].y;
                segtree[i].len=segtree[2*i+1].len;
                segtree[base+i].blank=0;
            }
            else{
                segtree[i].x=segtree[2*i].x;
                segtree[i].y=segtree[2*i].y;
                segtree[i].len=segtree[2*i].len;
                segtree[base+i].blank=0;
            }    
        }
        else
            segtree[i].x=segtree[2*i].x;
            segtree[i].y=segtree[2*i+1].y;
            segtree[i].len=segtree[2*i].len+segtree[2*i+1].len;
            segtree[base+i].blank=0;
    }
    for(int i=0;i<2*base+1;i++){
        cout<<"len"<<i<<"="<<segtree[i].len<<endl;
    }
    for(int i=0;i<m+k;i++){
        int a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            add(b-1,c-1,d,1);
        }
        else{
            cin>>b>>c;
            cout<<res(b-1,c-1)<<'\n';
        }
    }
    return 0;
}
void add(int l,int r,int d,int index){
    if(segtree[index].len==1){
        segtree[index].value+=d;
    }
    else if(segtree[index].x==l&&segtree[index].y==r)
        segtree[index].lazy+=d;
    else{
        int half=(segtree[index].x+segtree[index].y)/2;
        if(half>=l)
            add(l,half,d,2*index);
        if(half+1<=r)
            add(half+1,r,d,2*index+1);
    }
}
long long res(int l,int r){
    srch(l,r,1);
    long long ans=0;
    l+=base;
    r+=base;
    while(l<=r){
        if(l%2==1)
            ans+=segtree[l++].value;
        if(r%2==0)
            ans+=segtree[r--].value;
        l/=2;
        r/=2;
        if(l==r){
            ans+=segtree[l].value;
            break;
        }
        else{
            continue;
        }
    }
    return ans;
}
void srch(int l,int r,int index){
    if(segtree[index].lazy!=0){
        propagate(index);
    }
    else{
        if(segtree[index].len!=1){
            int half=(segtree[index].x+segtree[index].y)/2;
            if(half>=l)
                srch(l,half,2*index);
            if(half+1<=r)
                srch(half+1,r,2*index+1);      
        }
    }
}
void propagate(int index){
    segtree[index].value+=segtree[index].lazy*segtree[index].len;
    segtree[index].lazy=0;
    if(segtree[index].len!=1){
        segtree[index*2].lazy=segtree[index].lazy;
        segtree[index*2+1].lazy=segtree[index].lazy;
        propagate(index*2);
        propagate(index*2+1);    
    }
}