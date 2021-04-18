// 무지성 피보나치 ...멈춰! 행렬로 풀어보자
// + 나눗셈에서 나머지의 성질을 이용하여 처리하자
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define big 1000000007;
using namespace std;

struct mat{ //2*2 행렬 정의
	long long data[2][2];
};
mat mul(mat a,mat b){ //행렬곱 정의
	mat res;
	res.data[0][0]=(a.data[0][0]*b.data[0][0]+a.data[0][1]*b.data[1][0])%big; //나머지의 성질에 의해 미리미리 나눠줌
	res.data[0][1]=(a.data[0][0]*b.data[0][1]+a.data[0][1]*b.data[1][1])%big;
	res.data[1][0]=(a.data[1][0]*b.data[0][0]+a.data[1][1]*b.data[1][0])%big;
	res.data[1][1]=(a.data[1][0]*b.data[0][1]+a.data[1][1]*b.data[1][1])%big;
	return res;
}
mat div(mat a,long long n){ //n이 매우 크므로 n이 1이 될때까지 나눔
	if(n>1){
		a=div(a,n/2); 	// 나누고 (분할)
		a=mul(a,a);		// 다시 곱해서 (정복)
		if(n%2==1){		// 홀수인 경우에는 기본 행렬을 곱해준다 ex) 125 -> (64)+(64) + 1
			mat org;
			org.data[0][0]=1; org.data[0][1]=1;
			org.data[1][0]=1; org.data[1][1]=0;
			a=mul(a,org);
		}
	}
	return a; //결과를 리턴
}
long long fib(long long n){
	mat res;
	res.data[0][0]=1; res.data[0][1]=1;
	res.data[1][0]=1; res.data[1][1]=0;
	res=div(res,n);
	return res.data[0][1];
}
int main() {
	long long n;
	cin>>n;
	if(n==0)
		cout<<0<<endl;
	else
		cout<<fib(n)<<endl;
	return 0;
}
