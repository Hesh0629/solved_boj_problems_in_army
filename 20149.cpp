#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cross(pair<long double,long double> v1,pair<long double,long double> v2){
	long double ans=v1.first*v2.second-v1.second*v2.first;
	if(ans>0) return 1;
	else if(ans==0) return 0;
	else return -1;
}
int main() {
	cout.precision(15);
	long double x1,y1,x2,y2,x3,y3,x4,y4,ans;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	pair<long double,long double>input1={x1,y1},input2={x2,y2},input3={x3,y3},input4={x4,y4};
	if(input2<input1) swap(input1,input2);
	if(input4<input3) swap(input4,input3);
	x1=input1.first; 
	x2=input2.first;
	x3=input3.first;
	x4=input4.first;
	y1=input1.second; 
	y2=input2.second; 
	y3=input3.second; 
	y4=input4.second; 
	pair<long double,long double>v1,v2,v3,v4;
	v1={x3-x1,y3-y1};
	v2={x4-x1,y4-y1};
	v3={x1-x3,y1-y3};
	v4={x2-x3,y2-y3};
	long double a=cross({x2-x1,y2-y1},v1),b=cross({x2-x1,y2-y1},v2),c=cross({x4-x3,y4-y3},v3),d=cross({x4-x3,y4-y3},v4);
	/*주의 : 일직선상에 놓이면 a*b==0 && c*d==0이지만 역은 성립 안한다. 이걸 놓쳤다.*/
	if(a*b==0 && c*d==0){
		if(input2<input3||input4<input1) cout<<0<<endl;
		else {
			cout<<1<<endl;
			if(a==0&&b==0&&c==0&&d==0){ //일직선상에 위치할 때 (정렬끝)
				if(input1==input3||input2==input4) ans=2;  //시작점끼리 같거나 끝점끼리 같은경우
				else if(input1<input3&&input4<input2) ans=2;
				else if(input3<input1&&input2<input4) ans=2;
				else ans=1;
			}
			else ans=1;
		}
	}
	else if(a*b<=0&&c*d<=0) {
		cout<<1<<endl;
		ans=1;
	}
	else cout<<0<<endl;
	if(ans==1){
		if(input1==input3) cout<<input1.first<<" "<<input1.second<<endl;
		else if(input1==input4) cout<<input1.first<<" "<<input1.second<<endl;
		else if(input2==input3) cout<<input2.first<<" "<<input2.second<<endl;
		else if(input2==input4) cout<<input2.first<<" "<<input2.second<<endl;
		else{
			if(x2==x1){
				long double deg=(long double)(y4-y3)/(long double)(x4-x3);
				long double b=y3-deg*x3;
				long double ans_x=x1, ans_y=deg*ans_x+b;
				cout<<fixed<<ans_x<<" "<<fixed<<ans_y<<endl;
			}
			else if(x4==x3){
				long double deg=(long double)(y2-y1)/(long double)(x2-x1);
				long double b=y2-deg*x2;
				long double ans_x=x3, ans_y=deg*ans_x+b;
				cout<<fixed<<ans_x<<" "<<fixed<<ans_y<<endl;
			}
			else{
				long double deg1=(long double)(y2-y1)/(long double)(x2-x1),deg2=(long double)(y4-y3)/(long double)(x4-x3);
				long double b1=y1-deg1*x1,b2=y3-deg2*x3;
				long double ans_x=(long double)(b2-b1)/(deg1-deg2), ans_y=deg1*ans_x+b1;
				cout<<fixed<<ans_x<<" "<<fixed<<ans_y<<endl;
			}
		}
	}
	return 0;
}
