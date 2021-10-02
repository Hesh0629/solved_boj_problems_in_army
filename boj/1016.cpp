//제곱 ㄴㄴ수
//에라토스테네스의 체를 응용하여 제곱 ㅇㅇ 수들을 제거 + count 답 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include<math.h>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  long int min,max;
  cin>>min>>max;
  bool*list=new bool[max-min+2];
  for(long int i=0;i<max-min+2;i++){
      list[i]=true;
  }
  long int start=min;
  long int res=max-min+1;
  for(long int i=2;i*i<=max;i++){
	long int target;
	if(start%(i*i)==0){
		target=start;
        start+=1;
	}
	else{
        target = start+((i*i)-start%(i*i));
	}
	for(long int j=target;j<=max;j+=i*i){
        if(list[j-min]==true){
            list[j-min]=false;
            res-=1;
        }
	}
  }
  cout<<res;
  return 0;
}
