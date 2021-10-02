// DP식은 쉬운데 메모리 제한이 4MB 이어서 int array[3][3]으로 해결한 문제
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  	int n,a,b,c;
  	cin>>n;
  	if(n==1){
	  	cin>>a>>b>>c;
		cout<<max(a,max(b,c))<<" "<<min(a,min(b,c))<<endl;
	}
	else if(n==2){
		int arr[2][3];
		for(int i=0;i<1;i++)
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
		int min_ans[3],max_ans[3];
		min_ans[0]=min(arr[0][0],arr[0][1])+arr[1][0];
		min_ans[1]=min(arr[0][0],min(arr[0][1],arr[0][2]))+arr[1][1];
		min_ans[2]=min(arr[0][1],arr[0][2])+arr[1][2];
		max_ans[0]=max(arr[0][0],arr[0][1])+arr[1][0];
		max_ans[1]=max(arr[0][0],min(arr[0][1],arr[0][2]))+arr[1][1];
		max_ans[2]=max(arr[0][1],arr[0][2])+arr[1][2];
		cout<<max(max_ans[0],max(max_ans[1],max_ans[2]))<<" "<<min(min_ans[0],min(min_ans[1],min_ans[2]))<<endl;
	}
	else{
		int input[3][3]={0},min_ans[3][3]={0},max_ans[3][3]={0};
		for(int i=0;i<n;i++){
			if(i==0){
				cin>>input[2][0]>>input[2][1]>>input[2][2];
				for(int j=0;j<3;j++){
					min_ans[2][j]=input[2][j];
					max_ans[2][j]=input[2][j];
				}
			}
			else{
				for(int j=0;j<3;j++){
					input[0][j]=input[1][j];
					input[1][j]=input[2][j];
					min_ans[0][j]=min_ans[1][j];
					min_ans[1][j]=min_ans[2][j];
					max_ans[0][j]=max_ans[1][j];
					max_ans[1][j]=max_ans[2][j];
				}
				cin>>input[2][0]>>input[2][1]>>input[2][2];
				min_ans[2][0]=min(min_ans[1][0],min_ans[1][1])+input[2][0];
				min_ans[2][1]=min(min_ans[1][0],min(min_ans[1][1],min_ans[1][2]))+input[2][1];
				min_ans[2][2]=min(min_ans[1][1],min_ans[1][2])+input[2][2];
				max_ans[2][0]=max(max_ans[1][0],max_ans[1][1])+input[2][0];
				max_ans[2][1]=max(max_ans[1][0],max(max_ans[1][1],max_ans[1][2]))+input[2][1];
				max_ans[2][2]=max(max_ans[1][1],max_ans[1][2])+input[2][2];
			}
		}
		cout<<max(max_ans[2][0],max(max_ans[2][1],max_ans[2][2]))<<" "<<min(min_ans[2][0],min(min_ans[2][1],min_ans[2][2]))<<endl;
	}
}
