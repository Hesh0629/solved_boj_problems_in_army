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
  long int max;
  cin>>max;
  long int prime_max=(long int)sqrt(max);
  bool* primelist= new bool[max+1];
  for(int i=0;i<=prime_max;i++){
	  primelist[i]=false;
  }
  primelist[1]=true;
  primelist[2]=true;
  for(int i=2;i<=prime_max;i++){
	  if(primelist[i]==true){
		  for(int j=i*2;j<=max;j+=i){
			  primelist[j]=false;
			}
  		}
	}
}
