#include <iostream>
#include <vector>
using namespace std;
vector<int>tree[26];
void preorder(int cur){
	if(cur=='.'-65){
		return;
	}
	else{
		cout<<(char)(cur+65);
		preorder(tree[cur][0]);
		preorder(tree[cur][1]);
	}
}
void inorder(int cur){
	if(cur=='.'-65){
		return;
	}
	else{
		inorder(tree[cur][0]);
		cout<<(char)(cur+65);
		inorder(tree[cur][1]);
	}
}
void postorder(int cur){
	if(cur=='.'-65){
		return;
	}
	else{
		postorder(tree[cur][0]);
		postorder(tree[cur][1]);
		cout<<(char)(cur+65);
	}
}
int main() {
	int max;
	cin>>max;
	for(int i=0;i<max;i++){
		char self,lc,rc;
		cin>>self>>lc>>rc;
		tree[self-65].push_back(lc-65);
		tree[self-65].push_back(rc-65);
	}
	preorder(0);cout<<endl;
	inorder(0);cout<<endl;
	postorder(0);cout<<endl;
}
