//교차하는 선분을 판별하는 방법
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cross(pair<long long int,long long int> v1,pair<long long int,long long int> v2){
	long long int ans=v1.first*v2.second-v1.second*v2.first;
	if(ans>0) return 1;
	else if(ans==0) return 0;
	else return -1;
}
int main() {
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	pair<int,int>input1={x1,y1},input2={x2,y2},input3={x3,y3},input4={x4,y4};
	pair<int,int>v1,v2,v3,v4;
	v1={x3-x1,y3-y1};
	v2={x4-x1,y4-y1};
	v3={x1-x3,y1-y3};
	v4={x2-x3,y2-y3};
  // 자기 자신을 기준으로 상대 벡터의 양 끝점이 각각 반대편에 있다면 외적의 곱은 마이너스가 나온다.
  // 이를 이용하여 문제 풀이 가능. 예전에 operator를 써서 푼 적이 있긴한데 생각해보니 pair를 쓰면 해결 된다.
	int a=cross({x2-x1,y2-y1},v1),b=cross({x2-x1,y2-y1},v2),c=cross({x4-x3,y4-y3},v3),d=cross({x4-x3,y4-y3},v4);
	if(a*b==0 && c*d==0){ // 두 선분이 평행선 상에 위치하는 경우이다.
		if(input2<input1) swap(input1,input2);
		if(input4<input3) swap(input4,input3);
		if(input2<input3||input4<input1) cout<<0<<endl; //두 선분의 점들을 정렬해주고, 겹치는지, 한점에서 만나는지, 아니면 아예 접하지 않는지 판별.
		else cout<<1<<endl; 
	}
	else if(a*b<=0&&c*d<=0) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}
