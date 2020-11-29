//10999 구간 합 구하기2 (2020.11.29 D+83, 이병때 푼 마지막 문제)
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
    //--------------tree생성 부분--------------
    for(base=1;base<n;base*=2);
    segtree.resize(2*base+1);
    for(int i=0;i<n;i++){
        cin>>segtree[base+i].value;
        segtree[base+i].x=i;
        segtree[base+i].y=i;
        segtree[base+i].len=1;
        segtree[base+i].blank=0;
    }
    for(int i=base-1;i>=0;i--){
        segtree[i].value=segtree[2*i].value+segtree[2*i+1].value;
        if(segtree[2*i].blank==1&&segtree[2*i+1].blank==1){
            segtree[i].blank=1;
        }
        else if(segtree[2*i].blank==1){
            segtree[i].x=segtree[2*i+1].x;
            segtree[i].y=segtree[2*i+1].y;
            segtree[i].len=segtree[2*i+1].len;
            segtree[i].blank=0;
        }
        else if(segtree[2*i+1].blank==1){
            segtree[i].x=segtree[2*i].x;
            segtree[i].y=segtree[2*i].y;
            segtree[i].len=segtree[2*i].len;
            segtree[i].blank=0;
        }    
        else{
            segtree[i].x=segtree[2*i].x;
            segtree[i].y=segtree[2*i+1].y;
            segtree[i].len=segtree[2*i].len+segtree[2*i+1].len;
            segtree[i].blank=0;
        }
    }
    //-------------------------------------------
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
void add(int l,int r,int d,int index){ //들어온 lazy를 노드 정보에 더해주는 함수
    if(segtree[index].len==1){
        segtree[index].value+=d;
    }
    else if(segtree[index].x==l&&segtree[index].y==r)
        segtree[index].lazy+=d;
    else{
        int half=segtree[index*2].x+segtree[index*2].len-1;
        if(r<=half)
            add(l,r,d,2*index);
        else if(l>=half+1)
            add(l,r,d,2*index+1);
        else{
            add(l,half,d,2*index);
            add(half+1,r,d,2*index+1);
        }
    }
}
long long res(int l,int r){ //구간 합을 구하는 함수
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
void srch(int l,int r,int index){//구간합을 내기위해 탑 다운으로 가다가 lazy를 만나면 propagate하며 업데이트 해주는 함수
    if(segtree[index].lazy!=0){
        propagate(index);
    }
    else{
        if(segtree[index].len!=1){
            int half=segtree[index*2].x+segtree[index*2].len-1;
            if(r<=half)
                srch(l,r,2*index);
            else if(l>=half+1)
                 srch(l,r,2*index+1);
            else{
                srch(l,half,2*index);
                srch(half+1,r,2*index+1);
            }
            segtree[index].value=segtree[index*2].value+segtree[index*2+1].value;
        }    
    }
}
void propagate(int index){
    segtree[index].value+=segtree[index].lazy*segtree[index].len;
    if(segtree[index].len!=1){
        segtree[index*2].lazy=segtree[index].lazy;
        segtree[index*2+1].lazy=segtree[index].lazy;
        segtree[index].lazy=0;
        propagate(index*2);
        propagate(index*2+1);
    }
    else{
        segtree[index].lazy=0;
    }
}