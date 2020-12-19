//2020.12.19 일병되고 푼 첫문제
//간단하게 최대한 3으로 나누려다가 결국 dp로 푼 문제 (쉽긴한데 왜 3으로 나누는게 정해가 아닌지 모르겠다)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int cur=0;
    vector<int>arr(n+1,0);
    arr[n]=0;
    for(int i=n-1;i>=1;i--){
        if(i*3<=n)
            arr[i]=min(arr[i+1],min(arr[i*2],arr[i*3]))+1;
        else if(i*2<=n)
             arr[i]=min(arr[i+1],arr[i*2])+1;
        else
            arr[i]=arr[i+1]+1;
    }
    cout<<arr[1];
}
