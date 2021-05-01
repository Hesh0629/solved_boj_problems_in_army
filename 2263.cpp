//2021.5.1 일-말, 중위순회와 후위순회가 주어졌을때 전위순회 구하기. 사실 중위순회와 나머지 둘중하나만 주어지면 트리 모양은 확정이 된다.

#include <iostream>
#include <vector>
using namespace std;
vector<int>inorder;
vector<int>postorder;
vector<int>inorder_index(100000,-1);
void preorder(int in_start,int in_end,int post_start,int post_end){
	if(in_start>in_end||post_start>post_end)
		return;
	int cur_root=postorder[post_end]; //post_end가 루트임.
	cout<<cur_root<<" ";
	preorder(in_start,inorder_index[cur_root]-1,post_start,post_start+(inorder_index[cur_root]-in_start)-1); //inorder 에서 루트기준 왼쪽, postorder 범위는 [post_start,post_start+inorder에서 루트 왼쪽 길이-1]
	preorder(inorder_index[cur_root]+1,in_end,post_start+(inorder_index[cur_root]-in_start),post_end-1); //inorder 에서 루트기준 오른쪽,, postorder 범위는 [post_start+루트 왼쪽길이(결과적으로 오른쪽 부분 시작점),post_end-1]
}
int main() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
	  int data;
	  cin>>data;
	  inorder.push_back(data);
  }
    for(int i=0;i<n;i++){
	  int data;
	  cin>>data;
	  postorder.push_back(data);
  }
  for(int i=0;i<n;i++){
	  inorder_index[inorder[i]]=i; // 노드들의 inorder 순서 인덱스 저장
  }
  preorder(0,n-1,0,n-1);
}
