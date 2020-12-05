//10999 구간 합 구하기2 (2020.11.29 D+83, 이병때 푼 마지막 문제)
//예전 방식대로 하면 TLE, Lazy Propagation 이용해야하는 문제
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000010
long long arr[MAX];
using namespace std;
int n,m,k,base;
typedef struct {
    long long value,lazy;
}str;
vector<str>segtree;
void update(int l,int r,int nl,int nr,long long diff,int index); //들어온 lazy를 노드 정보에 더해주는 함수
long long res(int l,int r,int nl,int nr, int index);  //구간합을 내기위해 탑 다운으로 가다가 lazy를 만나면 propagate하며 업데이트 해주는 함수
long long init(int nl, int nr,int index);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    //--------------tree생성 부분--------------
    for(base=1;base<n;base*=2);
    segtree.resize(2*base+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    init(0,n-1,1);
    //-------------------------------------------
    for(int i=0;i<m+k;i++){
        long long a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            update(b,c,1,n,d,1);
        }
        else{
            cin>>b>>c;
            cout<<res(b,c,1,n,1)<<'\n'; 
        }
    }
    return 0;
}

long long init(int nl, int nr,int index){
    if(nl==nr){
        return segtree[index].value=arr[nl];
    }
    else{
        int half=(nl+nr)/2;
        return segtree[index].value=init(nl,half,index*2)+init(half+1,nr,index*2+1);
    }
}

void update(int l,int r,int nl,int nr,long long diff,int index){ //들어온 lazy를 노드 정보에 더해주는 함수
    if(segtree[index].lazy!=0){
        segtree[index].value+=segtree[index].lazy*(nr-nl+1);
        if(nr!=nl){
            segtree[index*2].lazy+=segtree[index].lazy;
            segtree[index*2+1].lazy+=segtree[index].lazy;
        }
        segtree[index].lazy=0;
    } 
    if(nl>r||nr<l) return;
    else if(nl>=l&&nr<=r){
        if(nl==nr) segtree[index].value+=diff;
        else segtree[index].lazy+=diff;
    }
    else{
        int half=(nl+nr)/2;
        update(l,r,nl,half,diff,2*index);
        update(l,r,half+1,nr,diff,2*index+1);
        segtree[index].value=segtree[index*2].value+segtree[index*2+1].value;
    }
}

long long res(int l,int r,int nl,int nr, int index){ //구간합을 내기위해 탑 다운으로 가다가 lazy를 만나면 propagate하며 업데이트 해주는 함수
    long long len=nr-nl+1;
    if(segtree[index].lazy!=0){
        segtree[index].value+=(segtree[index].lazy)*(len);
        if(len!=1){
            segtree[index*2].lazy+=segtree[index].lazy;
            segtree[index*2+1].lazy+=segtree[index].lazy;
        }
        segtree[index].lazy=0;
    }
    if(nl>r||nr<l) return 0; 
    if(nl>=l&&nr<=r) return segtree[index].value;
    return res(l,r,nl,(nl+nr)/2,2*index) + res(l,r,(nl+nr)/2+1,nr,2*index+1);
}
