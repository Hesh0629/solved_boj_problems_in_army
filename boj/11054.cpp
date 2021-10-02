//바이토닉 수열 증가하는 수열의 길이와 감소하는 수열의 길이를 각각구한 후 길이의 합이 긴 것을 구하면 
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

int main() {
 cin.tie(NULL);
 cout.tie(NULL);
 ios_base::sync_with_stdio(false);
 int n;
 cin>>n;
 int*arr=new int[n];
 int*as=new int[n]; // i 번째에서 증가하는 수열의 길이
 int*ds=new int[n]; // i 번째에서 감소하는 수열의 길이
 int cur_max=-1;
 for(int i=0;i<n;i++){
     cin>>arr[i];
     int temp_max=0;
     for(int j=0;j<i;j++){
        if(arr[j]<arr[i])
            temp_max=max(temp_max,as[j]);
     }
     as[i]=temp_max+1;
 }
 for(int i=n-1;i>=0;i--){
     int temp_max=0;
     for(int j=i+1;j<n;j++){
        if(arr[j]<arr[i])
            temp_max=max(temp_max,ds[j]);
     }
     ds[i]=temp_max+1;
     cur_max=max(as[i]+ds[i]-1,cur_max);
 }
 cout<<cur_max;
}
