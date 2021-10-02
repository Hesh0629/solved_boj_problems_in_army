//맞닿은 부분수열이 중복되지 않으면서 최솟값을 찾는 문제. 간단하게 작은 수(1,2,3으로 숫자 제한)부터 재귀돌리며 틀린 경우 backtracking을 시도하여 1초 이내로 문제풀이가 가능
//실수한 부분: N의 최대값이 80인데 이걸 long long int로 달리다가 망했다. 문자열 비교로 하면 될것을 왜 수식 돌리면서 했을까. 자료형 
#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;
long int res;
char*ans;
int n;
void func1(int num,int index){
    int flag =0;
    if(index==n){
        cout<<ans;
        exit(0);
    }
    else{
        ans[index]=num+48;
        for(int i=index-1,j=1;i>=0;i-=2,j++){
            if(!strncmp(ans+i, ans+index+1-j, j)){
                flag=1;
                ans[index]=0;
                break;
            }
        }
        if(!flag){
            for(int i=1;i<=3;i++)
                func1(i,index+1);
        }
    }
}
int main(){
    cin>>n;
    ans=new char[n+1];
    for(int i=1;i<=3;i++)
        func1(i,0);
    return 0;
}
