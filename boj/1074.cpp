#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long int n,r,c;
void rec(long long int cur_n,long long int w,long long int h,long long int time){
	long long int half=pow(2,cur_n-1);
	if(cur_n!=1){
		if(r>=h+half&&c>=w+half){
			h+=half;
			w+=half;
			time+=(long long int)pow(2,cur_n-1)*(long long int)pow(2,cur_n-1)*3;
		}
		else if(r>=h+half&&c<w+half){
			h+=half;
			time+=(long long int)pow(2,cur_n-1)*(long long int)pow(2,cur_n-1)*2;
		}
		else if(r<h+half&&c>=w+half){
			w+=half;
			time+=(long long int)pow(2,cur_n-1)*(long long int)pow(2,cur_n-1)*1;
		}
		rec(cur_n-1,w,h,time);
	}
	else {
		if(r>h&&c>w)
			time+=3;
		else if(r>h&&c<=w)
			time+=2;
		else if(r<=h&&c>w)
			time+=1;
		cout<<time<<endl;
	}
}
int main() {
	cin>>n>>r>>c;
	rec(n,0,0,0);
	return 0;
}
