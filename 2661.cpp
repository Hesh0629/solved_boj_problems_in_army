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