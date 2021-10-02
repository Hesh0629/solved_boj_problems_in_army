#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct mat{
	long long int data[5][5]={0};
};
mat orig;
long long int n,m; //n*n크기의 행렬을 m제곱
mat mul(mat a,mat b){
	mat res;
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++){
			for(long long int k=0;k<n;k++)
				res.data[i][j]+=(a.data[i][k]*b.data[k][j])%1000;
		}
	}
	return res;
}
mat div(mat para,long long int m){
	if(m>1){
		para=div(para,m/2);
		para=mul(para,para);
		if(m%2==1){
			para=mul(para,orig);
		}
	}
	return para;
}
int main() {
	cin>>n>>m;
  	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++)
			cin>>orig.data[i][j];  
	}
	mat res=div(orig,m);
	for(long long int i=0;i<n;i++){
		for(long long int j=0;j<n;j++)
			cout<<res.data[i][j]%1000<<" "; //나머지~ 출력을 왜 안햇을까~
		cout<<'\n';
	}
}
