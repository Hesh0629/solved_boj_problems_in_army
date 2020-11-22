//1725 히스토그램. 세그먼트 트리를 이용하여 구간의 최소 높이를 저장.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>tree1;//높이 저장
vector<int>tree2;//인덱스 저장
int n;
int base,ans;
void rec(int start,int end);
int srch(int l,int r);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ans=-1;
    cin>>n;
    for(base=1;base<n;base*=2);
    tree1.clear();
    tree1.assign(2*base+1,1000000001);
    tree2.clear();
    tree2.assign(2*base+1,1000000001);
    for(int i=0;i<n;i++){
        cin>>tree1[base+i];
        tree2[base+i]=i;
    }
    for(int i=base-1;i>0;i--){
        tree1[i]=min(tree1[2*i],tree1[2*i+1]);
        if(tree1[i]==tree1[2*i])
            tree2[i]=tree2[2*i];
        else
            tree2[i]=tree2[2*i+1];
    }
    rec(0,n-1);
    cout<<ans;
}
void rec(int start,int end){
    int len=end-start+1;
    int index=srch(start,end);
    int h=tree1[base+index]; //틀렸던 부분...index 즉 srch의 반환형은 0~n-1사이 인덱스
    if(start>end){
        return;
    }
    if(ans<len*h)
        ans=len*h;
    if(len!=1){
        if(index-1>=0&&index-1<=n-1)
            rec(start,index-1);
        if(index+1>=0&&index+1<=n-1)
            rec(index+1,end);   
    }
}
int srch(int l,int r){
    l+=base;
    r+=base;
    int res=l;
    while(l<=r){
        if(l%2==1){
            if(tree1[l]<tree1[res])
                res=l;
            l++;
        }
        if(r%2==0){
            if(tree1[r]<tree1[res])
                res=r;
            r--;
        }
        l/=2;
        r/=2;
        if(l==r){
            if(tree1[l]<tree1[res])
                res=l;
            break;
        }
    }
    return tree2[res];
}
