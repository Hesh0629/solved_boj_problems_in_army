//가장 긴 증가하는 부분수열 3과 비슷하지만 구하는 과정에서 lower_bound 또는 그냥 넣은 값의 인덱스를 역추적하는 과정 필요

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<int>input;
  for(int i=0;i<n;i++){
      int temp;
      cin>>temp;
      input.push_back(temp);
  }
  deque<int>index; //인덱스 추적
  deque<int>temp_ans; //기존 방식처럼 넣을 예정이긴함
  temp_ans.push_back(input[0]);
  index.push_back(0);
  for(int i=1;i<n;i++){
    if(temp_ans.back()<input[i]){ //현재 값이 temp_ans의 마지막값보다 크다면 맞는 위치니까 바로 push
        temp_ans.push_back(input[i]);
        index.push_back(temp_ans.size()-1); //넣어준 인덱스 위치 기억
    }
    else{ //lower_bound 를 통하여 맞는 위치 찾아주고 temp_ans 수정
        auto srch = lower_bound(temp_ans.begin(),temp_ans.end(),input[i]);
        index.push_back(srch-temp_ans.begin()); //이때 넣어준 인덱스 값 기억 (input과 매칭되도록)
        *srch=input[i];
    }
  }
  deque<int>ans;
  int cur=temp_ans.size()-1;
  for(int i=index.size()-1;i>=0&&cur>=0;i--){ //인덱스를 역추적 하면서 인덱스를 큰것부터 작은거 순으로 나열해주면 끝! (push_front 사용)
      if(index[i]==cur){
          ans.push_front(input[i]);
          cur--;
      }
  }
  cout<<ans.size()<<endl;
  for(auto i:ans){
      cout<<i<<" ";
  }
}
