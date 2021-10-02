//segment tree를 이용하여 구간합을 빠르게 구하고 중간에 수정도 가능한 트리를 배열을 활용하여 구현
#include<iostream>
#include<vector>
using namespace std;
vector<long long int>tree;
int base;
long long int sum(int i,int j);
void mod(int i,int k);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(base=1;base<n;base*=2); // Base는 n보다 작은 2의 제곱수로 구함
    tree.clear();
    tree.resize(2*base+1); // 트리(배열)의 크기는 2*Base+1
    for(int k=0;k<m;k++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            cout<<sum(b-1,c-1)<<'\n';
        }
        else{
            mod(b-1,c);
        }
    }
}
long long int sum(int i,int j){ //[i,j] 구간의 합을 구함 (단 i<j)
    long long int res=0;
    if(i>j){
        int temp=i;
        i=j;
        j=temp;
    }
    int l=i+base,r=j+base;
    while(l<=r){
        if(l%2==1)
            res+=tree[l++]; //left index가 트리의 오른쪽에 위치하는 경우 그 위의 부분은 이용하지 않으므로 해당 값을 결과에 더하고 l++을 하여 옆으로 넘어감
        if(r%2==0)
            res+=tree[r--]; //위와 상이
        l/=2;
        r/=2;
        if(l==r){ //만약 left와 right가 만나면 그 값 tree[l=r]이 우리가 구하고자하는 구간의 합을 들고 있으므로 결과에 더함
            res+=tree[l];
            break;
        }
        else{
            continue;
        }
    }
    return res;
}
void mod(int i,int k){
    long long int gap=k-tree[i+base]; //바꾸고자 하는값 k와 원래 있던 값의 차이 gap을 구함
    for(int j=base+i; j; j/=2){
        tree[j]+=gap; //값을 바꾼 영향은 바로 위 부모에만 영향을 미치므로 차이 gap을 더해주면서 빠르게 업데이트
    }
}