#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char map[6562][6562]={0};
void rec2(int x,int y,int n){ // for print blank
	for(int i=x;i<x+n;i++){
		for(int j=y;j<y+n;j++) map[i][j]=' ';
	}
}
void rec(int x,int y,int n){
	if(n==1) map[x][y]='*';
	else{
	int next=n/3;
	//cout<<"checkpoint "<<x<<" "<<y<<" "<<n<<endl;
	rec(x,y,next);
	rec(x,y+next,next);
	rec(x,y+next*2,next);
	rec(x+next,y,next);
	rec2(x+next,y+next,next);
	rec(x+next,y+next*2,next);
	rec(x+next*2,y,next);
	rec(x+next*2,y+next,next);
	rec(x+next*2,y+next*2,next);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	rec(0,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			cout<<map[i][j];
		}
		cout<<endl;
	}
}
